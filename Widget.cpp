#include "Widget.h"
#include "ui_Widget.h"
#include <QProcess>
#include <QDebug>
#include <QButtonGroup>
#include <QKeyEvent>
#include <QApplication>
#include <QClipboard>
#include <QDateTime>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->installEventFilter(this);
    ui->txtName->installEventFilter(this);
    ui->txtResult->installEventFilter(this);
    ui->isMStart->installEventFilter(this);
    ui->isTitleCase->installEventFilter(this);
    m_atom = GlobalAddAtomA("testAtom");
    RegisterHotKey((HWND)this->winId(), m_atom, 0, VK_F3);
    CreatTrayIcon();
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
}

Widget::~Widget()
{
    UnregisterHotKey((HWND)this->winId(), m_atom);
    GlobalDeleteAtom( m_atom );
    delete ui;
}

void Widget::CreatTrayIcon()
{
    CreatTrayMenu();

    if (!QSystemTrayIcon::isSystemTrayAvailable())      //判断系统是否支持系统托盘图标
    {
        return;
    }

    myTrayIcon = new QSystemTrayIcon(this);
    myTrayIcon->setIcon(QIcon(":/fyWidget.ico"));   //设置图标图片
    setWindowIcon(QIcon(":/fyWidget.ico"));  //把图片设置到窗口上\
    myTrayIcon->setToolTip("fyWidget V1.0");    //托盘时，鼠标放上去的提示信息
    myTrayIcon->setContextMenu(myMenu);     //设置托盘上下文菜单
    myTrayIcon->show();
    this->connect(myTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

void Widget::CreatTrayMenu()
{
    miniSizeAction = new QAction("Minimize(&N)",this);
    maxSizeAction = new QAction("Maximize(&X)",this);
    restoreWinAction = new QAction("Reduction(&R)",this);
    quitAction = new QAction("Exit(&Q)",this);

    this->connect(miniSizeAction,SIGNAL(triggered()),this,SLOT(hide()));
    this->connect(maxSizeAction,SIGNAL(triggered()),this,SLOT(showMaximized()));
    this->connect(restoreWinAction,SIGNAL(triggered()),this,SLOT(showNormal()));
    this->connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));
    qApp->installNativeEventFilter(this);

    myMenu = new QMenu((QWidget*)QApplication::desktop());

    myMenu->addAction(miniSizeAction);
    myMenu->addAction(maxSizeAction);
    myMenu->addAction(restoreWinAction);
    myMenu->addSeparator();     //加入一个分离符
    myMenu->addAction(quitAction);
}

void Widget::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        showNormal();
        break;
    default:
        break;
    }
}

void Widget::closeEvent(QCloseEvent *event)
{
    if (myTrayIcon->isVisible())
    {
        hide();     //最小化
        event->ignore();
    }
    else
        event->accept();
}


void Widget::on_txtName_returnPressed()
{
    QProcess process;
    QString cmd = R"(node C:\Users\20582\AppData\Roaming\npm\\node_modules\@wll8\fy\fy.js )" + ui->txtName->text();
    process.start(cmd);
    process.waitForStarted();
    process.waitForFinished();
    QString result = process.readAllStandardOutput().replace('\n', "");
    if(result.length() > 0)
    {
        if(ui->isTitleCase->isChecked())
        {
            result = result[0].toUpper() + result.mid(1);
        }
        if(ui->isMStart->isChecked())
        {
            result = "m_" + result;
        }
    }
    ui->txtResult->setText(result);
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent* ev = dynamic_cast<QKeyEvent*>(event);
        if(ev)
        {
            if((ev->modifiers() == Qt::ControlModifier) && (ev->key() == Qt::Key_C))
            {
                QClipboard * cb = QApplication::clipboard();
                cb->setText(ui->txtResult->text());
            }
        }
    }
    return QWidget::eventFilter(watched, event);
}

bool Widget::nativeEventFilter(const QByteArray &eventType, void *message, long *result)
{
    if(eventType == "windows_generic_MSG")
       {
           MSG* pMsg = reinterpret_cast<MSG*>(message);
           if(pMsg->message == WM_HOTKEY)
           {
               if(pMsg->wParam == m_atom)
               {
                   static long t = 0;
                   long current = QDateTime::currentMSecsSinceEpoch();
                   if(current - t < 200)
                       return QWidget::nativeEvent(eventType,message,result);
                   t = current;
                   if(this->isVisible() == false)
                   {
                       this->showNormal();
                       ui->txtName->setFocus();
                   }
                   else
                   {
                       ui->txtName->setText("");
                       ui->txtResult->setText("");
                       this->hide();
                   }
               }
           }
       }
       return QWidget::nativeEvent(eventType,message,result);
}

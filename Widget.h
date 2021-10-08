#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QAbstractNativeEventFilter>
#include <Windows.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget, public QAbstractNativeEventFilter
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void CreatTrayIcon();
    void CreatTrayMenu();

private slots:
    void on_txtName_returnPressed();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    bool nativeEventFilter(const QByteArray &eventType, void *message, long *result);
private:
    Ui::Widget *ui;
    QSystemTrayIcon* myTrayIcon;
    QMenu* myMenu;
    QAction* miniSizeAction;
    QAction* maxSizeAction;
    QAction* restoreWinAction;
    QAction* quitAction;
    ATOM m_atom;
    void closeEvent(QCloseEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);


};
#endif // WIDGET_H

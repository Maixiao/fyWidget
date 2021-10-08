/********************************************************************************
** Form generated from reading UI file 'Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txtName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *txtResult;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *isTitleCase;
    QCheckBox *isMStart;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(347, 98);
        Widget->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/fyWidget.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        txtName = new QLineEdit(Widget);
        txtName->setObjectName(QString::fromUtf8("txtName"));

        horizontalLayout->addWidget(txtName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        txtResult = new QLineEdit(Widget);
        txtResult->setObjectName(QString::fromUtf8("txtResult"));
        txtResult->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_2->addWidget(txtResult);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        isTitleCase = new QCheckBox(Widget);
        isTitleCase->setObjectName(QString::fromUtf8("isTitleCase"));
        isTitleCase->setFocusPolicy(Qt::NoFocus);
        isTitleCase->setChecked(true);

        horizontalLayout_3->addWidget(isTitleCase);

        isMStart = new QCheckBox(Widget);
        isMStart->setObjectName(QString::fromUtf8("isMStart"));
        isMStart->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(isMStart);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\217\230\351\207\217", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\277\273\350\257\221", nullptr));
        isTitleCase->setText(QCoreApplication::translate("Widget", "\351\246\226\345\255\227\346\257\215\345\244\247\345\206\231", nullptr));
        isMStart->setText(QCoreApplication::translate("Widget", "m\345\274\200\345\244\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

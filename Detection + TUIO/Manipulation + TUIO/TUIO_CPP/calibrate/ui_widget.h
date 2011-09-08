/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue Mar 29 23:58:08 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *snap;
    QLCDNumber *lcdx1;
    QLCDNumber *lcdy1;
    QLCDNumber *lcdy2;
    QLCDNumber *lcdx2;
    QLCDNumber *lcdy3;
    QLCDNumber *lcdx3;
    QLCDNumber *lcdy4;
    QLCDNumber *lcdx4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(301, 243);
        snap = new QPushButton(Widget);
        snap->setObjectName(QString::fromUtf8("snap"));
        snap->setGeometry(QRect(10, 10, 281, 71));
        lcdx1 = new QLCDNumber(Widget);
        lcdx1->setObjectName(QString::fromUtf8("lcdx1"));
        lcdx1->setGeometry(QRect(10, 90, 131, 23));
        lcdx1->setNumDigits(10);
        lcdy1 = new QLCDNumber(Widget);
        lcdy1->setObjectName(QString::fromUtf8("lcdy1"));
        lcdy1->setGeometry(QRect(160, 90, 131, 23));
        lcdy1->setNumDigits(10);
        lcdy2 = new QLCDNumber(Widget);
        lcdy2->setObjectName(QString::fromUtf8("lcdy2"));
        lcdy2->setGeometry(QRect(160, 130, 131, 23));
        lcdy2->setNumDigits(10);
        lcdx2 = new QLCDNumber(Widget);
        lcdx2->setObjectName(QString::fromUtf8("lcdx2"));
        lcdx2->setGeometry(QRect(10, 130, 131, 23));
        lcdx2->setNumDigits(10);
        lcdy3 = new QLCDNumber(Widget);
        lcdy3->setObjectName(QString::fromUtf8("lcdy3"));
        lcdy3->setGeometry(QRect(160, 170, 131, 23));
        lcdy3->setNumDigits(10);
        lcdx3 = new QLCDNumber(Widget);
        lcdx3->setObjectName(QString::fromUtf8("lcdx3"));
        lcdx3->setGeometry(QRect(10, 170, 131, 23));
        lcdx3->setNumDigits(10);
        lcdy4 = new QLCDNumber(Widget);
        lcdy4->setObjectName(QString::fromUtf8("lcdy4"));
        lcdy4->setGeometry(QRect(160, 210, 131, 23));
        lcdy4->setNumDigits(10);
        lcdx4 = new QLCDNumber(Widget);
        lcdx4->setObjectName(QString::fromUtf8("lcdx4"));
        lcdx4->setGeometry(QRect(10, 210, 131, 23));
        lcdx4->setNumDigits(10);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        snap->setText(QApplication::translate("Widget", "PRESS ME TO SNAP!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

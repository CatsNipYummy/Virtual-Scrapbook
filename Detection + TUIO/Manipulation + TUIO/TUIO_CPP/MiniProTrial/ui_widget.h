/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Mon Apr 4 15:24:07 2011
**      by: Qt User Interface Compiler version 4.6.2
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
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *click;
    QTextBrowser *textBrowser;
    QLCDNumber *lcdx;
    QLCDNumber *lcdy;
    QLCDNumber *lcdy_2;
    QLCDNumber *lcdx_2;
    QLCDNumber *lcdy_3;
    QLCDNumber *lcdx_3;
    QLCDNumber *lcdy_4;
    QLCDNumber *lcdx_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(389, 344);
        click = new QPushButton(Widget);
        click->setObjectName(QString::fromUtf8("click"));
        click->setGeometry(QRect(10, 130, 371, 81));
        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 371, 111));
        lcdx = new QLCDNumber(Widget);
        lcdx->setObjectName(QString::fromUtf8("lcdx"));
        lcdx->setGeometry(QRect(10, 220, 181, 23));
        lcdx->setDigitCount(10);
        lcdy = new QLCDNumber(Widget);
        lcdy->setObjectName(QString::fromUtf8("lcdy"));
        lcdy->setGeometry(QRect(200, 220, 181, 23));
        lcdy->setDigitCount(10);
        lcdy_2 = new QLCDNumber(Widget);
        lcdy_2->setObjectName(QString::fromUtf8("lcdy_2"));
        lcdy_2->setGeometry(QRect(200, 250, 181, 23));
        lcdy_2->setDigitCount(10);
        lcdx_2 = new QLCDNumber(Widget);
        lcdx_2->setObjectName(QString::fromUtf8("lcdx_2"));
        lcdx_2->setGeometry(QRect(10, 250, 181, 23));
        lcdx_2->setDigitCount(10);
        lcdy_3 = new QLCDNumber(Widget);
        lcdy_3->setObjectName(QString::fromUtf8("lcdy_3"));
        lcdy_3->setGeometry(QRect(200, 280, 181, 23));
        lcdy_3->setDigitCount(10);
        lcdx_3 = new QLCDNumber(Widget);
        lcdx_3->setObjectName(QString::fromUtf8("lcdx_3"));
        lcdx_3->setGeometry(QRect(10, 280, 181, 23));
        lcdx_3->setDigitCount(10);
        lcdy_4 = new QLCDNumber(Widget);
        lcdy_4->setObjectName(QString::fromUtf8("lcdy_4"));
        lcdy_4->setGeometry(QRect(200, 310, 181, 23));
        lcdy_4->setDigitCount(10);
        lcdx_4 = new QLCDNumber(Widget);
        lcdx_4->setObjectName(QString::fromUtf8("lcdx_4"));
        lcdx_4->setGeometry(QRect(10, 310, 181, 23));
        lcdx_4->setDigitCount(10);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        click->setText(QApplication::translate("Widget", "CLICK ME!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

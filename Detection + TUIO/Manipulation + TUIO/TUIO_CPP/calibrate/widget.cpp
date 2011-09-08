#include "widget.h"
#include "ui_widget.h"
#include <cv.h>
#include<cvblob.h>
#include <highgui.h>
#include<math.h>
#include<threadqt.h>
#include <iostream>
#include <iomanip>

using namespace cvb;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    count=0;
    index=0;

   // process();

}

Widget::~Widget()
{
    delete ui;
    thr.terminate();
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void Widget::process()
{

}

void Widget::on_snap_clicked()
{
    if(count<4)
    {

    }
    count++;

}

#ifndef WIDGET_H
#define WIDGET_H
#include <cvblob.h>
#include <cv.h>
#include <highgui.h>
#include <iostream>
#include <iomanip>
#include <QWidget>

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    CvCapture *capture;
    double cord[4][2];
    int count;
    int countflag;
    int blobcount;

protected:
    void changeEvent(QEvent *e);
    void writefile();



private:
    Ui::Widget *ui;

private slots:

public slots:
    void startcv();

private slots:
    void on_click_clicked();
};

#endif // WIDGET_H

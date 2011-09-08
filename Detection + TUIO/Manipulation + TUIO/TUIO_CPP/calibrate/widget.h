#ifndef WIDGET_H
#define WIDGET_H
#include<threadqt.h>
#include <QWidget>

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    int count;
    double cord[4][2];
    double x;
    double y;
    int index;
    MyThread thr;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Widget *ui;

private slots:
    void process();
    void on_snap_clicked();
};

#endif // WIDGET_H

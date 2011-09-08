#ifndef THREADQT_H
#define THREADQT_H
#include<cv.h>
#include<highgui.h>
#include<QThread>
class MyThread : public QThread
 {

 public:

     //CvCapture *capture;
     void run();
 };
#endif // THREADQT_H

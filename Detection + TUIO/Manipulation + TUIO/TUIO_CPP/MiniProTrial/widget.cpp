#include "widget.h"
#include "ui_widget.h"
#include <cvblob.h>
#include <cv.h>
#include <highgui.h>
#include <iostream>
#include <iomanip>
using namespace cvb;
Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget)
{
    ui->setupUi(this);
    count=-1;
    countflag=0;
    ui->textBrowser->append("WELCOME TO CALIBRARTION STAGE\nPress The CLICK ME BUTTON to START CALIBRATION \nMake sure you click the button only when you have the corresponding callibration points on the vedio widget\n");
}

Widget::~Widget()
{
    delete ui;



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



void Widget::startcv()
{
    CvTracks tracks;

    cvNamedWindow("red_object_tracking", CV_WINDOW_AUTOSIZE);
    //cvNamedWindow("segmentated", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("seg", CV_WINDOW_AUTOSIZE);
    capture = cvCaptureFromCAM(1);
    cvGrabFrame(capture);
    IplImage *img = cvRetrieveFrame(capture);

    CvSize imgSize = cvGetSize(img);

    //this is a temp frame for storing image frames for manipulation rather than manipulating the original frame
    IplImage *frame = cvCreateImage(imgSize, img->depth, img->nChannels);

    IplConvKernel* morphKernel = cvCreateStructuringElementEx(5, 5, 1, 1, CV_SHAPE_RECT, NULL);

    //unsigned int frameNumber = 0;
    unsigned int blobNumber = 0;

    bool quit = false;
    while (!quit&&cvGrabFrame(capture))
    {
        IplImage *img = cvRetrieveFrame(capture);

        cvConvertScale(img, frame, 1, 0);

        IplImage *segmentated = cvCreateImage(imgSize, 8, 1);

        // Detecting red pixels:
        // (This is very slow, use direct access better...)
        for (int j=0; j<imgSize.height; j++)
            for (int i=0; i<imgSize.width; i++)
            {
            CvScalar c = cvGet2D(frame, j, i);

            double b = ((double)c.val[0])/255.;
            double g = ((double)c.val[1])/255.;
            double r = ((double)c.val[2])/255.;
            unsigned char f = 255*((r>0.8)&&(g>0.8)&&(b>0.8)&&(r<=1.0)&&(g<=1.0)&&(b<=1.0));
            //unsigned char f = 255*(((r>rl)&&(g>gl)&&(b>bl)&&(r<=ru)&&(g<=gu)&&(b<=bu))&&((((r-g)<0.04)||((g-r)<0.04))&&(((r-b)<0.04)||((b-r)<0.04))&&(((b-g)<0.04)||((g-b)<0.04))));
            // unsigned char f = 255*(((r>rl)&&(g>gl)&&(b>bl)&&(r<=ru)&&(g<=gu)&&(b<=bu)));
            cvSet2D(segmentated, j, i, CV_RGB(f, f, f));
        }
        //cvShowImage("segmentated", segmentated);
        cvMorphologyEx(segmentated, segmentated, NULL, morphKernel, CV_MOP_OPEN, 1);
        cvShowImage("seg", segmentated);
        IplImage *labelImg = cvCreateImage(cvGetSize(frame), IPL_DEPTH_LABEL, 1);
        CvBlobs blobs;
        unsigned int result = cvLabel(segmentated, labelImg, blobs);
        cvFilterByArea(blobs, 10, 100000);
        cvRenderBlobs(labelImg, blobs, frame, frame, CV_BLOB_RENDER_BOUNDING_BOX);
        cvUpdateTracks(blobs, tracks, 200., 5);
        cvRenderTracks(tracks, frame, frame, CV_TRACK_RENDER_ID|CV_TRACK_RENDER_BOUNDING_BOX);

        cvShowImage("red_object_tracking", frame);

        /*std::stringstream filename;
      filename << "redobject_" << std::setw(5) << std::setfill('0') << frameNumber << ".png";
      cvSaveImage(filename.str().c_str(), frame);*/

        cvReleaseImage(&labelImg);
        cvReleaseImage(&segmentated);

        char k = cvWaitKey(10)&0xff;
        switch (k)
        {
        case 27:
        case 'q':
        case 'Q':
            quit = true;
            break;

        }

        blobcount=0;
        for (CvBlobs::const_iterator it=blobs.begin(); it!=blobs.end(); ++it)
        {

            blobcount++;
        }
        for (CvBlobs::const_iterator it=blobs.begin(); it!=blobs.end(); ++it)
        {
            if(blobcount==1)
            {
                switch(count)
                {
                case 0:
                    cord[0][0]=((double)it->second->centroid.x);
                    cord[0][1]=((double)it->second->centroid.y);
                    ui->lcdx->display(cord[0][0]);
                    ui->lcdy->display(cord[0][1]);
                    ui->click->setText("CLICK AGAIN!");
                    ui->textBrowser->append("3 more click left....\nPoint one captured successfully!!!");
                    count=-1;
                    break;
          case 1:
                    cord[1][0]=((double)it->second->centroid.x);
                    cord[1][1]=((double)it->second->centroid.y);
                    ui->lcdx_2->display(cord[1][0]);
                    ui->lcdy_2->display(cord[1][1]);
                    ui->textBrowser->append("2 more click left....\nPoint two captured successfully!!!");
                    count=-1;
                    break;
         case 2:
                    cord[2][0]=((double)it->second->centroid.x);
                    cord[2][1]=((double)it->second->centroid.y);
                    ui->lcdx_3->display(cord[2][0]);
                    ui->lcdy_3->display(cord[2][1]);
                    ui->textBrowser->append("1 more click left....\nPoint three captured successfully!!!");
                    count=-1;
                    break;
         case 3:
                    cord[3][0]=((double)it->second->centroid.x);
                    cord[3][1]=((double)it->second->centroid.y);
                    ui->lcdx_4->display(cord[3][0]);
                    ui->lcdy_4->display(cord[3][1]);
                    ui->textBrowser->append("No more click left....\nPoint one captured successfully!!!");
                    ui->textBrowser->append("Now Writing to file");
                    writefile();
                    ui->click->setDisabled(true);
                    count=-1;
                    break;
         default:
                    break;


                }
            }
        }
        cvReleaseBlobs(blobs);

        //frameNumber++;
    }

    cvReleaseStructuringElement(&morphKernel);
    cvReleaseImage(&frame);


    cvDestroyWindow("red_object_tracking");
    //cvDestroyWindow("segmentated");
    cvDestroyWindow("seg");
}


void Widget::writefile()
{
    FILE *fp;
    fp=fopen("data.txt","w+");
    for(int i=0;i<4;i++)
    {
        fprintf(fp,"%f %f\n",(float)cord[i][0],(float)cord[i][1]);
    }
    fclose(fp);
}

void Widget::on_click_clicked()
{

    switch(countflag)
    {
    case 0:
        count=0;
        break;
    case 1:
        count=1;
        break;
    case 2:
        count=2;
        break;
    case 3:
        count=3;
        break;
    default:
        break;

    }
    countflag++;
}

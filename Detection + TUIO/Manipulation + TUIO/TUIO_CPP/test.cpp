
#include <iostream>
#include <iomanip>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#if (defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__) || (defined(__APPLE__) & defined(__MACH__)))
#include <cv.h>
#include <highgui.h>
#include<math.h>
#else
#include <opencv/cv.h>
#include <opencv/highgui.h>//for windows 
#endif
#include <cvblob.h>// for cvBlob:blob tracking
using namespace cvb;
using namespace cv;
using namespace std;
#include<stdio.h>
#include "SimpleSimulator.h"

SimpleSimulator::SimpleSimulator(const char* host, int port)
{
    tuioServer = new TuioServer();
}
float SimpleSimulator::uvalue(float x,float y)
{
	return (((a*x)+(b*y)+c)/((g*x)+(h*y)+1));
}
float SimpleSimulator::vvalue(float x,float y)
{
	return (((d*x)+(e*y)+f)/((g*x)+(h*y)+1));
}
void SimpleSimulator::run()
{	



    
    FILE *fp;
    fp=fopen("data.txt","r");
    fscanf(fp,"%f %f %f %f %f %f %f %f",&a,&b,&c,&d,&e,&f,&g,&h);
    fclose(fp);
    double ratiox,ratioy;
    
    CvTracks tracks;
    fp=fopen("/home/spykarbro/Desktop/log.txt","w+");
    //cvNamedWindow("FingerTracking", CV_WINDOW_AUTOSIZE);
   // cvNamedWindow("segmentated", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("seg", CV_WINDOW_AUTOSIZE);
    CvCapture *capture = cvCaptureFromCAM(1);
    cvGrabFrame(capture);
    IplImage *img = cvRetrieveFrame(capture);
    
    CvSize imgSize = cvGetSize(img);
    IplImage *frame = cvCreateImage(imgSize, img->depth, img->nChannels);
    IplConvKernel* morphKernel = cvCreateStructuringElementEx(5, 5, 1, 1, CV_SHAPE_RECT, NULL);
    printf("%d %d");
    std::cout<<imgSize.width;
    std::cout<<imgSize.height;
    ratiox=(double)1/imgSize.width;
    ratioy=(double)1/imgSize.height;
    unsigned int blobNumber = 0;
    bool quit = false;
    while (!quit&&cvGrabFrame(capture))
    {
        IplImage *img = cvRetrieveFrame(capture);
        
        cvFlip(img,img,1);
       
        
        cvConvertScale(img, frame, 1, 0);
        IplImage *segmentated = cvCreateImage(imgSize, 8, 1);
        
        for (unsigned int j=0; j<imgSize.height; j++)
            for (unsigned int i=0; i<imgSize.width; i++)
            {
            CvScalar c = cvGet2D(frame, j, i);

            double b = ((double)c.val[0])/255.;
            double g = ((double)c.val[1])/255.;
            double r = ((double)c.val[2])/255.;

            unsigned char f = 255*((r>0.8)&&(g>0.8)&&(b>0.8)&&(r<=1.0)&&(g<=1.0)&&(b<=1.0));
            cvSet2D(segmentated, j, i, CV_RGB(f, f, f));//setting the pixel colour
        }
       // cvShowImage("segmentated", segmentated);
        cvMorphologyEx(segmentated, segmentated, NULL, morphKernel, CV_MOP_OPEN, 1);
        cvShowImage("seg", segmentated);
        IplImage *labelImg = cvCreateImage(cvGetSize(frame), IPL_DEPTH_LABEL, 1);
        CvBlobs blobs;
        unsigned int result = cvLabel(segmentated, labelImg, blobs);
        cvFilterByArea(blobs,10,10000);
        cvRenderBlobs(labelImg, blobs, frame, frame, CV_BLOB_RENDER_BOUNDING_BOX);
        cvUpdateTracks(blobs, tracks, 200., 5);
        cvRenderTracks(tracks, frame, frame, CV_TRACK_RENDER_ID|CV_TRACK_RENDER_BOUNDING_BOX);
        //cvShowImage("FingerTracking", frame);
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

        
        for (CvBlobs::const_iterator it=blobs.begin(); it!=blobs.end(); ++it)
        { 
            running=true;

				xc=(double)uvalue((float)it->second->centroid.x,(float)it->second->centroid.y)*ratiox;
				yc=(double)vvalue((float)it->second->centroid.x,(float)it->second->centroid.y)*ratioy;
			
            //xc=((double)it->second->centroid.x)*ratiox;
            //yc=((double)it->second->centroid.y)*ratioy;
            currentTime = TuioTime::getSessionTime();
            tuioServer->initFrame(currentTime);
            processxy(xc,yc);
            tuioServer->commitFrame();


        }
        cursorclean();
        cvReleaseBlobs(blobs);
    }

    cvReleaseStructuringElement(&morphKernel);
    cvReleaseImage(&frame);

    
    //cvDestroyWindow("FingerTracking");
    //cvDestroyWindow("segmentated");
    cvDestroyWindow("seg");


}
void SimpleSimulator::processxy(double x,double y)
{
    float xt,yt;
    float xo,yo;
    xo=(float)x;
    yo=(float)y;
    float difx,dify;
    TuioCursor *cur;
    cur=NULL;
    bool match=false;
    stickylist = tuioServer->getTuioCursors();
    for (std::list<TuioCursor*>::iterator tuioCursor = stickylist.begin(); tuioCursor!=stickylist.end(); tuioCursor++)
    {
        xt=(*tuioCursor)->getX();
        yt=(*tuioCursor)->getY();
        difx=abs(xo-xt);
        dify=abs(yo-yt);
        if((difx<0.05)&&(dify<0.075))
        {
            match=true;
            cur=(*tuioCursor);
            break;
        }
    }
    if(match==true)
    {
        cursorupdate(cur,x,y);
    }
    else
    {
        cursoradd(x,y);
    }
}

void SimpleSimulator::cursoradd(double x, double y)
{
    tuioServer->addTuioCursor((float)x,(float)y);
}
void SimpleSimulator::cursorupdate(TuioCursor *curse, double x, double y)
{
    tuioServer->updateTuioCursor(curse,(float)x,(float)y);
}
void SimpleSimulator::cursorremove(TuioCursor *curse)
{
    currentTime = TuioTime::getSessionTime();
    tuioServer->initFrame(currentTime);
    tuioServer->removeTuioCursor(curse);
    tuioServer->commitFrame();
}
void SimpleSimulator::cursorclean()
{
    long t1=0,t2=0;
    TuioTime t,c;
    c = TuioTime::getSessionTime();
    t2=c.getTotalMilliseconds();
    stickylist = tuioServer->getTuioCursors();
    for (std::list<TuioCursor*>::iterator tuioCursor = stickylist.begin(); tuioCursor!=stickylist.end(); tuioCursor++)
    {
        t=(*tuioCursor)->getTuioTime();
        t1=t.getTotalMilliseconds();
        if((t2-t1)>500)
        {
            cursorremove((*tuioCursor));
        }
    }

}

int main()
{
    SimpleSimulator *app;
    app = new SimpleSimulator("default",0);
    app->run();
    delete(app);
    return 0;
}



/* sprintf(lab,"%d",(int)floor(it->second->label));
            sprintf(area,"%d",(int)floor(it->second->area));
            sprintf(loc,"%d",(int)floor(it->second->centroid.x*ratiox));
            sprintf(loc2,"%d",(int)floor(it->second->centroid.y*ratioy));*/

/*strcat(bash1,lab);
            strcat(bash1,space);
            strcat(bash1,area);
            strcat(bash1,space);
            strcat(bash1,loc);
            strcat(bash1,space);
            strcat(bash1,loc2);
            strcat(bash1,"\n");
            fputs(bash1,fp);
            strcpy(bash1,"");*/







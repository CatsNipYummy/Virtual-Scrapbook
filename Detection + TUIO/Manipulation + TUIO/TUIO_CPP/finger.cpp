
#include <iostream>
#include <iomanip>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#if (defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__) || (defined(__APPLE__) & defined(__MACH__)))
#include <cv.h>
#include <highgui.h>
#else
#include <opencv/cv.h>
#include <opencv/highgui.h>//for windows 
#endif
#include <cvblob.h>// for cvBlob:blob tracking
using namespace cvb;
#include<stdio.h>
#include "SimpleSimulator.h"

SimpleSimulator::SimpleSimulator(const char* host, int port)
{
    tuioServer = new TuioServer();
}

void SimpleSimulator::run()
{	
    //for wriring the cordinates into the file
    /*char loc[20];
    char loc2[20];
    char lab[20];
    char area[20];
    char space[2]=" ";
    char bash1[300];*/


    //to find the relation btwn the image size and screen size
    double ratiox,ratioy;
    FILE *fp;
    CvTracks tracks;//for storing the details of the tracks
    fp=fopen("/home/spykarbro/Desktop/log.txt","w+");
    cvNamedWindow("FingerTracking", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("segmentated", CV_WINDOW_AUTOSIZE);//for showing the image before morphing
    cvNamedWindow("seg", CV_WINDOW_AUTOSIZE);//for showning the morphed image
    CvCapture *capture = cvCaptureFromCAM(0);//capture Image from the CAM
    cvGrabFrame(capture);
    IplImage *img = cvRetrieveFrame(capture);
    CvSize imgSize = cvGetSize(img);
    IplImage *frame = cvCreateImage(imgSize, img->depth, img->nChannels);
    IplConvKernel* morphKernel = cvCreateStructuringElementEx(5, 5, 1, 1, CV_SHAPE_RECT, NULL);//creates a structuring element
    ratiox=1400/imgSize.width;//find out the ratio for relating the image width with screen resolution width
    ratioy=900/imgSize.height;//find out the ratio for relating the image height with screen resolution height
    unsigned int blobNumber = 0;
    bool quit = false;
    while (!quit&&cvGrabFrame(capture))
    {
        IplImage *img = cvRetrieveFrame(capture);
        cvConvertScale(img, frame, 1, 0);//converting the FRAME in img to frame with a single scaling
        IplImage *segmentated = cvCreateImage(imgSize, 8, 1);
        //This part gets each pixels RGB values and assigns it into the cvScalar object which is a 4 double value storage.and checks if the RGB of that pixel is within the range specified and if so paints its while or else blacked out
        for (unsigned int j=0; j<imgSize.height; j++)
            for (unsigned int i=0; i<imgSize.width; i++)
            {
            CvScalar c = cvGet2D(frame, j, i);

            double b = ((double)c.val[0])/255.;
            double g = ((double)c.val[1])/255.;
            double r = ((double)c.val[2])/255.;
            unsigned char f = 255*(((r>0.60)&&(g>0.60)&&(b>0.60)&&(r<=1.0)&&(g<=1.0)&&(b<=1.0))&&((((r-g)<0.04)||((g-r)<0.04))&&(((r-b)<0.04)||((b-r)<0.04))&&(((b-g)<0.04)||((g-b)<0.04))));//comparison:defining the colour ranges
            cvSet2D(segmentated, j, i, CV_RGB(f, f, f));//setting the pixel colour
        }
       // cvShowImage("segmentated", segmentated);//displays the unmorphed image
        cvMorphologyEx(segmentated, segmentated, NULL, morphKernel, CV_MOP_OPEN, 1);//morphing phase.using the structured element defined by cvCreateStructuringElement()
        cvShowImage("seg", segmentated);//displays the morphed image
        IplImage *labelImg = cvCreateImage(cvGetSize(frame), IPL_DEPTH_LABEL, 1);//creating a labelling image which is then superimposed on to the main frame
        //////////////////////////////////////////////////////////////////////////
        CvBlobs blobs;//a data type for storing the Blobs in the image
        unsigned int result = cvLabel(segmentated, labelImg, blobs);//labels the connected parts of the image
        cvFilterByArea(blobs,500,25000);//filters the image for the blobs in the specified range 
        cvRenderBlobs(labelImg, blobs, frame, frame, CV_BLOB_RENDER_BOUNDING_BOX);//marks the blobs on the image label by drawing a rectangular block around each of the recognized blobs
        cvUpdateTracks(blobs, tracks, 200., 5);//Tracks the Blobs and record that info into the tracks variable of cvTrack
        cvRenderTracks(tracks, frame, frame, CV_TRACK_RENDER_ID|CV_TRACK_RENDER_BOUNDING_BOX);//draws a blue box around the tracked blob
        //cvShowImage("FingerTracking", frame);//shows the final imgae with blobs and tracks
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
        // this part of the code is for storing the cordinate details into the log.txt file 
        
        for (CvBlobs::const_iterator it=blobs.begin(); it!=blobs.end(); ++it)
        {
            
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
            running=true;
            currentTime = TuioTime::getSessionTime();
            tuioServer->initFrame(currentTime);

            cursor = tuioServer->addTuioCursor(0.2,0.2);
            tuioServer->commitFrame();
            currentTime = TuioTime::getSessionTime();
            tuioServer->initFrame(currentTime);
            tuioServer->updateTuioCursor(cursor,(float)floor(it->second->centroid.x*ratiox),(float)floor(it->second->centroid.y*ratioy));
            tuioServer->commitFrame();
            currentTime = TuioTime::getSessionTime();
            tuioServer->initFrame(currentTime);
            tuioServer->removeTuioCursor(cursor);
            tuioServer->commitFrame();



        }
        cvReleaseBlobs(blobs);
    }

    cvReleaseStructuringElement(&morphKernel);
    cvReleaseImage(&frame);

    fclose(fp);
    cvDestroyWindow("FingerTracking");
    cvDestroyWindow("segmentated");
    cvDestroyWindow("seg");


}

int main()
{
    SimpleSimulator *app;
    app = new SimpleSimulator("default",0);
    app->run();
    delete(app);
    return 0;
}











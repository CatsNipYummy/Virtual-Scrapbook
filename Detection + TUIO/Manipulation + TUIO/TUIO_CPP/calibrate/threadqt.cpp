
#include<threadqt.h>
#include<cv.h>
#include<highgui.h>
#include<stdio.h>
#include<cvblob.h>
#include <iostream>
#include <iomanip>
using namespace cvb;
void MyThread::run()
{
    CvTracks tracks;

    cvNamedWindow("red_object_tracking", CV_WINDOW_AUTOSIZE);
    //cvNamedWindow("segmentated", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("seg", CV_WINDOW_AUTOSIZE);
    CvCapture *capture = cvCaptureFromCAM(1);
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
          unsigned char f = 255*((r>0.2+g)&&(r>0.2+b));
          //unsigned char f = 255*(((r>rl)&&(g>gl)&&(b>bl)&&(r<=ru)&&(g<=gu)&&(b<=bu))&&((((r-g)<0.04)||((g-r)<0.04))&&(((r-b)<0.04)||((b-r)<0.04))&&(((b-g)<0.04)||((g-b)<0.04))));
          //unsigned char f = 255*(((r>rl)&&(g>gl)&&(b>bl)&&(r<=ru)&&(g<=gu)&&(b<=bu)));
          cvSet2D(segmentated, j, i, CV_RGB(f, f, f));
        }
      //cvShowImage("segmentated", segmentated);
      cvMorphologyEx(segmentated, segmentated, NULL, morphKernel, CV_MOP_OPEN, 1);
  cvShowImage("seg", segmentated);


      IplImage *labelImg = cvCreateImage(cvGetSize(frame), IPL_DEPTH_LABEL, 1);

      CvBlobs blobs;
      //unsigned int result = cvLabel(segmentated, labelImg, blobs);
      cvFilterByArea(blobs, 100, 10000);
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
        case 's':
        case 'S':
          for (CvBlobs::const_iterator it=blobs.begin(); it!=blobs.end(); ++it)
          {
            std::stringstream filename;
            filename << "redobject_blob_" << std::setw(5) << std::setfill('0') << blobNumber << ".png";
            cvSaveImageBlob(filename.str().c_str(), img, it->second);
            blobNumber++;

            std::cout << filename.str() << " saved!" << std::endl;
          }
          break;
      }

      cvReleaseBlobs(blobs);

      //frameNumber++;
    }

    cvReleaseStructuringElement(&morphKernel);
    cvReleaseImage(&frame);


    cvDestroyWindow("red_object_tracking");
    //cvDestroyWindow("segmentated");
     // cvDestroyWindow("seg");
}

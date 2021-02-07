#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Header_Files/ReadMedia.h"
using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////

void showImage(string path) {

    Mat img = imread(path);
    imshow("Image", img);
    waitKey(0);

}

/////////////////  Video  //////////////////////

void showVideo(string path) {

    VideoCapture cap(path);
    Mat img;
    
    while (true) {
        cap.read(img);
        if (img.empty())
        {
            cout << "Could not open or find the image!\n" << endl;
            break;
        }
        imshow("Image", img);
        waitKey(20);
    }

}

/////////////////  WebCam  //////////////////////

void showWebcam() {

    VideoCapture cap(0);
    Mat img;

    while (true) {
        cap.read(img);
        imshow("Image", img);
        waitKey(20);
    }

}
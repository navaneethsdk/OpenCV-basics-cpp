#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Header_Files/colorDetection.h"
using namespace cv;
using namespace std;


/////////////////  Color Detection  //////////////////////
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

void detectColor(string path) {
    
    Mat img = imread(path);
    Mat imgHSV, mask;
    cvtColor(img, imgHSV, COLOR_BGR2HSV); // change to HSV for easiness of color detection

    namedWindow("Tracksbar",(640, 200));
    createTrackbar("Hue Min", "Tracksbar", &hmin, 179);
    createTrackbar("Hue Max", "Tracksbar", &hmax, 179);
    createTrackbar("Sat Min", "Tracksbar", &smin, 255);
    createTrackbar("Sat Max", "Tracksbar", &smax, 255);
    createTrackbar("Val Min", "Tracksbar", &vmin, 255);
    createTrackbar("Val Max", "Tracksbar", &vmax, 255);

    while (true) {
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(imgHSV, lower, upper, mask);

        imshow("Image", img);
        imshow("Image HSV", imgHSV);
        imshow("Image mask", mask);
        waitKey(1);
    }
    

}
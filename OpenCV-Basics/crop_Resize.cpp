#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Header_Files/cropResize.h"
using namespace cv;
using namespace std;


void resizeImg(string path) {

    Mat img = imread(path);
    Mat imgResized;
    // resize(img, imgResized, Size(640, 480));
    resize(img, imgResized, Size(), 0.5, 0.5);
    imshow("Image", img);
    imshow("Image Resized", imgResized);
    waitKey(0);

}

void cropImg(string path) {

    Mat img = imread(path);
    Mat imgCrop;
    Rect ROI(200, 100, 300, 300);
    Rect roi();
    imgCrop = img(ROI);
    imshow("Image", img);
    imshow("Image Cropped", imgCrop);
    waitKey(0);

}




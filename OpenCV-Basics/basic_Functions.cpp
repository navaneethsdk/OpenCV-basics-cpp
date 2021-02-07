#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Header_Files/basicFunctions.h"
using namespace cv;
using namespace std;


void BGRtoGRAY(string path) {

    Mat img = imread(path);
    Mat imgGray;
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    imshow("Image", img);
    imshow("Image Gray", imgGray);
    waitKey(0);

}

void imageBlur(string path) {

    Mat img = imread(path);
    Mat imgBlur;
    GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);
    imshow("Image", img);
    imshow("Image Gray", imgBlur);
    waitKey(0);

}

void edgeDetector(string path) {

    Mat img = imread(path);
    Mat imgBlur, imgCanny;
    // for dilating and eroding (increasing and decreasing thickness of edges resp.)
    Mat imgDila, imgErod;
    // Blur before feeding it to Canny Edge Detector
    GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);
    Canny(imgBlur,imgCanny,25,75);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDila, kernel);
    erode(imgDila, imgErod, kernel);

    // imshow("Image", img);
    imshow("Image Canny", imgCanny);
    imshow("Image Dilation", imgDila);
    imshow("Image Erosion", imgErod);
    waitKey(0);

}

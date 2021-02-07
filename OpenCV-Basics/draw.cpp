#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Header_Files/draw.h"
using namespace cv;
using namespace std;


void generateBlankImg() {
    // Blank image
    Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255)); //8uc3 - 8 bits (0 to 255), unsigned, 3 channels
    // circle(img, Point(256, 256), 155, Scalar(0, 69, 255), 10);
    circle(img, Point(256,256), 155, Scalar(0, 69, 255), FILLED);
    rectangle(img, Point(130,226), Point(382,286), Scalar(255,255,255),FILLED); //Bottom right and top left 
    line(img,Point(130,296),Point(382,296),Scalar(255, 255, 255),2);

    putText(img, "Navaneeth D", Point(170,262),FONT_HERSHEY_COMPLEX,0.8, Scalar(0, 69, 255),2);
    imshow("Image", img);
    waitKey(0);

}




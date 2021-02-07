#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include "Header_Files/faceDetection.h"
using namespace cv;
using namespace std;


/////////////////  face detection  //////////////////////

void detectFace(string path) {

    Mat img = imread(path);
    vector<Rect> faces;
    CascadeClassifier faceCascade;
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");

    if (faceCascade.empty()) {
        cout << "XML file not loaded";
    }

    faceCascade.detectMultiScale(img, faces, 1.1, 10);

    for (int i = 0; i < faces.size(); i++)
    {
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3); 
    }

    imshow("Image", img);
    waitKey(0);

}
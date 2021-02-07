#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Header_Files/detectContour.h"
using namespace cv;
using namespace std;


void getContours(Mat imgDil, Mat img) {

    vector<vector<Point>> contours;
    vector<Vec4i> heirarchy;
    int area, objCor;
    string objType;
    float peri, aspectRatio;

    findContours(imgDil, contours, heirarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    // drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
    vector<vector<Point>> conpoly(contours.size());
    vector<Rect> boundingBox(contours.size());

    // filter
    for (int i = 0; i < contours.size() ; i++)
    {
        area = contourArea(contours[i]);
        cout << area << endl;

        if (area > 1000) {
            peri = arcLength(contours[i], true);
            
            if (!contours.empty()) {
                approxPolyDP(contours[i], conpoly[i], 0.02 * peri, true);
            }
            cout << conpoly[i].size() << endl;
            boundingBox[i] = boundingRect(conpoly[i]);
            rectangle(img, boundingBox[i].tl(), boundingBox[i].br(), Scalar(0, 255, 0), 5);
            // drawContours(img, conpoly, i, Scalar(255, 0, 255), 2);
            objCor = (int)conpoly[i].size();

            if (objCor == 3) { objType = "Triangle"; }
            else if (objCor == 4) {
                aspectRatio = (float)boundingBox[i].width / (float)boundingBox[i].height;
                if (aspectRatio > 0.95 && aspectRatio < 1.05) {
                    objType = "Square";
                }
                else {
                    objType = "Rectangle";
                }
                
            }
            else { objType = "Circle"; }

            putText(img, objType, { boundingBox[i].x, boundingBox[i].y-5}, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
        }
    }
}

void detectContour(string path) {

    Mat img = imread(path);
    Mat imgBlur, imgCanny, imgDila, imgGray;

    // preprocessing
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
    Canny(imgBlur, imgCanny, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDila, kernel);

    getContours(imgDila, img);

    imshow("Image", img);
    // imshow("Image gray", imgGray);
    // imshow("Image blur", imgBlur);
    // imshow("Image canny", imgCanny);
    // imshow("Image dilated", imgDila);

    waitKey(0);

}
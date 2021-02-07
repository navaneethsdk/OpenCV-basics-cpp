#pragma once
#ifndef OPENCV_FUNCTIONS
#define OPENCV_FUNCTIONS

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void BGRtoGRAY(string path);
void imageBlur(string path);
void edgeDetector(string path);

#endif

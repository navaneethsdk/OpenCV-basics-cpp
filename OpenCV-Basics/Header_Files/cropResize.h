#pragma once
#ifndef OPENCV_CROP_RESIZE
#define OPENCV_CROP_RESIZE

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void resizeImg(string path);
void cropImg(string path);

#endif

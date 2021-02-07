#pragma once
#ifndef OPENCV_READ_MEDIA
#define OPENCV_READ_MEDIA

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void showImage(string path);
void showVideo(string path);
void showWebcam();

#endif

#pragma once
#ifndef FACE_DET
#define FACE_DET

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void detectFace(string path);

#endif

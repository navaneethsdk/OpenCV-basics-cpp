#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Header_Files/ReadMedia.h"
#include "Header_Files/basicFunctions.h"
#include "Header_Files/cropResize.h"
#include "Header_Files/draw.h"
#include "Header_Files/warpPerspective.h"
#include "Header_Files/colorDetection.h"
#include "Header_Files/detectContour.h"
#include "Header_Files/faceDetection.h"

using namespace cv;
using namespace std;


int main() {
    string path = "Resources/test.png";
    // BGRtoGRAY(path);
    // imageBlur(path);
    // edgeDetector(path);
    // resizeImg(path);
    // cropImg(path);
    // generateBlankImg();
    warpPerspective(path);
    // detectColor(path);
    // detectContour(path);
    // detectFace(path);
    return 0;
}

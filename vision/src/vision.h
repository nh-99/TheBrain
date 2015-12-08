#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

class Vision {
    public:
        Mat applyHsvThreshold(Mat srcImage);
        Mat applyImageTransformations(Mat srcImage);
};

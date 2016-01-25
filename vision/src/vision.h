#ifndef VISION_H
#define VISION_H

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
using namespace cv;

class Vision {
    public:
        Mat applyHsvThreshold(Mat srcImage);
        Mat applyCannyTransform(Mat srcImage);
        vector<Rect> getContours(Mat srcImage);
        map<int, double> getResults(vector<Rect> zones);
};
#endif

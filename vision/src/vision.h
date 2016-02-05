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
        vector<RotatedRect> getContours(Mat srcImage);
        vector<map<int, double> > getResults(vector<RotatedRect> zones);
};
#endif

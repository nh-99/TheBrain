#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>

using namespace cv;

class Vision {
    private:
        Mat applyHsvThreshold(Mat srcImage);
        Mat applyConvexHull(Mat srcImage);
        Mat applyMinusThreshold(Mat srcImage);
        vector getImageContours(Mat srcImage);
    public:
        map getValues(vector imageContours);
};

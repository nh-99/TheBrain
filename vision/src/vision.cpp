#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

Mat applyHsvThreshold(Mat srcImage) {
    Mat hsv_image, threshold, toReturn; // The material that the function will return
    medianBlur(srcImage, srcImage, 3);
    cvtColor(srcImage, hsv_image, COLOR_BGR2HSV);
    inRange(hsv_image, Scalar(86, 117, 209), Scalar(96, 255, 255), toReturn);
    return toReturn;
}

Mat applyImageTransformations(Mat srcImage) {
    Mat newImage = applyHsvThreshold(srcImage);
    return newImage;
}

int main() {
    Mat src = imread("/home/noah/Pictures/SampleImages/image.jpg");
    if(src.empty()) {
        return 1;
    }
    Mat testApply = applyImageTransformations(src);
    imshow("Test", testApply);
    waitKey(0);
    return 0;
}

#include "src/vision.h"

Mat Vision::applyHsvThreshold(Mat srcImage) {
    Mat hsv_image, threshold, toReturn; // The material that the function will return
    medianBlur(srcImage, srcImage, 3);
    cvtColor(srcImage, hsv_image, COLOR_BGR2HSV);
    inRange(hsv_image, Scalar(86, 117, 209), Scalar(96, 255, 255), toReturn);
    return toReturn;
}

Mat Vision::applyImageTransformations(Mat srcImage) {
    Mat newImage = applyHsvThreshold(srcImage);
    return newImage;
}

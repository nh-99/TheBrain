#include "vision.h"

Mat Vision::applyHsvThreshold(Mat srcImage) {
    Mat hsv_image, threshold, toReturn; // The material that the function will return
    medianBlur(srcImage, srcImage, 3);
    cvtColor(srcImage, hsv_image, COLOR_BGR2HSV);
    inRange(hsv_image, Scalar(86, 117, 209), Scalar(96, 255, 255), toReturn);
    return toReturn;
}

Mat Vision::applyCannyTransform(Mat srcImage) {
    Mat cannyOutput;
    int thresh = 100;
    Canny(srcImage, cannyOutput, thresh, thresh*2, 3);
    return cannyOutput;
}

vector<vector<Point> > Vision::getContours(Mat srcImage) {
    vector<vector<Point> > contours;
    findContours(srcImage, contours, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
    return contours;
}

map<int, double> Vision::getResults(vector<vector<Point> > contours) {
    map<int, double> toReturn;
    /// Get the moments
    vector<Moments> mu(contours.size());
    for(int i = 0; i < contours.size(); i++) {
        mu[i] = moments(contours[i], false);
    }

    ///  Get the mass centers:
    vector<Point2f> mc(contours.size());
    for(int i = 0; i < contours.size(); i++) {
        mc[i] = Point2f(mu[i].m10/mu[i].m00, mu[i].m01/mu[i].m00);
    }

    return toReturn;
}

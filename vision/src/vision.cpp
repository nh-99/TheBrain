#include "vision.h"

int thresh = 100;
RNG rng(12345);
int max_thresh = 255;
int w_filter = 30;

Mat Vision::applyHsvThreshold(Mat srcImage) {
    Mat hsv_image, threshold, toReturn; // The material that the function will return
    medianBlur(srcImage, srcImage, 3);
    cvtColor(srcImage, hsv_image, COLOR_BGR2HSV);
    inRange(hsv_image, Scalar(0, 165, 87), Scalar(94, 255, 183), toReturn);
    return toReturn;
}

Mat Vision::applyCannyTransform(Mat srcImage) {
    Mat cannyOutput;
    Canny(srcImage, cannyOutput, thresh, thresh*2, 3);
    return cannyOutput;
}

vector<RotatedRect> Vision::getContours(Mat srcImage) {
    Mat threshold_output;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    /// Detect edges using Threshold
    threshold(srcImage, threshold_output, thresh, 255, THRESH_BINARY);
    /// Find contours
    findContours(threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

    /// Approximate contours to polygons + get bounding rects and circles
    vector<RotatedRect> minRect(contours.size());

    for(int i = 0; i < contours.size(); i++) {
        minRect.push_back(minAreaRect(Mat(contours[i])));
    }
    return minRect;
}

vector<map<int, double> > Vision::getResults(vector<RotatedRect> zones) {
    vector<map<int, double> > toReturn;
    for(int i = 0; i < zones.size(); i++) {
        if(zones[i].size.width > w_filter) { // Filter the objects by width before returning the values
            map<int, double> zoneValues;
            zoneValues[0] = zones[i].size.width;
            zoneValues[1] = zones[i].size.height;
//            zoneValues[2] = zones[i].size().area();
//            zoneValues[3] = ((zones[i].x + zones[i].width) / 2);
//            zoneValues[4] = ((zones[i].y + zones[i].height) / 2);
            toReturn.push_back(zoneValues);
        }
    }
    return toReturn;
}

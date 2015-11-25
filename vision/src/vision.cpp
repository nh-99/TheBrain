#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

Mat applyHsvThreshold(Mat srcImage) {
    Mat hsv_image, toReturn; // The material that the function will return
    medianBlur(srcImage, srcImage, 3);
    cvtColor(srcImage, hsv_image, COLOR_BGR2HSV); // TODO: only apply this to a clone, return og for other function
    inRange(hsv_image, Scalar(86, 117, 209), Scalar(96, 255, 255), toReturn);
    return toReturn;
}

Mat applyCannyDetect(Mat srcImage) {
    Mat detected_edges;
    Mat dst;
    dst.create(srcImage.size(), srcImage.type());

    // cvtColor(srcImage, src_gray, CV_BGR2GRAY);
    /// Canny detector¬
    Canny(detected_edges, detected_edges, 100, 100 * 3, 3);
    /// Using Canny's output as a mask, we display our result¬
    dst = Scalar::all(0);
    srcImage.copyTo(dst, detected_edges);
    return dst;
}

Mat applyImageTransformations(Mat srcImage) {
    Mat newImage = applyHsvThreshold(srcImage);
    Mat neewImage = applyCannyDetect(newImage);
    return neewImage;
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

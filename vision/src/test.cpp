#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

int main() {
    Mat src = imread("/home/noah/Pictures/SampleImages/image.jpg");
    Mat output;
    imshow("src", src);
    waitKey();

    inRange(src, cv::Scalar(0, 0, 0), cv::Scalar(255, 200, 255), output);
    imshow("output", output);
    waitKey();
    return 0;
}

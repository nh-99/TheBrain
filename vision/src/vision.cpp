#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

Mat applyHsvThreshold(Mat srcImage) {
    // TODO: Apply HSV threshold
    return srcImage;
}

Mat applyCannyDetect(Mat srcImage) {
    Mat src_gray, detected_edges;
    Mat dst;
    dst.create(srcImage.size(), srcImage.type());

    cvtColor(srcImage, src_gray, CV_BGR2GRAY);

    blur(src_gray, detected_edges, Size(3, 3));
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
    Mat src = imread("/home/noah/Pictures/SampleImages/image13.jpg");
    Mat testApply = applyImageTransformations(src);
    imshow("Test", testApply);
    waitKey(0);
    return 0;
}

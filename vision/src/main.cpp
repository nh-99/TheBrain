#include "vision.h"

Mat src;
Vision vt;

int main(int argc, const char* argv[]) {
    src = imread("/home/noah/Pictures/RealFullField/0.jpg",1);
    Mat hsv_image = vt.applyHsvThreshold(src);
    vector<Rect> getRectangles = vt.getContours(hsv_image);
    cout << getRectangles[0].width << endl;
}

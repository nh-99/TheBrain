#include "vision.h"

Mat src;
Vision vt;
RNG rng(12345);

int main(int argc, const char* argv[]) {
    src = imread(argv[1], 1);
    Mat hsv_image = vt.applyHsvThreshold(src);
    vector<Rect> getRectangles = vt.getContours(hsv_image);
    vector<map<int, double> > results = vt.getResults(getRectangles);
    for(int i = 0; i < results.size(); i++) {
        map<int, double> resultMap = results[i];
        cout << resultMap[0] << endl;
    }
}

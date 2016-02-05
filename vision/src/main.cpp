#include "vision.h"
#include "target.h"

Vision vt;
Target target;
double targetFeet = 20;
double pixelWidth = 640;
double fovAngle = 59.7 / 2;

int main(int argc, const char* argv[]) {
    Mat src = imread(argv[1], 1);
    Mat hsv_image = vt.applyHsvThreshold(src);
    vector<RotatedRect> getRectangles = vt.getContours(hsv_image);
    vector<map<int, double> > results = vt.getResults(getRectangles);
    for(int i = 0; i < results.size(); i++) {
        map<int, double> resultMap = results[i];
        double distanceOne = target.directDistanceToTarget(targetFeet, resultMap[0], pixelWidth, fovAngle);
        cout << distanceOne << endl;
//        double distanceTwo = target.directDistanceToTarget(targetFeet, resultMap[4], pixelWidth, fovAngle);
    }
}

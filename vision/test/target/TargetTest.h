#include <cxxtest/TestSuite.h>
#include "vision.h"
#include "target.h"

Mat src; Mat hsv_image;
vector<RotatedRect> getRectangles;
vector<map<int, double> > results;

Vision vt;
Target target;
double targetFeet = 21;
double pixelWidth = 640;
double fovAngle = 59.7 / 2;

class TargetTest : public CxxTest::TestSuite {
public:
    void testLoadImage(void) {
        src = imread("images/0.jpg");
        if(!src.data) {
            TS_FAIL("Image could not be read");
        } else {
            TS_ASSERT_EQUALS(1, 1);
        }
    }

    void testHsvImage(void) {
        hsv_image = vt.applyHsvThreshold(src);
        TS_ASSERT_EQUALS(hsv_image.size(), Size(640, 480));
    }

    void testGetRectangles(void) {
        getRectangles = vt.getContours(hsv_image);
        TS_ASSERT_EQUALS(getRectangles.size(), 24);
    }

    void testGetResults(void) {
        results = vt.getResults(getRectangles);
        TS_ASSERT_EQUALS(results.size(), 2);
    }

    void testDistanceValues(void) {
        double distance;
        for(int i = 0; i < results.size(); i++) {
            map<int, double> resultMap = results[i];
            double distanceOne = target.directDistanceToTarget(targetFeet, resultMap[0], pixelWidth, fovAngle);
            distance = distanceOne;
        }
        TS_ASSERT_EQUALS(round(distance), 136);
    }
};

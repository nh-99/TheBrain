#include <cxxtest/TestSuite.h>
#include "target.h"
#include <math.h>

class TestDistanceAlgorithms : public CxxTest::TestSuite {
    Target target;
    public:
        void testGetAngle(void) {
            double angle = target.initialAngleToRotate(5.385, 4.472);
            TS_ASSERT_EQUALS(round(angle), 1.0);
        }
        void testGetDistanceToFinalRotation(void) {
            double angle = target.initialAngleToRotate(5.385, 4.472);
            double distanceToRotation = target.distanceToFinalRotation(angle, 5.385);
            TS_ASSERT_EQUALS(round(distanceToRotation), 3.0);
        }
        void testDistanceToTote(void) {
            double angle = target.initialAngleToRotate(5.385, 4.472);
            double distanceToTote = target.distanceToTote(angle, 5.385);
            TS_ASSERT_EQUALS(round(distanceToTote), 4.0);
        }
};

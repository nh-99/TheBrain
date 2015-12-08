#include <cxxtest/TestSuite.h>
#include "target.h"
#include <math.h>

class TestDistanceAlgorithms : public CxxTest::TestSuite {
    public:
        Target target;
        void testGetAngle(void) {
            double angle = target.initialAngleToRotate(5.385, 4.472);
            TS_ASSERT_EQUALS(round(angle), 0.0);
        }
        void testGetDistanceToFinalRotation(void) {
            double angle = target.initialAngleToRotate(5.385, 4.472);
            double distanceToRotation = target.distanceToFinalRotation(angle, 5.385);
            TS_ASSERT_EQUALS(round(distanceToRotation), 5.0);
        }
        void testDistanceToTote(void) {
            double angle = target.initialAngleToRotate(5.385, 4.472);
            double distanceToTote = target.distanceToTote(angle, 5.385);
            TS_ASSERT_EQUALS(round(distanceToTote), 2.0);
        }
};

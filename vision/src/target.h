#ifndef TARGET_H
#define TARGET_H
#define PI 3.14159265

#include <stdlib.h>
#include <math.h>

class Target {
    public:
        double directDistanceToTarget(double targetFeet, double targetPixels, double fovPixels, double fovAngle);
        double getInitialAngle(double targetLength, double distanceOne, double distanceTwo);
        double getLengthOne(double initialAngle, double distanceOne);
        double getLengthTwo(double initialAngle, double distanceOne);
        double getFirstDistanceToMove(double lengthOne, double lengthTwo, double distanceToRotate);
        double getFirstAngleToRotate(double distanceToRotate, double firstDistanceToMove, double distanceOne);
        double getFinalAngle(double initialAngle, double firstAngleToRotate);
};
#endif

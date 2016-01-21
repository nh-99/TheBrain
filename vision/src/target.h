#ifndef TARGET_H
#define TARGET_H

#include <stdlib.h>
#include <math.h>

class Target {
    public:
        double initialAngleToRotate(double distanceOne, double distanceTwo);
        double distanceToFinalRotation(double angleToRotate, double distanceOne);
        double distanceToTote(double angleToRotate, double distanceOne);
    private:
        double initialAngle(double distanceOne, double distanceTwo);
};
#endif

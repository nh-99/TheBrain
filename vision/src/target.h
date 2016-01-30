#ifndef TARGET_H
#define TARGET_H
#define PI 3.14159265

#include <stdlib.h>
#include <math.h>

class Target {
    public:
        double directDistanceToTarget(double targetFeet, double targetPixels, double fovPixels, double fovAngle);
        //
};
#endif

#ifndef TARGET_H
#define TARGET_H

#include <stdlib.h>
#include <math.h>

class Target {
    public:
        double directDistanceToTarget(double targetFeet, double targetPixels, double fovPixels, double fovAngle);
};
#endif

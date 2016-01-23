#ifndef VELOCITY_H
#define VELOCITY_H

#include <stdlib.h>
#include <math.h>

class Velocity {
    private:
        double velocityX(double distanceToGoal, double height, double time);
        double velocityY(double height);
    public:
        double getLaunchVelocity(distanceToGoal, height, time);
};
#endif

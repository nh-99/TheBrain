#include "velocity.h"

/*
 * Created by Noah Howard
 * 
 * Code to find the velocity needed to launch the projectile to a height
 */

double Velocity::velocityX(double distanceToGoal, double height, double time) {
    distanceX = sqrt((distanceToGoal^2) - (height^2));
    return distanceX / time;
}

double Velocity::velocityY(double height) {
    return 19.6 * y;
}

double Velocity::getLaunchVelocity(double distanceToGoal, double height, double time) {
    return velocityX(distanceToGoal, height, time) + sqrt(velocityY(height));
}

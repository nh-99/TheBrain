#include "target.h"

double Target::initialAngleToRotate(double distanceOne, double distanceTwo) {
    // cos^-1((d2-d1-x1)/(2*d1*x1)) = angleToRotate
    // distances must be in inches
    return acos((pow(2.75,2.0) + pow(distanceOne,2.0) - pow(distanceTwo,2.0))/(2 * distanceOne * 2.75));
}

double Target::distanceToFinalRotation(double angleToRotate, double distanceOne) {
    return (cos(angleToRotate) * distanceOne);
}

double Target::distanceToTote(double angleToRotate, double distanceOne) {
    return (sin(angleToRotate) * distanceOne);
}

#include "target.h"

/*
 * Calling order for this class:
 * initialAngle
 * initialAngleToRotate
 * secondAngleToRotate
 * legOne
 * legTwo
 * driveDistanceOne
 */

double Target::initialAngle(double distanceOne, double distanceTwo) {
    // cos^-1((d2-d1-x1)/(2*d1*x1)) = angleToRotate
    // distances must be in inches
    return acos((pow(2.75,2.0) + pow(distanceOne,2.0) - pow(distanceTwo,2.0))/(2 * distanceOne * 2.75));
}

double Target::legOne(double angleToRotate, double distanceOne) {
    return (cos(angleToRotate) * distanceOne);
}

double Target::legTwo(double angleToRotate, double distanceOne) {
    return (sin(angleToRotate) * distanceOne);
}

double Target::driveDistanceOne(double distanceToRotate) {
    return sqrt(((legTwo - distanceNeededToRotate)^2) + (legOne^2));
}

double Target::initialAngleToRotate(double distanceNeededToRotate, double distanceOne) {
    double newLeg = Target::driveDistanceOne(distanceNeededToRotate);
    return acos(((distanceNeededToRotate^2)-(newLeg^2)-(distanceOne^2))/(-2 * newLeg * distanceOne));
}

double Target::secondAngleToRotate(double initialAngle, double firstRotationAngle) {
    return 180 - ((90 - initialAngle) + firstRotationAngle);
}

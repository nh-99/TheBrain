#include "target.h"

/*
 * Created by Noah Howard
 */

double Target::directDistanceToTarget(double targetFeet, double targetPixels, double fovPixels, double fovAngle) {
    return (targetFeet * fovPixels) / (2 * targetPixels * tan(fovAngle * (PI/180)));
}

double Target::getInitialAngle(double targetLength, double distanceOne, double distanceTwo) {
    return acos((pow(targetLength, 2.0) + pow(distanceOne, 2.0) - pow(distanceTwo, 2.0)) / (2 * targetLength * distanceOne));
}

double Target::getLengthOne(double initialAngle, double distanceOne) {
    return cos(initialAngle) * distanceOne;
}

double Target::getLengthTwo(double initialAngle, double distanceOne) {
    return sin(initialAngle) * distanceOne;
}

double Target::getFirstDistanceToMove(double lengthOne, double lengthTwo, double distanceToRotate) {
    return sqrt(pow((lengthTwo - distanceToRotate), 2.0) + lengthOne);
}

double Target::getFirstAngleToRotate(double distanceToRotate, double firstDistanceToMove, double distanceOne) {
    return acos((pow(distanceToRotate, 2.0) - pow(firstDistanceToMove, 2) - pow(distanceOne, 2)) / (-2 * firstDistanceToMove * distanceOne));
}

double Target::getFinalAngle(double initialAngle, double firstAngleToRotate) {
    double angleFour = 90 - initialAngle;
    return 180 - (angleFour + firstAngleToRotate);
}

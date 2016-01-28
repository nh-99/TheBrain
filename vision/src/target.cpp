#include "target.h"

/*
 * Created by Noah Howard
 */

double Target::directDistanceToTarget(double targetFeet, double targetPixels, double fovPixels, double fovAngle) {
    return (targetFeet * fovPixels) / (2 * targetPixels * tan(fovAngle));
}

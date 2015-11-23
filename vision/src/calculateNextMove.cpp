#include<stdlib.h>
#include<string>

namespace std;

void* calculateInnerVelocity();
void* checkForAction();
void* initiatePickup();

void getNextMove(float distanceToGoal, float widthOfRobot, float outerWheelVelocity) {
    double innerVelocity = calculateInnerVelocity(distanceToGoal, widthOfRobot, outerWheelVelocity);
    checkForAction(distanceToGoal);
}

double calculateInnerVelocity(float distanceToGoal, float widthOfRobot, float outerWheelVelocity) {
    return (outerWheelVelocity * distanceToGoal/(2 * widthOfRobot * distanceToGoal));
}

string checkForAction(float distanceToGoal) {
    if(distanceToGoal < 15) {
        initiatePickup();
    }
}

void initiatePickup() {
    // TODO: Tell the robot to pickup a tote here with fancy networking shit
}

#include "Wheel.hpp"
#include <iostream>

Wheel::Wheel() : steeringAngle(0) {}  // Default constructor that initializes the steering angle to 0

int Wheel::getSteeringAngle() const {
    return steeringAngle;
}

void Wheel::setSteeringAngle(int angle) {
    int newAngle = steeringAngle + angle;

    if (newAngle < -270 || newAngle > 270) {
        std::cout << "You cannot turn the wheel any further." << std::endl;
    } else {
        steeringAngle = newAngle;
    }
}

void Wheel::turnLeft() {
    if (steeringAngle == -90) {
        std::cout << "You are turning left." << std::endl;
    }
}

void Wheel::turnRight() {
    if (steeringAngle == 90) {
        std::cout << "You are turning right." << std::endl;
    }
}

void Wheel::makeUturn() {
    if (steeringAngle == -180 || steeringAngle == 180) {
        std::cout << "You are making a U-turn." << std::endl;
    } else {
        std::cout << "You cannot make a U-turn at the moment." << std::endl;
    }
}

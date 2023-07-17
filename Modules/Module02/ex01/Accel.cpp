#include "Accel.hpp"

Accel::Accel() : currentSpeed(0) {}

Accel::~Accel(){};  // Destructor

int Accel::getCurrentSpeed() const {
    return currentSpeed;
}

void Accel::setCurrentSpeed(int speed) {
    currentSpeed = speed;
}

void Accel::accelerate(int accel) {
    int amount = accel;
    int newSpeed = currentSpeed + amount;
    if (newSpeed > 200) {  // Check if the new speed exceeds the limit
        std::cout << "Invalid speed. Speed cannot exceed 200 km/h." << std::endl;
        currentSpeed = 200;  // Set the speed to the maximum allowed value
    } else {
        currentSpeed = newSpeed;  // Update the speed
    }
}

void Accel::decelerate(int decel) {
    int amount = decel;
    int newSpeed = currentSpeed - amount;
    if (newSpeed < 0) {  // Check if the new speed goes below zero
        std::cout << "Invalid deceleration. You cannot decelerate below 0 km/h." << std::endl;
        currentSpeed = 0;  // Set the speed to zero
    } else {
        currentSpeed = newSpeed;  // Update the speed
    }
}
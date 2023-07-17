#ifndef ACCEL_HPP
#define ACCEL_HPP

#include <iostream>

class Accel {
protected:
    int currentSpeed;  // The current speed of the acceleration

public:
    Accel();  // Default constructor
    ~Accel();  // Destructor

    int getCurrentSpeed() const;  // Retrieves the current speed
    void setCurrentSpeed(int speed);  // Sets the current speed

    void accelerate(int accel);  // Increases the speed by the specified amount
    void decelerate(int decel);  // Decreases the speed by the specified amount
};

#endif

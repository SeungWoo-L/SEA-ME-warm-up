#ifndef __WHEEL_HPP__
#define __WHEEL_HPP__

class Wheel {
protected:
    int steeringAngle;  // The current angle of the steering wheel

public:
    Wheel();  // Default constructor

    int getSteeringAngle() const;  // Retrieves the current steering angle
    void setSteeringAngle(int angle);  // Sets the steering angle
    void turnLeft();  // Performs a left turn if the steering angle is -90 degrees
    void turnRight();  // Performs a right turn if the steering angle is 90 degrees
    void makeUturn();  // Performs a U-turn if the steering angle is -180 or 180 degrees
};

#endif

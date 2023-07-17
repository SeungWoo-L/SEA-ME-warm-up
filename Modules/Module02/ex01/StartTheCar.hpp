#ifndef STARTTHECAR_HPP
#define STARTTHECAR_HPP

#include "Wheel.hpp"
#include "Accel.hpp"
#include "Engine.hpp"
#include "Apart.hpp"
#include <memory>

class StartTheCar : public Wheel, public Accel, public Engine {
private:
    int mode;  // The mode selected by the user
    std::shared_ptr<Apart> apart;  // Shared pointer to an instance of the Apart class

public:
    StartTheCar();  // Constructor

    void run();  // Function to start the car program

private:
    void showMainMenu();  // Function to display the main menu
    void useCar();  // Function to use the car
    void showCarMenu();  // Function to display the car menu
    void setSteering();  // Function to set the steering angle
    void setSpeed();  // Function to set the car speed
    void checkCarStatus();  // Function to check the car's status
    void stopTheCar();  // Function to stop the car
};

#endif

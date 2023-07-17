#include "StartTheCar.hpp"
#include <iostream>
#include <limits>

StartTheCar::StartTheCar() : mode(0), apart(std::make_shared<Apart>()) {
    apart->setName("Default");
    apart->setYear(0);
}

void StartTheCar::run() {
    while (true) {
    re1:
        showMainMenu();
        if (mode == 1) {
            if (getEngineStatus() == false) {
                useCar();
            }
            if (getEngineStatus() == true) {
                showCarMenu();
            } else {
                goto re1;
            }
        } else if (mode == 2) {
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        }
    }
}

void StartTheCar::showMainMenu() {
    std::cout << "Select an option:\n";
    std::cout << "1. Use Car\n";
    std::cout << "2. Don't Use Car\n";
    std::cout << "Enter your choice: ";
    std::cin >> mode;

    while (std::cin.fail() || (mode != 1 && mode != 2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid choice.\n";
        std::cout << "Enter your choice: ";
        std::cin >> mode;
    }
}

void StartTheCar::useCar() {
    std::string carName;
    int carYear;
    std::cout << "Enter the Name of the Car: ";
    std::cin >> carName;
    std::cout << "Enter the Year of the Car: ";
    std::cin >> carYear;
    apart->setName(carName);
    apart->setYear(carYear);

    startEngine();
    std::cout << "The engine is started.\n";
}

void StartTheCar::showCarMenu() {
    int option;
    while (true) {
        std::cout << "Car Menu:\n";
        std::cout << "1. Set Steering\n";
        std::cout << "2. Set Speed\n";
        std::cout << "3. Check Car's Status\n";
        std::cout << "4. Stop the Car\n";
        std::cout << "Enter the option number: ";
        std::cin >> option;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid option number.\n";
            continue;
        }

        if (option == 1) {
            setSteering();
        } else if (option == 2) {
            setSpeed();
        } else if (option == 3) {
            checkCarStatus();
        } else if (option == 4) {
            stopTheCar();
            break;
        } else {
            std::cout << "Invalid option number. Please enter a valid option.\n";
        }
    }
}

void StartTheCar::setSteering() {
    int angle;
    std::cout << "Enter the angle to adjust (Enter -1 to exit): ";
    std::cin >> angle;
    if (angle == -1) {
        return;
    }

    int newAngle = Wheel::getSteeringAngle() + angle;
    if (newAngle < -270 || newAngle > 270) {
        std::cout << "Invalid angle. Steering angle exceeds the limit.\n";
        if (newAngle < -270) {
            Wheel::setSteeringAngle(-270);
        } else if (newAngle > 270) {
            Wheel::setSteeringAngle(270);
        }
        return;
    }

    Wheel::setSteeringAngle(angle);
    std::cout << "Steering angle updated.\n";
    if (Wheel::getSteeringAngle() == 90) {
        Wheel::turnRight();
    } else if (Wheel::getSteeringAngle() == -90) {
        Wheel::turnLeft();
    } else if (Wheel::getSteeringAngle() == -180 || newAngle == 180) {
        Wheel::makeUturn();
    }
}

void StartTheCar::setSpeed() {
    int speed;
    std::cout << "Enter the speed to set: ";
    std::cin >> speed;

    if (speed < 0) {
        std::cout << "Decelerating...\n";
        Accel::decelerate(-speed);
    } else {
        Accel::accelerate(speed);
        std::cout << "Speed updated.\n";
    }

    if (Accel::getCurrentSpeed() == 0) {
        std::cout << "The car has stopped." << std::endl;
    }
}

void StartTheCar::checkCarStatus() {
    std::cout << "Car's Status:\n";
    std::cout << "Car's Name: " << apart->getName() << "\n";
    std::cout << "Car's Year: " << apart->getYear() << "\n";
    std::cout << "Engine On/Off: " << (Engine::getEngineStatus() ? "On" : "Off") << std::endl;
    std::cout << "Engine Temperature: " << Engine::getEngineTemp() << " degrees" << std::endl;
    std::cout << "Car Speed: " << Accel::getCurrentSpeed() << std::endl;
    std::cout << "Steering Angle: " << Wheel::getSteeringAngle() << std::endl;
}

void StartTheCar::stopTheCar() {
    if (Engine::getEngineStatus()) {
        Engine::stopEngine();
        std::cout << "The engine is stopped.\n";
    } else {
        std::cout << "The engine is already turned off.\n";
    }
}

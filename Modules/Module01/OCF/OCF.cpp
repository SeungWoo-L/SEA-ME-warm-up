#include"OCF.hpp"


Car::Car(const std::string& name, int speed) {
        std::cout << "Basic Constructor Called \n";
        this ->Cars_Name = name;
        this ->speed = speed; 
    }

Car::Car(const Car& car){

        std::cout << "Copy Constructor Called \n";
        this -> Cars_Name = car.Cars_Name;
        this -> speed = car.speed;
    }

Car& Car::operator=(const Car& car) {

       std::cout<<"Copy Assignment Constructor Called \n";


        if (this == &car) {
            return *this;
        }
        
        this->Cars_Name = car.Cars_Name;
        this->speed = car.speed;

        return *this;
    }

Car::~Car() {
    std::cout << "Destructor Called\n";
}

void Car::printCarDetails() const {
        std::cout << "Car Name: " << Cars_Name << ", Speed: " << speed << std::endl << std::endl;
    }
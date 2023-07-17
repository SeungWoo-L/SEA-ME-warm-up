#include "Truck.hpp"

TRUCK::TRUCK() : Car(), Load(0) {}

TRUCK::TRUCK(const std::string& maker, const std::string& model, int year, int speed, double load)
    : Car(maker, model, year, speed), Load(load) {


    if (load > 10) {
        std::cout << "Caution: Load capacity exceeds the recommended limit!" << std::endl;
    }
}

TRUCK::TRUCK(const TRUCK& truck_ref, double load)
    : Car(truck_ref), Load(load) {
   
}

TRUCK& TRUCK::operator=(const TRUCK& truck_ref) {
  
    if (this != &truck_ref) {
        Car::operator=(truck_ref); 
        Load = truck_ref.Load;
    }
    return *this;
}

TRUCK::~TRUCK() {}


void TRUCK::displayTruckInfo() const {
    displayCarInfo();
    std::cout << "Truck Load Capacity: " << Load << " tons" << std::endl;
}

void TRUCK::getTruckLoadAmount() const{
    std:: cout << "This Car's load capacity is : " << Load  << " tons" << std::endl;
    
}

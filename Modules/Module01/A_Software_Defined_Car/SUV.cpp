#include "SUV.hpp"

SUV::SUV() : Car(Car_Maker, Car_Model, Car_Year, speed){
    int Capacity = 6;
}

SUV::SUV(const std::string& maker, const std::string& model, int year, int speed, int capacity):
Car(maker, model, year, speed){
     if(capacity <= 6){
        std::cout << "Minimun Capacityis 6, Capacity is set 6" << std::endl;
        this-> Capacity = 6;
    }
    else if(capacity >= 7 && capacity <= 12){
        this -> Capacity = capacity;
    }
    else{
        std::cout << "Capacity you wanted is too BIG!!" << std::endl
        << "The Capacity is set to 12" << std::endl; 
        this -> Capacity = 12;
    }
}

SUV::SUV(const SUV& suv_ref, int capacity):Car(suv_ref){
    std::cout << "Copy Function is Called by SUV.cpp \n";

    if(Capacity < 6){
        this-> Capacity = 6;
    }
    else if(Capacity >= 6 || Capacity <= 12){
        this -> Capacity = capacity;
    }
    else{
        std::cout << "Capacity you wanted is too BIG!!" << std::endl
        << "The Capacity is set to 12" << std::endl; 
        this -> Capacity = 12;
    }
}

SUV &SUV::operator=(const SUV & suv_ref){
    if(this == & suv_ref){
        return *this;
    }

    Car::operator=(suv_ref);

    Capacity = suv_ref.Capacity;

    return *this;

}

SUV::~SUV(){}


void SUV::displaySUVInfo() const {
    displayCarInfo();
    std::cout << "SUV Human Capacity: " << Capacity << " mans" << std::endl;
}


int SUV::GetCapacity() const{
    std::cout << "This Car's Capacity is :" ; 
    return this-> Capacity;}

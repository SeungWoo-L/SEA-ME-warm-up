#ifndef __TRUCK_HPP__
#define __TRUCK_HPP__

#include "Car.hpp"

class TRUCK : virtual public Car{
protected:
    double Load;

public:

    void drive() const override{
        std::cout << "TRUCK can load the stuff more!" << std::endl;
    }

    TRUCK();
   
    TRUCK(const std::string& maker, const std::string& model, int year, int speed, double load);
    TRUCK(const TRUCK& truck_ref, double load);
    TRUCK& operator=(const TRUCK& truck_ref);
    ~TRUCK();

    void displayTruckInfo() const ;

    void getTruckLoadAmount() const;

};



#endif
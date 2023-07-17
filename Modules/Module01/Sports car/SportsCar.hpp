#ifndef __SPORTSCAR_HPP__
#define __SPORTSCAR_HPP__


#include "Car.hpp"

class SportsCar : public Car{

private:
    int top_speed;

public:


    SportsCar() : Car() {top_speed = 0;};
    SportsCar(const Car& ref, int topSpeed);//:Car(ref), top_speed(top_speed){};
   // SportsCar(const std::string& Car_Maker, const std::string& Car_Model, int Car_Year, const int top_speed); // Constructor
    SportsCar(const SportsCar& sportscar_ref);
    SportsCar &operator = (const SportsCar &sportscar_ref);
    ~SportsCar(); 


    void drive() const;

};


#endif


#ifndef __CAR_HPP__
#define __CAR_HPP__

#include<iostream>
#include<string>


class Car{

protected:

    std::string Car_Maker;
    std::string Car_Model;
    int Car_Year;


public:

    Car() : Car_Maker(""), Car_Model(""), Car_Year(0) {} // Default constructor
    Car(std::string Car_Maker, std::string Car_Model, int Car_Year); // Constructor
    Car(const Car& car);
    Car &operator = (const Car &car);
    ~Car();                            // Destructor



    void drive() const;
};




#endif


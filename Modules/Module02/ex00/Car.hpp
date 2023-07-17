#pragma once

#ifndef __CAR_HPP__
#define __CAR_HPP__


#include "Speed.hpp"
#include "Angle.hpp"
#include <iostream>
#include <string>
#include <memory>


class Car : public Speed, public Angle{

public:

    std::string Car_Maker;
    std::string Car_Model;
    int Car_Year;

    Car(); // Default constructor
    Car(std::string Car_Maker, std::string Car_Model, int Car_Year, int speed, int angle); // Constructor
    Car(const Car& car);
    Car &operator = (const Car &car);
    ~Car();                            // Destructor

    void drive() const;
};




#endif


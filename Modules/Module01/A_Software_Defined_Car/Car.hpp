#ifndef __CAR_HPP__
#define __CAR_HPP__

#include<iostream>
#include<string>


class Car {
protected:
    std::string Car_Maker;
    std::string Car_Model;
    int Car_Year;
    int speed;       // 속도

public:

    Car();
    Car(const std::string& maker,
        const std::string& model,
        int year,
        int speed);

    Car(const Car& car_ref);
    Car &operator=(const Car& car_ref);

    virtual ~Car();
    // The virtual destructor ensures proper destruction of derived class
    // objects through base class pointers.
    void displayCarInfo() const ;

    virtual void drive() const = 0;
};



#endif




#ifndef __SPORTS_CAR_CPP__
#define __SPORTS_CAR_CPP__


#include "Car.hpp"

class Sports_Car : virtual public Car{
protected:
    int top_speed;
    std::string Mode;

public:

    void drive() const override {
        std::cout << "Sports car is driving at high speed!" << std::endl;
    }

    Sports_Car();
   
    Sports_Car(const std::string& maker, const std::string& model, int year, int speed, int top_speed , std::string Mode);
    Sports_Car(const Car& car_ref, int top_speed, std::string Mode);
    Sports_Car& operator = (const Sports_Car& sports_car_ref);
    ~Sports_Car();

    void displaySportsCarInfo() const;
    
    
    void GetTopSpeed() const;


};


#endif




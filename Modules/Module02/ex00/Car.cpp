#include"Car.hpp"

Car::Car(): Car_Maker("Default"), Car_Model("Default"), Car_Year(0), Speed() , Angle(){}

Car::Car(std::string Car_Maker, std::string Car_Model, int Car_Year, int speed, int angle)
:Car_Maker(Car_Maker), Car_Model(Car_Model), Car_Year(Car_Year), Speed(), Angle() {
    SetSpeed(speed);
    SetAngle(angle);
    std::cout << "Basic Sport Car Constructor Called \n\n";
}



Car::Car(const Car& car)
:Car_Maker(car.Car_Maker) , Car_Model(car.Car_Model), Car_Year(car.Car_Year), Speed(car), Angle(car){
    std::cout << "Copy Car Constructor Called \n\n";
}


 Car& Car::operator = (const Car &car_ref){

    if(this != &car_ref){
        Speed::operator = (car_ref);
        Angle::operator = (car_ref);
        Car_Maker = car_ref.Car_Maker;
        Car_Model = car_ref.Car_Model;
        Car_Year = car_ref.Car_Year; 
    }
    std::cout<<"Copy Assignment Sport Car Constructor Called \n\n";
    return *this = car_ref;
}

Car::~Car() {
    std::cout << "Destructor Called\n";
}


void Car::drive () const {
    std::cout 
    << "Car Maker Name: " << Car_Maker 
    <<", Model: " << Car_Model 
    <<", Year: "  << Car_Year 
    <<", Speed: " << speed
    <<", Angle: " << angle
    << std::endl << std::endl ;
   
}
 
#include"Sports_Car.hpp"

Sports_Car::Sports_Car() :Car(), top_speed(0), Mode("Echo"){}


Sports_Car:: Sports_Car(const std::string& maker, const std::string& model, int year, int speed, int top_speed , std::string Mode):
    Car(maker, model, year, speed)
{
    if(top_speed>200){
        this -> top_speed = 200;
    }
    else{
        this -> top_speed = top_speed;
    }

    if(Mode == "E" || Mode == "e"){
        this -> Mode = "Echo";
    }
    else if(Mode == "S" || Mode == "s"){
        this -> Mode = "Sports";
        }
    else{
        std::cout << "You type Wrong Mode!" << std::endl 
        << "The Mode is set to the Default Mode(Echo)" << std::endl;
        this -> Mode = "Echo";
    }
}

Sports_Car::Sports_Car(const Car& car_ref, int top_speed, std::string Mode)
:Car(car_ref){
    std::cout << "Copy Function is Called by Sports_Car.cpp \n";

    if(top_speed >200){
        this->top_speed = 200;
    }
    else{
        this-> top_speed = top_speed;
    }

    if(Mode == "Echo" || Mode == "Sport"){
        this -> Mode = Mode;}
    else{
        std::cout << "You type Wrong Mode!" << std::endl 
        << "The Mode is set to the Default Mode(Echo)" << std::endl;
        this -> Mode = "Echo";
    }
}

Sports_Car& Sports_Car::operator=(const Sports_Car & sports_car_ref){
    if (this == &sports_car_ref){
        return *this;
    }
    Car::operator=(sports_car_ref);

    top_speed = sports_car_ref.top_speed;
    Mode = sports_car_ref.Mode;

    return *this;
}


Sports_Car::~Sports_Car(){}


void Sports_Car::displaySportsCarInfo() const{
    displayCarInfo();
    std::cout << "SportsCar's TOP Speed is : " << top_speed << " km/h" << std::endl;
    std::cout << "SportsCar's driving MODE is : " << Mode << std::endl;
    
}

void Sports_Car::GetTopSpeed()const {
    std:: cout << "This Car's maximum speed is : " << top_speed << " km/h" <<std::endl;
}



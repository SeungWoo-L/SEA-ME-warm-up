#include"Car.hpp"


Car::Car(std::string Car_Maker, std::string Car_Model, int Car_Year){
    std::cout << "Basic Sport Car Constructor Called \n\n";
    this -> Car_Maker = Car_Maker;
    this -> Car_Model = Car_Model;
    this -> Car_Year = Car_Year;
}



Car::Car(const Car& car){
    std::cout << "Copy Car Constructor Called \n\n";
    this -> Car_Maker = car.Car_Maker;
    this -> Car_Model = car.Car_Model;
    this -> Car_Year = car.Car_Year;
}


 Car& Car::operator = (const Car &car_ref){

       std::cout<<"Copy Assignment Sport Car Constructor Called \n\n";


        if (this == &car_ref) {
            return *this;
        }
        
        this->Car_Maker = car_ref.Car_Maker;
        this->Car_Model = car_ref.Car_Model;
        this->Car_Year = car_ref.Car_Year;

        return *this;
}

Car::~Car() {
    std::cout << "Destructor Called\n";
}


void Car::drive() const{
    std::cout << "Car Maker Name: " << Car_Maker << ", Model: " << Car_Model 
    <<  ", Year: "  << Car_Year << std::endl << std::endl ;
   

}
 
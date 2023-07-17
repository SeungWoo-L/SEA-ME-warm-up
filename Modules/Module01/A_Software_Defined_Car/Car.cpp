#include"Car.hpp" 
 
 
 
Car::Car()
    : Car_Maker("Default"),
      Car_Model("Defualt"),
      Car_Year(0),
      speed(0){}


Car::Car(const std::string& maker, const std::string& model, int year, int speed)
    : Car_Maker(maker),
      Car_Model(model),
      Car_Year(year),
      speed(speed){}


Car::Car(const Car&car_ref)
    : Car_Maker(car_ref.Car_Maker),
      Car_Model(car_ref.Car_Model),
      Car_Year(car_ref.Car_Year),
      speed(car_ref.speed){}

Car &Car::operator=(const Car& car_ref){
    if(this == &car_ref){
        return *this;
    }

    Car_Maker = car_ref.Car_Maker;
    Car_Model = car_ref.Car_Model;
    Car_Year = car_ref.Car_Year;
    speed = car_ref.speed;

  return *this;
}
Car::~Car(){}


void Car::displayCarInfo() const {
        std::cout << "Car Maker: " << Car_Maker << std::endl;
        std::cout << "Car Model: " << Car_Model << std::endl;
        std::cout << "Car Year: " << Car_Year << std::endl;
        std::cout << "Speed: " << speed << " km/h" << std::endl;
    }
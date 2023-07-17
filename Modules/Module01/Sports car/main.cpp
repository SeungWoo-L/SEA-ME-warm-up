#include "Car.hpp"
#include "SportsCar.hpp"

int main() {

    Car car0;
    car0.drive();

    Car car1("Toyota", "Camry", 2022);
    car1.drive(); // Car Maker Name: Toyota, Model: Camry, Year: 2022


    Car car2(car1); // make a copy
    car2.drive();

    Car car3;
    car3 = car2;
    car3.drive(); // make a copy with operator

    SportsCar sportsCar0;
    sportsCar0.drive(); // SportsCar Top Speed: 300

    SportsCar sportsCar1(car1 , 100);
    sportsCar1.drive();

    SportsCar sportsCar2(sportsCar1); // Car part of sportsCar1 is copied to sportCar2
    sportsCar2.drive(); // Car Maker Name: , Model: , Year: 0

    SportsCar sportsCar3;
    sportsCar3 = sportsCar2;
    sportsCar3.drive();


    return 0;
}
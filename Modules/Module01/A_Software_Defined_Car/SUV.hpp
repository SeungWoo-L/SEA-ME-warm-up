#ifndef __SUV_HPP__
#define __SUV_HPP__

#include "Car.hpp"

class SUV : virtual public Car{
private:
    int Capacity;

public:

    void drive() const override{
        std::cout << "SUV has more human capacity" << std::endl;
    }
    
    SUV();
    SUV(const std::string& maker, const std::string& model, int year, int speed, int capacity);
    SUV(const SUV& suv_ref, int capacity);
    SUV& operator=(const SUV& suv_ref);
    ~SUV();
    

    void displaySUVInfo() const;

    int GetCapacity() const;


};



#endif
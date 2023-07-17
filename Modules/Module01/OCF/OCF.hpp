#ifndef __OCF_HPP__
#define __OCF_HPP__

#include<iostream>
#include<string>


class Car{

private:

    std::string Cars_Name;    // make it private and Getter Func , Setter Func
    int speed;
public:
    Car(const std::string& Name, int Speed); // Constructor
    Car(const Car& car);
    Car &operator = (const Car &car);
    ~Car();                            // Destructor




    // std::string Get_Name(){return Cars_Name;}
    // int Get_Speed(){return speed;}
    // std::string Set_Name(std::string Cars_Name){this->Cars_Name = Cars_Name;}
    // std::string Set_Name(int speed){this->speed = speed;}
    



    void printCarDetails() const;

};

#endif
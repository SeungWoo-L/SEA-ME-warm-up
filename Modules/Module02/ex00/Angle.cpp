#include "Angle.hpp"

Angle::Angle(){
    angle = 0;
}


void Angle::SetAngle(int NewAngle){
   // std::cout << "Now Your Car Angle set to " << NewAngle << std::endl;
    angle = NewAngle;
}

int Angle::GetAngle() const{
   // std::cout << "Your Steering Angle is " ;
    return angle;
}

Angle::~Angle(){
    std::cout << "Destructor Called" << std::endl;
}



#include "Speed.hpp"

Speed::Speed(){
    speed = 0;
}


void Speed::SetSpeed(int newSpeed){
   // std::cout << "Now Your Car Speed is Set to " << newSpeed << std::endl;
    speed = newSpeed;
}

int Speed::GetSpeed() const{
  //  std::cout << "Your Car Speed is : " ;
    return speed;
   
}

Speed::~Speed(){
    std::cout << "Destructor Called" << std::endl;
}
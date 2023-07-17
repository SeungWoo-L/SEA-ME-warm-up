#include"SportsCar.hpp"



SportsCar::SportsCar(const Car&ref, const int top_speed):Car(ref)
{
    std::cout << "Basic SportsCar Constructor Called \n\n";

    this-> top_speed = top_speed;
}



SportsCar::SportsCar(const SportsCar& sportscar_ref):Car(sportscar_ref){
    std::cout << "Copy SportsCar Constructor Called \n\n";
    this-> top_speed = sportscar_ref.top_speed;
}


SportsCar& SportsCar::operator = (const SportsCar &sportscar_ref){

       std::cout<<"Copy Assignment SportsCar Constructor Called \n\n";


        if (this == &sportscar_ref) {
            return *this;
        }
        Car::operator=(sportscar_ref); // Call base class assignment operator
        
        this-> top_speed = sportscar_ref.top_speed;

        return *this;
}

SportsCar::~SportsCar() {
    std::cout << "Destructor Called\n";
}


void SportsCar::drive() const{
    std::cout << "Car Maker Name: " << this-> Car_Maker << ", Model: " << this-> Car_Model 
    <<  ", Year: "  << this->Car_Year <<  " SportsCar Top Speed: " << top_speed << std::endl <<std::endl;
   

}
 
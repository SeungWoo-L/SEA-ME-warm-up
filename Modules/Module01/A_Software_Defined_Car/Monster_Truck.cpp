#include "Monster_Truck.hpp"
# include <exception>

MonsterTruck::MonsterTruck() : Sports_Car(), TRUCK(), monsterMode("Sports_mode") {}

MonsterTruck::MonsterTruck(const std::string& maker, const std::string& model, int year, int speed, int top_speed, const std::string& mode)
    : Car(maker, model, year, speed), Sports_Car(), monsterMode(mode) {
  
    Sports_Car::top_speed = top_speed;
    Change_to_Monster(mode);
}


MonsterTruck::MonsterTruck(const std::string& maker, const std::string& model, int year, int speed, double load, const std::string& mode)
    : Car(maker, model, year, speed), TRUCK(), monsterMode(mode) {
  

    TRUCK::Load = load;
    Change_to_Monster(mode);
}

MonsterTruck::MonsterTruck(const std::string& maker, const std::string& model, int year, int speed,int top_speed, double load, const std::string& mode)
    : Car(maker, model, year, speed), Sports_Car(), TRUCK(), monsterMode(mode) {
 
    Sports_Car::top_speed = top_speed;
    TRUCK::Load = load;
    Change_to_Monster(mode);
}

void MonsterTruck::Change_to_Monster(const std::string& mode) {
    if (mode == "S" || mode == "s") {
        monsterMode = "Sports_mode";
        displayCarInfo();
        GetTopSpeed();
        displayMonsterTruckInfo();
        // maker, model, year, speed topspeed, , Mostermode
    } else if (mode == "T" || mode == "t") {
        monsterMode = "Truck_mode"; 
        displayCarInfo();
        getTruckLoadAmount();
        displayMonsterTruckInfo();
        // maker, model, year, speed, load , Monstermode
    } else if (mode == "H" || mode == "h") {
        monsterMode = "Hybrid mode";
        displayCarInfo();
        GetTopSpeed();
        getTruckLoadAmount();
        displayMonsterTruckInfo();
        //maker, model, year, speed, topspeed, load , Monstermode
    } else {
        monsterMode = "Invalid_Mode";
    }
}

void MonsterTruck::displayMonsterTruckInfo() const { 

    std::cout << "Monster Mode: " << monsterMode << std::endl;
}
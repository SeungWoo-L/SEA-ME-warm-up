#ifndef __MONSTER_TRUCK_HPP__
#define __MONSTER_TRUCK_HPP__


#include "Sports_Car.hpp"
#include "Truck.hpp"


class MonsterTruck : virtual public Car , public Sports_Car, public TRUCK {
private:
    std::string monsterMode;

public:

    void drive() const override {
        std::cout << "Monster is Ready" << std::endl;
    }
    MonsterTruck();
    MonsterTruck(const std::string& maker, const std::string& model, int year, int speed, int top_speed, const std::string& mode);
    MonsterTruck(const std::string& maker, const std::string& model, int year, int speed, double load, const std::string& mode);
    MonsterTruck(const std::string& maker, const std::string& model, int year, int speed, int top_speed, double load, const std::string& mode);
    void Change_to_Monster(const std::string& mode);
    void displayMonsterTruckInfo() const;
};

#endif 



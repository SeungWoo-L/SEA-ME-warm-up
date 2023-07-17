#include <iostream>
#include <string>
#include <limits>

#include "Sports_Car.hpp"
#include "SUV.hpp"
#include "Truck.hpp"
#include "Monster_Truck.hpp"

// 함수 원형 선언
void inputSportsCarSpecs();
void inputSUVSpecs();
void inputTruckSpecs();
void inputMonsterTruckSpecs();

int main() {
again:
    std::cout << "Choose a car mode (sports, suv, truck, monster): ";
    std::string mode;
    std::cin >> mode;

    if (mode == "sports") {
        inputSportsCarSpecs();
    } else if (mode == "suv") {
        inputSUVSpecs();
    } else if (mode == "truck") {
        inputTruckSpecs();
    } else if (mode == "monster") {
        inputMonsterTruckSpecs();
    } else {
        std::cout << "Invalid mode." << std::endl;
        goto again;
    }

    return 0;
}

// 스포츠카 스펙 입력 함수
void inputSportsCarSpecs() {
    std::string maker, model;
    int year, speed, top_speed;
    std::string mode;

    std::cout << "Enter sports car maker: ";
    std::cin >> maker;
    std::cout << "Enter sports car model: ";
    std::cin >> model;
    while(true){
        std::cout << "Enter sports car year: ";
        std::cin >> year;
        
        if(year <=0  || std::cin.fail()){
            std::cout << "Invaild year, Please enter a positive numeric value" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }     
    }

    while (true)
    {
        std::cout << "Enter sports car speed: ";
        std::cin >> speed;

        if(speed <=0 || std::cin.fail()){
            std::cout << "Invalid speed. Please enter a positive numeric value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;

        }
    }
    

     while (true) {
        std::cout << "Enter sports car top speed: ";
        std::cin >> top_speed;

        if (top_speed <= 0 || std::cin.fail()) {
            std::cout << "Invalid top speed. Please enter a positive numeric value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // while(true){

    std::cout << "Enter sports car mode:(E : Echo, S : Sports) ";
    std::cin >> mode;
    // if(mode != "E" || mode != "e" || mode != "S" || mode != "s"){
    //     std::cout << "Invaild mode, Mode set to Echo(Default) Mode" << std::endl;
    //     break;
    //     }
    //     else{
    //         break;
    //     }
    // }

    Sports_Car sports_Car(maker, model, year , speed , top_speed, mode);
    std::cout << std::endl;
    sports_Car.displaySportsCarInfo();
  
}

// SUV 스펙 입력 함수
void inputSUVSpecs() {
    std::string maker, model;
    int year, speed;
    int capacity;

    std::cout << "Enter SUV maker: ";
    std::cin >> maker;
    std::cout << "Enter SUV model: ";
    std::cin >> model;
    while (true) {
        std::cout << "Enter SUV cars year: ";
        std::cin >> year;

        if (year <= 0 || std::cin.fail()) {
            std::cout << "Invalid year. Please enter a positive numeric value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    while (true) {
        std::cout << "Enter SUV car speed: ";
        std::cin >> speed;

        if (speed <= 0 || std::cin.fail()) {
            std::cout << "Invalid speed. Please enter a positive numeric value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    while (true) {
        std::cout << "Enter SUV capacity: ";
        std::cin >> capacity;

        if (capacity <= 0 || std::cin.fail()) {
            std::cout << "Invalid capacity. Please enter a positive numeric value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }


    SUV suv(maker, model, year , speed , capacity);
    std::cout << std::endl;
    suv.displaySUVInfo();

}

// 트럭 스펙 입력 함수
void inputTruckSpecs() {
    std::string maker, model;
    int year, speed;
    double load;

    std::cout << "Enter truck maker: ";
    std::cin >> maker;
    std::cout << "Enter truck model: ";
    std::cin >> model;
    while (true) {
        std::cout << "Enter Truck car year: ";
        std::cin >> year;

        if (year <= 0 || std::cin.fail()) {
            std::cout << "Invalid year. Please enter a positive numeric value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    while (true) {
        std::cout << "Enter Truck speed: ";
        std::cin >> speed;

        if (speed <= 0 || std::cin.fail()) {
            std::cout << "Invalid speed. Please enter a positive numeric value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    while (true) {
        std::cout << "Enter Truck Load amount: ";
        std::cin >> load;

        if (load <= 0 || std::cin.fail()) {
            std::cout << "Invalid Load amount. Please enter a positive numeric value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }




    TRUCK truck(maker, model, year , speed , load);
    std::cout << std::endl;
    truck.displayTruckInfo();
    
 
    
}

// 몬스터 트럭 스펙 입력 함수
void inputMonsterTruckSpecs() {
    std::string maker, model;
    int year, speed, top_speed;
    double load;
    std::string mode;

    std::cout << "Enter monster truck maker: ";
    std::cin >> maker;

    std::cout << "Enter monster truck model: ";
    std::cin >> model;

    while (true) {
        std::cout << "Enter Monster Truck car year: ";
        std::cin >> year;

        if (year <= 0 || std::cin.fail()) {
            std::cout << "Invalid year. Please enter a positive numeric value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    while (true) {
        std::cout << "Enter Monster Truck speed: ";
        std::cin >> speed;

        if (speed <= 0 || std::cin.fail()) {
            std::cout << "Invalid speed. Please enter a positive numeric value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
re1:
    std::cout << "Enter monster Truck mode (S : Sport, T : Truck , H : Hybrid): ";
    std::cin >> mode; 

    if(mode =="S" || mode == "s"){
         while (true) {
            std::cout << "Enter Monster Truck top_speed: ";
            std::cin >> top_speed;

        if (top_speed <= 0 || std::cin.fail()) {
            std::cout << "Invalid Top_Speed. Please enter a positive numeric value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
            }
        }

        std::cout<<std::endl;
        MonsterTruck monster(maker, model, year, speed, top_speed, mode);
        std::cout << std::endl;
    } 
    else if(mode == "T" || mode == "t"){
        while (true) {
            std::cout << "Enter Monster Truck Load amount: ";
            std::cin >> load;

            if (load <= 0 || std::cin.fail()) {
                std::cout << "Invalid Load amount. Please enter a positive numeric value." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
        std::cout << std::endl;
        MonsterTruck monster(maker, model, year, speed, load, mode);
        std::cout << std::endl;
    

    }
    else if(mode == "H" || mode == "h"){
        while (true) {
            std::cout << "Enter Monster Truck top_speed: ";
            std::cin >> top_speed;
            
            if (top_speed <= 0 || std::cin.fail()) {
            std::cout << "Invalid Top_Speed. Please enter a positive numeric value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
                }
       }
        while (true) {
            std::cout << "Enter Monster Truck Load amount: ";
            std::cin >> load;

            if (load <= 0 || std::cin.fail()) {
                std::cout << "Invalid Load amount. Please enter a positive numeric value." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
        std::cout<<std::endl;
        MonsterTruck monster(maker, model, year, speed, top_speed, load, mode); 
        std::cout<<std::endl;
    }

    else{
        std::cout << "Please Type Right Mode" << std::endl;
        goto re1;
    }

}
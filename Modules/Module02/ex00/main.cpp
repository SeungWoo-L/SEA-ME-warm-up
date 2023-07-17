#include "Car.hpp"



int main() {
    // Generate Car class using carPtr
    Car *carPtr = new Car();
    (*carPtr).Car_Maker = "Hyundai";
    (*carPtr).Car_Model = "Avante";
    (*carPtr).Car_Year = 2022;
    (*carPtr).drive();

    carPtr -> Car_Maker = "WolfsWagen";
    carPtr -> Car_Model = "Golf";
    carPtr -> Car_Year = 2023;
    carPtr -> drive();
    // Change Speed
    carPtr->SetSpeed(100);
    // Print Speed 
    std::cout << "Car Speed is set to : " << carPtr -> GetSpeed() << std::endl;
    // Change Angle
    carPtr->SetAngle(30) ;
    // Print Angle 
    std::cout << "Car Angle is set to: " << carPtr->GetAngle() << std::endl;
    // Call drive function 
    carPtr->drive();
    // Freeing the Memory
    delete carPtr;
    std::cout << std::endl;


    Car *carPtr2 = new Car("Audi", "A6", 2020, 100, 45);
    carPtr2->drive();
    (*carPtr2).drive();
    carPtr2 -> SetSpeed(200);
    carPtr2->drive();
    carPtr2 -> SetAngle(10);
    carPtr2 ->drive();

    delete carPtr2;


    std::cout << std::endl;
    std::cout << "Old fashioned" << std::endl;
    std::cout << "=================================================================" << std::endl;
    std::cout << "Use the SmartPointer" << std::endl << std::endl;

    std::unique_ptr<Car> carPtr3 = std::make_unique<Car>();
    carPtr3 -> Car_Maker = "NewCompany";
    carPtr3 -> Car_Model = "NewModel";
    carPtr3 -> Car_Year = 2024;
    carPtr3 -> drive();

    carPtr3 -> SetSpeed(200); 
    carPtr3 -> SetAngle(90) ;

    //std::cout << carPtr3 -> GetSpeed() << std::endl;
    //std::cout << carPtr3 -> GetAngle() << std::endl; 
    carPtr3 -> drive();


    std::unique_ptr<Car> new1Ptr;
    new1Ptr = move(carPtr3);
    new1Ptr -> drive();
    // carPtr3 -> drive();

    carPtr3.reset();
    new1Ptr.reset();

    std::cout << "Unique Pointer" << std::endl;
    std::cout << "=========================================================================" << std::endl;
    std::cout << "Shared Pointer" << std::endl;


    std::shared_ptr<Car> carPtr4 = std::make_shared<Car>();

    (*carPtr4).Car_Maker = "SharedCar";
    (*carPtr4).Car_Model = "SharedModel";
    (*carPtr4).Car_Year = 1999;
    carPtr4->SetSpeed(200);
    carPtr4->SetAngle(10);
    //(*carPtr4).drive();
    carPtr4->drive();
    std::cout << carPtr4.use_count() << std::endl;

    std::shared_ptr<Car> new4Ptr = carPtr4;
    std::cout << carPtr4.use_count() << std::endl;

    new4Ptr->Car_Maker = "NewSharedCar";
    new4Ptr->Car_Model = "NewSharedModel";
    new4Ptr->Car_Year = 0;
    new4Ptr->SetSpeed(1000);
    new4Ptr->SetAngle(1000);
    new4Ptr->drive();

    carPtr4.reset();
    std::cout << new4Ptr.use_count() << std::endl;


    std::cout << "===================================================================" << std::endl;
    std::cout << "Weak Pointer" << std::endl;




    std::weak_ptr<Car> carPtr5 = std::make_shared<Car>();
    // carPtr5 -> Car_Maker = "WeakCar";
    // carPtr5 -> Car_Model = "WeakModel";
    // carPtr5 -> Car_Year = 2023;
    // carPtr5 -> SetSpeed(300);
    // carPtr5 -> SetAngle(180);
    // carPtr5 -> drive();
    // Weak Pointer Cannot access the instance directly!!

     std::weak_ptr<Car> weakPtr;

    {
        std::shared_ptr<Car> sharedPtr = std::make_shared<Car>("Hyundai", "Avante", 2022, 200, 180);
        weakPtr = sharedPtr; // 약한 참조자 생성

        std::cout << "SharedPtr use count: " << sharedPtr.use_count() << std::endl;
        std::cout << "Weak pointer use count: " << weakPtr.use_count() << std::endl;

        if (auto lockedPtr = weakPtr.lock()) { // Make the weakPtr to shared Pointer and allocate to the lockedPtr, if the scope end, weakPtr will be expired
            std::cout << "Weak pointer is valid." << std::endl;
            std::cout << "Car Maker: " << lockedPtr->Car_Maker << std::endl;
            std::cout << "Car Model: " << lockedPtr->Car_Model << std::endl;
            std::cout << "Car Year: " << lockedPtr->Car_Year << std::endl;
            std::cout << "Car Speed: " << lockedPtr->GetSpeed() << std::endl;
            std::cout << "Car Angle: " << lockedPtr->GetAngle() << std::endl;
        } else {
            std::cout << "Weak pointer is expired." << std::endl;
        }

        std::cout << "Hold on" << std::endl;
        std::cout << "sharedPtr use count: " << sharedPtr.use_count() << std::endl;
        std::cout << "Weak pointer use count: " << weakPtr.use_count() << std::endl;
    }
    //Where the WeakPtr expired!! out of scope!!
    

    if (auto lockedPtr = weakPtr.lock()) {
        std::cout << "Weak pointer is valid." << std::endl;
        std::cout << "Car Maker: " << lockedPtr->Car_Maker << std::endl;
        std::cout << "Car Model: " << lockedPtr->Car_Model << std::endl;
        std::cout << "Car Year: " << lockedPtr->Car_Year << std::endl;
        std::cout << "Car Speed: " << lockedPtr->GetSpeed() << std::endl;
        std::cout << "Car Angle: " << lockedPtr->GetAngle() << std::endl;
    } else {
        std::cout << "Weak pointer is expired." << std::endl;
    }
    

    return 0;
}
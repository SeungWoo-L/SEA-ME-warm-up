#include<string>

#include"OCF.hpp"

int main() {
    Car car0("Car0", 100);
    car0.printCarDetails();

    Car car1("Car1", 200);
    car1.printCarDetails();

    Car car2("Default", 0);
    car2.printCarDetails();
    car2 = car1; // 대입 연산자 사용하여 car1에 car2의 값을 복사

    car2.printCarDetails(); // Car Name: Car2, Speed: 200

    Car special(car1);
    special.printCarDetails();

    return 0;
}
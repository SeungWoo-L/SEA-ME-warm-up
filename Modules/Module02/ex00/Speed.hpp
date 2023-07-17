#ifndef __SPEED_HPP__
#define __SPEED_HPP__

#include<iostream>


class Speed{
protected:
    int speed;


public:
    Speed();
    ~Speed();


    void SetSpeed(int newSpeed);
    int GetSpeed() const;
};



#endif



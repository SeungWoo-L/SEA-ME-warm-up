#ifndef __ANGLE_HPP__
#define __ANGLE_HPP__

#include<iostream>


class Angle{
protected:
    int angle;


public:
    Angle();
    ~Angle();


    void SetAngle(int NewAngle);
    int GetAngle() const;
};



#endif



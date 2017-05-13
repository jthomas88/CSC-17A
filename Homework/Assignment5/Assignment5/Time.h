/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.h
 * Author: Jeff
 *
 * Created on May 5, 2017, 3:34 PM
 */

#ifndef TIME_H
#define TIME_H
#include "NumDays.h"
#include <cstdlib>
#include <string>
//using std::string;

class Time {
public:
    //Constructor
    Time();
    //Setters    
    void setMS(int);
    void setST(int);
    void setMV(int);
    void setVT(int);
    void setMU(int);
    void setUT(int);
    void setID(std::string);
    void setNa(std::string);
    //Getters
    int getMS();
    int getST();
    int getMV();
    int getVT();
    int getMU();
    int getUT();
    std::string getID();
    std::string getNa();
    NumDays operator =(const int&);
private:
    std::string idNum;
    std::string empName;
    NumDays maxSick,sickTak,
            maxVaca,vacaTak,
            maxUnpa,unpaTak;    
};

#endif /* TIME_H */


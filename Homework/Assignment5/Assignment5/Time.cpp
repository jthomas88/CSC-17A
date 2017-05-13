/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.cpp
 * Author: Jeff
 * 
 * Created on May 5, 2017, 3:34 PM
 */

#include <cstdlib>

#include "Time.h"
#include "NumDays.h"

Time::Time() {
}
void Time::setMS(int ms){
    maxSick.setHrs(ms);
}
void Time::setST(int st){
    sickTak.setHrs(st);
}
void Time::setMV(int mv){
    maxVaca.setHrs(mv);
    if(maxVaca.getHrs()>240)maxVaca.setHrs(240);
}
void Time::setVT(int vt){
    vacaTak.setHrs(vt);
}
void Time::setMU(int mu){
    maxUnpa.setHrs(mu);
}
void Time::setUT(int ut){
    unpaTak.setHrs(ut);
}
void Time::setID(std::string id){
    idNum=id;
}
void Time::setNa(std::string name){
    empName=name;
}
//Getters
int Time::getMS(){return maxSick.getDay();}
int Time::getST(){return sickTak.getDay();}
int Time::getMV(){return maxVaca.getDay();}
int Time::getVT(){return vacaTak.getDay();}
int Time::getMU(){return maxUnpa.getDay();}
int Time::getUT(){return unpaTak.getDay();}
std::string Time::getID(){return idNum;}
std::string Time::getNa(){return empName;}
//Overloaded Operators

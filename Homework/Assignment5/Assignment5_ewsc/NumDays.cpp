/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.cpp
 * Author: Jeff
 * 
 * Created on May 4, 2017, 3:13 PM
 */

#include "NumDays.h"

NumDays::NumDays() {
    hours=0;
}
//Setters
void  NumDays::setHrs(int h){
    hours=h;
}
//Getters
int   NumDays::getHrs(){return hours;}
float NumDays::getDay(){
    float days;
    days=static_cast<float>(hours)/8;
    return days;
}
//Overloaded operators
NumDays NumDays::operator + (const NumDays &right){
    NumDays temp;
    temp.hours=hours+right.hours;
    return temp;
}
NumDays NumDays::operator - (const NumDays &right){
    NumDays temp;
    temp.hours=hours-right.hours;
    return temp;
}
void NumDays::operator =(const int &right){
    NumDays temp;
    temp=right;
}
int NumDays::operator ++ (){
    //NumDays temp(hours);
    hours++;
    return this->hours;
}
int NumDays::operator -- (){
    //NumDays temp;
    hours--;
    return this->hours;    
}


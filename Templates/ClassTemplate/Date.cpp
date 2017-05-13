/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.cpp
 * Author: Jeff
 * 
 * Created on May 3, 2017, 4:26 PM
 */

//Libraries
#include "Date.h"
#include <sstream>

//Constructors/Destructors
Date::Date() {
}
Date::Date(const Date& orig) {
}
Date::~Date() {
}
//Setters
void Date::setDay(int d){
    day=d;
}
void Date::setMon(int m){
    month=m;
}
void Date::setYea(int y){
    year=y;
}
//Getters
int  Date::getDay(){return day;}
int  Date::getMon(){return month;}
int  Date::getYea(){return year;}
//Other Functions
string Date::mdy1(){
    std::stringstream date;
    date<<day<<'/'<<month<<'/'<<year;
    return date.str();
}
string Date::mdy2(){
    string mon;
    std::stringstream date;
    
    switch(month){
        case 1:
            mon=new char[sizeof("January")];
            mon="January";
            break;
        case 2:
            mon=new char[sizeof("February")];
            mon="February";
            break;
        case 3:
            mon=new char[sizeof("March")];
            mon="March";
            break;
        case 4:
            mon="April";break;
        case 5:
            mon="May";break;
        case 6:
            mon="June";break;
        case 7:
            mon="July";break;
        case 8:
            mon="August";break;
        case 9:
            mon="September";break;
        case 10:
            mon="October";break;
        case 11:
            mon="November";break;
        case 12:
            mon="December";break;     
    }
    date<<mon<<' '<<day<<", "<<year;
    return date.str();
}
string Date::dmy(){
    string mon;
    std::stringstream date;
    
    switch(month){
        case 1:
            mon=new char[sizeof("January")];
            mon="January";
            break;
        case 2:
            mon=new char[sizeof("February")];
            mon="February";
            break;
        case 3:
            mon=new char[sizeof("March")];
            mon="March";
            break;
        case 4:
            mon="April";break;
        case 5:
            mon="May";break;
        case 6:
            mon="June";break;
        case 7:
            mon="July";break;
        case 8:
            mon="August";break;
        case 9:
            mon="September";break;
        case 10:
            mon="October";break;
        case 11:
            mon="November";break;
        case 12:
            mon="December";break;     
    }
    date<<day<<' '<<mon<<' '<<year;
    return date.str();
}
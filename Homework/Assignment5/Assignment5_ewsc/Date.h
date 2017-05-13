/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: Jeff
 *
 * Created on May 3, 2017, 4:26 PM
 */

#ifndef DATE_H
#define DATE_H

#include <string>
using std::string;

class Date {
public:
    //Constructor
    Date();
    //Setters
    void setDay(int);
    void setMon(int);
    void setYea(int);
    //Getters
    int  getDay();
    int  getMon();
    int  getYea();
    string mdy1();
    string mdy2();
    string dmy();
    //Destructor
    Date(const Date& orig);
    virtual ~Date();
private:
    int month; //Month of the year
    int day;   //Day of the month
    int year;  //Year

};

#endif /* DATE_H */


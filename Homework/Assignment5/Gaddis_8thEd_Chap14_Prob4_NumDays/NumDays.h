/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.h
 * Author: Jeff
 *
 * Created on May 4, 2017, 3:13 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays{
public:
    //Constructor
    NumDays();
    //Setters
    void  setHrs(int);
    //Getters
    int   getHrs();
    float getDay();
    //Overloaded operators
    NumDays operator + (const NumDays&);
    NumDays operator - (const NumDays&);
    int     operator ++ ();
    int     operator -- ();
private:
    int hours;
};

#endif /* NUMDAYS_H */


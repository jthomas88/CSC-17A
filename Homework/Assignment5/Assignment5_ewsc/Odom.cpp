/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Odom.cpp
 * Author: Jeff
 * 
 * Created on May 8, 2017, 1:51 AM
 */

#include "Odom.h"
#include "Fuel.h"

Odom::Odom() {
    miles=0;
}
int Odom::getMile(){return miles;}
Odom Odom::operator ++(int){
    Odom temp;//(miles);
    miles++;
    if(miles>999999)miles=0;
    return temp;
}


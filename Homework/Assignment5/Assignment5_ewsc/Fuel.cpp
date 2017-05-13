/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fuel.cpp
 * Author: Jeff
 * 
 * Created on May 8, 2017, 1:51 AM
 */

#include "Fuel.h"
#include "Odom.h"

Fuel::Fuel() {
    gas=15; //Set fuel to maximum by default
}
void Fuel::setFuel(int g){
    gas=g;
}
int  Fuel::getFuel(){return gas;}
Fuel Fuel::operator ++(int n){
    Fuel temp;//(gas);
    gas++;
    return temp;
    }
Fuel Fuel::operator --(int n){
    Fuel temp;//(gas);
    gas--;
    return temp;
}
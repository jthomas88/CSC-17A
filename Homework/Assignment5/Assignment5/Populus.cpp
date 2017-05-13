/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Populus.cpp
 * Author: Jeff
 * 
 * Created on May 4, 2017, 1:50 PM
 */

#include "Populus.h"

//Constructor
Populus::Populus() {
    pop=0;
    birth=0;
    death=0;
}
//Setters
void  Populus::setPop(unsigned int p){
    pop=p;
}
void  Populus::setBR(unsigned int b){
    birth=b;
}
void  Populus::setDR(unsigned int d){
    death=d;
}
//Getters
int   Populus::getPop(){return pop;}
int   Populus::getBR(){return birth;}
int   Populus::getDR(){return death;}
//Calculators
float Populus::calcCR(unsigned int p,unsigned int c){
    float cr;
    cr=static_cast<float>(c)/p;
    return cr;
}


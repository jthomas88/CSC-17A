/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProdWkr.cpp
 * Author: Jeff
 * 
 * Created on May 9, 2017, 10:05 AM
 */

#include "ProdWkr.h"
#include "Employee.h"

ProdWkr::ProdWkr() {
    shift=0;
    pay=0.00f;
}
void ProdWkr::setShif(bool s){
    shift=s;
}
void ProdWkr::setPay(float p){
    pay=p;
}

bool  ProdWkr::getShif(){return shift;}
float ProdWkr::getPay(){return pay;}


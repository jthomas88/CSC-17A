/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DivSale.cpp
 * Author: Jeff
 * 
 * Created on May 8, 2017, 12:52 AM
 */

#include "DivSale.h"

DivSale::DivSale() {
    //qSale={};
    tSale=0.0f;
}

void  DivSale::setQ(float q,int n){
    qSale[n]=q;
    tSale+=q;
}
float DivSale::getQ(int q){return qSale[q];}
float DivSale::getT(){return tSale;}

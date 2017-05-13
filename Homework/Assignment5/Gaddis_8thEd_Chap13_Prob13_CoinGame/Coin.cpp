/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coin.cpp
 * Author: Jeff
 * 
 * Created on May 4, 2017, 2:15 PM
 */

#include "Coin.h"
#include <cstdlib>

Coin::Coin() {
    isHeads=1;
    value=0;
}
bool Coin::toss(){
    std::rand()%2==1?isHeads=1:isHeads=0;
    return isHeads;
}
void Coin::setVal(int v){
    value=v;
}
int  Coin::getVal(){return value;}

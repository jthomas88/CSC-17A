/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventory.cpp
 * Author: Jeff
 * 
 * Created on May 3, 2017, 4:26 PM
 */

//Libraries
#include "Inventory.h"
#include <sstream>

//Constructors/Destructors
Inventory::Inventory() {
}

//Setters
void Inventory::setItem(int i){
    item=i;
}
void Inventory::setQty(int q){
    qty=q;
}
void Inventory::setCost(float c){
    cost=c;
}
void Inventory::setTtl(){
    total=cost*qty;
}
//Getters
int   Inventory::getItem(){return item;}
int   Inventory::getQty(){return qty;}
float Inventory::getCost(){return cost;}
float Inventory::getTtl(){return total;}
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

#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
using std::string;

class Inventory{
public:
    //Constructor
    Inventory();
    //Setters
    void setItem(int);
    void setQty(int);
    void setCost(float);
    void setTtl();
    //Getters
    int   getItem();
    int   getQty();
    float getCost();
    float getTtl();
private:
    int   item;  //Item number
    int   qty;   //Item quantity
    float cost;  //Cost per unit
    float total; //Total cost

};

#endif /* INVENTORY_H */


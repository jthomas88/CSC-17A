/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fuel.h
 * Author: Jeff
 *
 * Created on May 8, 2017, 1:51 AM
 */

#ifndef FUEL_H
#define FUEL_H

class Fuel {
public:
    Fuel();
    void setFuel(int);
    int  getFuel();
    Fuel operator ++(int);
    Fuel operator --(int);
private:
    int gas;
};

#endif /* FUEL_H */


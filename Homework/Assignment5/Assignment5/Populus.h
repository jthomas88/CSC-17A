/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Populus.h
 * Author: Jeff
 *
 * Created on May 4, 2017, 1:50 PM
 */

#ifndef POPULUS_H
#define POPULUS_H

class Populus {
public:
    //Constructor
    Populus();
    //Setters
    void  setPop(unsigned int);
    void  setBR(unsigned int);
    void  setDR(unsigned int);
    //Getters
    int   getPop();
    int   getBR();
    int   getDR();
    //Calculators
    float calcCR(unsigned int,unsigned int);
private:
    unsigned int pop;   //Total population
    unsigned int birth; //Total births
    unsigned int death; //Total deaths
};

#endif /* POPULUS_H */


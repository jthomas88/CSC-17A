/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lemming.h
 * Author: Jeff
 *
 * Created on April 6, 2017, 11:07 PM
 */

#ifndef LEMMING_H
#define LEMMING_H

struct Lemming{
    //Properties
    int   size;    //Number of lemmings in army
    char  gift;    //Code for chosen gift
    float dodge;   //Dodge rate
    //Arrays
    bool  *isDead; //Check if lemming in array is dead
    //Increments
    int defeat;
    int squad;
};

#endif /* LEMMING_H */


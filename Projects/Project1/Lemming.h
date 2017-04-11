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
    int   size;  //Number of lemmings in army
    int   ppL;   //ppL (Power Per Lemming)
    float dodge; //Dodge rate
    int   *army; //Army of lemmings
};

#endif /* LEMMING_H */


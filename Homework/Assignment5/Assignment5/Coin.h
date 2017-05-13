/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coin.h
 * Author: Jeff
 *
 * Created on May 4, 2017, 2:15 PM
 */

#ifndef COIN_H
#define COIN_H

class Coin {
public:
    Coin();
    bool toss();
    void setVal(int);
    int  getVal();
private:
    bool isHeads;
    int  value;
    
};

#endif /* COIN_H */


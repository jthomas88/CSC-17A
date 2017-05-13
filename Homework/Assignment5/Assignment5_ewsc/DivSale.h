/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DivSale.h
 * Author: Jeff
 *
 * Created on May 8, 2017, 12:52 AM
 */

#ifndef DIVSALE_H
#define DIVSALE_H

class DivSale {
public:
    DivSale();
    void  setQ(float,int);
    float getQ(int);
    float getT();
private:
    float qSale[4];
    float tSale;
};

#endif /* DIVSALE_H */


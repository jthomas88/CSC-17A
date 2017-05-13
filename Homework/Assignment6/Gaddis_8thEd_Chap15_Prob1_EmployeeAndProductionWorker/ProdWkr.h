/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProdWkr.h
 * Author: Jeff
 *
 * Created on May 9, 2017, 10:05 AM
 */

#ifndef PRODWKR_H
#define PRODWKR_H
#include "Employee.h"

class ProdWkr:public Employee {
public:
    ProdWkr();
    
    void setShif(bool);
    void setPay(float);
    
    bool  getShif();
    float getPay();
private:
    bool  shift;
    float pay;
};

#endif /* PRODWKR_H */


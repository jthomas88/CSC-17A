/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CrdCard.h
 * Author: Jeff
 *
 * Created on March 12, 2017, 5:58 PM
 */

#ifndef CRDCARD_H
#define CRDCARD_H

struct CrdCard{
        string ccCom;    //Credit card company
        int stDig;    //Starting digits
        char ccNum[]; //Credit card number
    };


#endif /* CRDCARD_H */


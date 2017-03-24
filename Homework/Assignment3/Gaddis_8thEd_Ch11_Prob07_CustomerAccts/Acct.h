/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Accts.h
 * Author: Jeff
 *
 * Created on March 23, 2017, 4:37 PM
 */

#ifndef ACCTS_H
#define ACCTS_H

struct Acct{
    string name,
           addr;
    char   phon[];
    float  blnc;
    string paid;
    bool   isFill=0;
};

#endif /* ACCTS_H */


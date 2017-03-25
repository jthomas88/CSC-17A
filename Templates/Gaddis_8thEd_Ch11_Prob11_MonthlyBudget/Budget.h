/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Budget.h
 * Author: Jeff
 *
 * Created on March 24, 2017, 11:39 AM
 */

#ifndef BUDGET_H
#define BUDGET_H

struct Budg{
    float hous, //Housing
          util, //Utilities
          hexp, //Household expenses
          trns, //Transportation
          food, //Food
          meds, //Medical
          insr, //Insurance
          entr, //Entertainment
          clot, //Clothing
          misc; //Miscellaneous
    float totl=0.00f; //Total monthly spending
};

#endif /* BUDGET_H */


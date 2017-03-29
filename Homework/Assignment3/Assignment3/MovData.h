/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MovData.h
 * Author: Jeff
 *
 * Created on March 22, 2017, 5:05 PM
 */

#ifndef MOVDATA_H
#define MOVDATA_H

struct MovData{
    string title; //Movie title
    string drctr; //Director
    int    year;  //Year released
    short  runtm; //Runtime in minutes
    short  bdgt;  //Movie Budget (in millions)
    short  grss;  //Gross Earnings (in millions)
};

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* MOVDATA_H */


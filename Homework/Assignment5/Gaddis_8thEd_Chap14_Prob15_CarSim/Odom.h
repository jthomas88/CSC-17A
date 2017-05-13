/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Odom.h
 * Author: Jeff
 *
 * Created on May 8, 2017, 1:51 AM
 */

#ifndef ODOM_H
#define ODOM_H


class Odom {
public:
    Odom();
    int getMile();
    Odom operator ++(int);
private:
    int miles;
    const int MPG=24;
};

#endif /* ODOM_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: Jeff
 *
 * Created on May 4, 2017, 1:28 PM
 */

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
    Circle();
    void  setRad(float);
    float getRadi();
    float getDiam();
    float getArea();
    float getCirc();
private:
    float radius;
    float pi=3.14159;
};

#endif /* CIRCLE_H */


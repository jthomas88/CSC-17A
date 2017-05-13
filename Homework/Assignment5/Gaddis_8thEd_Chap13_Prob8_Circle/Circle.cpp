/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.cpp
 * Author: Jeff
 * 
 * Created on May 4, 2017, 1:28 PM
 */

#include "Circle.h"

Circle::Circle() {
    radius=0.0f;
}

void  Circle::setRad(float r){
    radius=r;
}
float Circle::getRadi(){return radius;}
float Circle::getDiam(){
    float d;
    d=radius*2;
    return d;
}
float Circle::getArea(){
    float a;
    a=pi*radius*radius;
    return a;
}
float Circle::getCirc(){
    float c;
    c=2*pi*radius;
    return c;
}

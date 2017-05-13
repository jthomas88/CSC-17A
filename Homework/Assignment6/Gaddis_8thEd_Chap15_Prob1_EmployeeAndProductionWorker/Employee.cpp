/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.cpp
 * Author: Jeff
 * 
 * Created on May 9, 2017, 10:05 AM
 */

#include <string>
#include "Employee.h"


Employee::Employee() {
    name="Default";
    idNum="000000";
    hireDt={'1','2','1','2','1','2'}
}
void Employee::setName(std::string n){
    name=n;
}
void Employee::setID(std::string i){
    idNum=i;
}
void Employee::setHire(char *d){
    d=new char[6];
    hireDt;
    delete[]d;
}

std::string Employee::getName(){return name;}
std::string Employee::getID(){return idNum;}
char* Employee::getHire(){return hireDt;}
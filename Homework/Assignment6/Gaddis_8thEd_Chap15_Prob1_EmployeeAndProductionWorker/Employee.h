/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: Jeff
 *
 * Created on May 9, 2017, 10:05 AM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
public:
    Employee();
    
    void setName(std::string);
    void setID(std::string);
    void setHire(char*);
    
    std::string getName();
    std::string getID();
    char* getHire();
private:
    std::string name;
    std::string idNum;
    char hireDt[6];
};

#endif /* EMPLOYEE_H */


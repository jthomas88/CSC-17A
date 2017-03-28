/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Student.h
 * Author: Jeff
 *
 * Created on March 27, 2017, 7:54 PM
 */

#ifndef STUDENT_H
#define STUDENT_H

struct Student{
    std::string name;
    int         stuID;
    int         *tests;
    int         tstSize;
    float       avg;
    char        grade;
};

#endif /* STUDENT_H */


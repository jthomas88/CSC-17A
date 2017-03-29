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
    std::string name;    //Student name 
    int         stuID;   //Student ID
    int         *tests;  //Array of test scores
    int         tstSize; //Number of test scores
    float       avg;     //Average test score
    char        grade;   //Letter Grade
};

#endif /* STUDENT_H */


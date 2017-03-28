/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>
#include <ctime>

using namespace std; //Namespace used in system library

//User libraries
#include "Student.h"

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declare random size of dynamic array
    int size=rand()%5+5;
    
    //Allocate Memory
    Student *array;
    array=new Student[size];
    
    //Input Values
    
    //Process Values
    
    //Exit program
    return 0;
}

void prntAry()

Student 
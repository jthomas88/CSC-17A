/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
int *doSomething(int x,int y);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    int *x,*y;
    
    //Test Function
    doSomething(x,y);
    
    //Exit program
    return 0;
}

int doSomething(int *x, int *y){ 
    int temp=x; 
    x=y*10; 
    y=temp*10; 
    return x+y; 
}   
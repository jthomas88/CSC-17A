/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random generator
#include <ctime>     //Random seed

using namespace std; //Namespace used in system library

//User libraries
#include "CrdCard.h"

//Global constants

//Function prototypes
void genCC(CrdCard,char []);
void flipDig(char []);
bool validCC(char[]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Intialize random seed
    srand(time(0));
    
    //Declare Arrays
    char cc[]; //Credid card array
    
    //Exit program
    return 0;
}
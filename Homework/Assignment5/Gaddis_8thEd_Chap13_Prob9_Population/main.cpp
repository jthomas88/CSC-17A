/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random gen
#include <ctime>     //Random seed
#include <iomanip>   //Output format

using namespace std; //Namespace used in system library

//User libraries
#include "Populus.h"
//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    //Declaration of variables
    Populus populus;
    unsigned int birth,death,pop;     
    //Construct object
    Populus();    
    //Set Values
    pop=rand()%50000;
    birth=rand()%pop;
    death=rand()%pop;
    populus.setPop(pop);
    populus.setBR(birth);
    populus.setDR(death);
    //Calculate rates
    cout<<"Total population : "<<populus.getPop()<<endl<<endl;
    cout<<"Total births     : "<<populus.getBR()<<endl;
    cout<<"Annual birth rate: "<<fixed<<setprecision(2)
        <<populus.calcCR(pop,birth)<<endl<<endl;
    cout<<"Total deaths     : "<<populus.getDR()<<endl;
    cout<<"Annual death rate: "<<fixed<<setprecision(2)
        <<populus.calcCR(pop,death)<<endl;
    
    //Exit program
    return 0;
}
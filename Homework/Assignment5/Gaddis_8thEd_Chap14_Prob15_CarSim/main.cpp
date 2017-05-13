/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>

#include "Fuel.h"  //Input/Output objects
#include "Odom.h"

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    const int MPG=24;
    //Declaration of variables
    Odom odom;
    Fuel fuel;
    
    do{
        cout<<"Odometer  : "<<odom.getMile()<<endl;
        cout<<"Fuel Gauge: "<<fuel.getFuel()<<endl;
        odom++;
        if(odom.getMile()%MPG==0)fuel--;
        cout<<endl;
    }while(fuel.getFuel()>=0);
    
    
    //Input Values
    
    //Process Values
    
    //Exit program
    return 0;
}
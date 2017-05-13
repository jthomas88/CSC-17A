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
#include "Date.h"

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare object
    Date date;
    //Declare Variables
    int d;
    //Input day
    do{
        cout<<"Enter the day: ";
        cin>>d;
        cout<<endl;
    }while(d>31||d<1);
    date.setDay(d);
    //Input month
    int m;
    do{
        cout<<"Enter the month: ";
        cin>>m;
        cout<<endl;
    }while(m>12||m<1);
    date.setMon(m);
    //Input year
    int y;
    do{
        cout<<"Enter the year: ";
        cin>>y;
        cout<<endl;
    }while(y<1000);
    date.setYea(y);
    //Output results
    cout<<date.mdy1()<<endl;
    cout<<date.mdy2()<<endl;
    cout<<date.dmy()<<endl;
    
    //Exit program
    return 0;
}
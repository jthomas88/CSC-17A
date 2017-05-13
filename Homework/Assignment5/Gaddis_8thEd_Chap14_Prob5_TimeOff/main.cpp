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
#include "NumDays.h"
#include "Time.h"
//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    Time emp;
    int hrs;
    string n;
    
    //Prompt for input (Employee 1)
    cout<<"Enter employee's name: ";
    cin>>n;
    emp.setNa(n);
    cout<<endl;
    
    cout<<"Enter "<<emp.getNa()<<"'s ID number: ";
    cin>>n;
    emp.setID(n);
    cout<<endl;
    
    do{
        cout<<"Enter sick hours: ";
        cin>>hrs;
        emp.setMS(hrs);
    }while(hrs<0);
    
    do{
        cout<<"Enter vacation hours: ";
        cin>>hrs;
        emp.setMV(hrs);
    }while(hrs<0||hrs>240);
    
    do{
        cout<<"Enter unpaid hours: ";
        cin>>hrs;
        emp.setMU(hrs);
    }while(hrs<0);
    
    cout<<"Name: "<<emp.getNa()<<endl;
    cout<<"ID #: "<<emp.getID()<<endl;
    cout<<"Sick days    : "<<emp.getMS()<<endl;
    cout<<"Vacation days: "<<emp.getMV()<<endl;
    cout<<"Unpaid days  : "<<emp.getMU()<<endl;
    
    //Input Values
    
    //Process Values
    
    //Exit program
    return 0;
}
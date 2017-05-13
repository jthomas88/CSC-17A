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
    //Declare constants
    const int SICK=8;  //Hours of sick leave earned per month
    const int VACA=12; //Hours of vacation earned per month
    //Declaration of variables
    Time emp;
    int mon;
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
        cout<<"Enter number of months worked: ";
        cin>>mon;
        if(mon<0)cout<<"Months must be a positive number."<<endl;
    }while(mon<0);
    
    emp.setMV(mon*VACA);
    emp.setMS(mon*SICK);
    
    cout<<"Name: "<<emp.getNa()<<endl;
    cout<<"ID #: "<<emp.getID()<<endl;
    cout<<"Sick days    : "<<emp.getMS()<<endl;
    cout<<"Vacation days: "<<emp.getMV()<<endl;
    
    //Input Values
    
    //Process Values
    
    //Exit program
    return 0;
}
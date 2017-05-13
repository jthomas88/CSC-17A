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
//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    NumDays emp1,emp2;
    int hrs;
    
    //Prompt for input (Employee 1)
    cout<<"Enter the number of hours employee 1 worked this week: ";
    cin>>hrs;
    emp1.setHrs(hrs);
    
    //Prompt for input (Employee 2)
    cout<<"Enter the number of hours employee 2 worked this week: ";
    cin>>hrs;
    emp2.setHrs(hrs);
    
    cout<<endl;
    
    //Output hours
    cout<<"Employee 1 hours worked: "<<emp1.getHrs()<<endl;
    cout<<"Employee 1 days worked : "<<emp1.getDay()<<endl;
    cout<<endl;
    cout<<"Employee 2 hours worked: "<<emp2.getHrs()<<endl;
    cout<<"Employee 2 days worked : "<<emp2.getDay()<<endl;
    cout<<endl;
    //Showcase overloaded operators
    ++(emp1);
    --(emp2);
    cout<<"Employee 1 hours worked: "<<emp1.getHrs()<<endl;
    cout<<"Employee 1 days worked : "<<emp1.getDay()<<endl;
    cout<<endl;
    cout<<"Employee 2 hours worked: "<<emp2.getHrs()<<endl;
    cout<<"Employee 2 days worked : "<<emp2.getDay()<<endl;
    cout<<endl;
    cout<<"Sum of hours       : "<<(emp1+emp2).getHrs()<<endl;
    cout<<"Difference of hours: "<<(emp1-emp2).getHrs()<<endl;
    //Input Values
    
    //Process Values
    
    //Exit program
    return 0;
}
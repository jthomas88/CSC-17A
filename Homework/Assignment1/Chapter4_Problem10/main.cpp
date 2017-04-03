/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on March 06, 2017, 10:30 PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
bool isLeap(short);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare Variables
    int  mn;  //User inputted month
    short yr; //User inputted year
    
    //Explain Program
    cout<<"This program will determine how many days are in a given year.\n";
    
    //Prompt for input
    cout<<"Enter a month (1-12): ";
    cin>>mn;
    cout<<"Enter a year: ";
    cin>>yr;
    
    //Output number of days
    switch(mn){
        //All months with 31 days
        case 1:case 3:case 5:case 7:case 8:
        case 10:case 12: cout<<"31 days";break;
        //All months with 30 days
        case 4:case 6:case 9:case 11: cout<<"30 days";break;
        //Adds extra day to Feb is bool function is true
        case 2:cout<<28+isLeap(yr)<<" days.";
    }   
    
    //Exit program
    return 0;
}

//Determines if given year is leap year
bool isLeap(short yr){
    if((yr%4==0&&yr%100!=0)||(yr%400==0&&yr%100==0)){
        return 1;
    }
    else{
        return 0;
    }
}
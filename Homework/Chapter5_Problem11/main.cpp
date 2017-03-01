/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Format output

using namespace std; //Namespace used in system library

//User libraries

//Global constants
int PERCENT=100; //Percent conversion

//Function prototypes
int popChng(int,int,float);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare Variables
    int   start,   //User declared start population
          days;    //User declared number of days  
    float increas; //User declared increase percentage
    
    //Prompt user for input
    do{
        cout<<"Enter the starting population: ";
        cin>>start;
        if(start<2)cout<<endl<<"Invalid. "<<
        "Starting population must be 2 or greater.";
    }while(start<2); //Check for valid input    
    cout<<endl;
    
    do{
        cout<<"Enter the population increase percentage: ";
        cin>>increas;
        if(increas<0)cout<<endl<<"Invalid. "<<
        "Population increase cannot be negative.";
    }while(increas<0); //Check for valid input
    cout<<endl;
    
    do{
        cout<<"Enter the number of days to observe: ";
        cin>>days;
        if(days<1)cout<<endl<<"Invalid. "<<
        "Number of days must be at least 1.";
    }while(days<1); //Check for valid input    
    cout<<endl;
    
    //Call population change function
    cout<<popChng(start,days,increas);    
    
    //Exit program
    return 0;
}

int popChng(int start,int days,float increas){
    int newPop=start; //Set new population to starting population
    float incRate=increas/PERCENT; //Set percentage to proper placing
    for(int i=0;i<days;i++){
        newPop+=(newPop*incRate); //Add population increase to total
        cout<<"Day "<<i+1<<": "<<fixed<<newPop<<endl; //Output daily data
    }
    cout<<"Final Population: ";
    return newPop; //Return final result
}
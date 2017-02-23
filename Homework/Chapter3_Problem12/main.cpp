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
void fillAry(short[],int); //Fills array with values 0 - 99
void prntAry(short[],int); //Outputs array

int cToF(short);           //Celsius-to-Fahrenheit conversion

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare Constants
    const short SIZE=100;
    
    //Declare Arrays
    short cel[SIZE], //Celsius array 0-100 degrees
          frn[SIZE]; //Parallel fahrenheit array
    
    
    //Fill cel array
    fillAry(cel,SIZE);
    
    //Output Celsius Array
    cout<<"Celsius: ";
    prntAry(cel,SIZE);
    cout<<endl;
    
    //Convert to Fahrenheit
    for(int i=0;i<SIZE;i++){
        frn[i]=cToF(cel[i]);
    }
    
    //Output Fahrenheit array
    cout<<"Fahrenheit: ";
    prntAry(frn,SIZE);
    cout<<endl<<endl;
    
    //Exit program
    return 0;
}

void fillAry(short a[],int n){
    for(int i=0;i<n;i++){
        a[i]=i;
    }
}

void prntAry(short a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
}

int cToF(short cel){
    int frn;
    frn=(cel*9)/5+32;
    return frn;
}
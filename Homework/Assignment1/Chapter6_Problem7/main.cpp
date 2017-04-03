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
void fillAry(short[],int); //Fills array with values 0 - 99
void prntAry(short[],int); //Outputs array

int fToC(short);           //Fahrenheit-to-Celcius conversion

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare Constants
    const short SIZE=20;
    
    //Declare Arrays
    short frn[SIZE], //Fahrenheit array 0-20 degrees
          cel[SIZE]; //Parallel Celsius array
    
    
    //Fill frn array
    fillAry(frn,SIZE);
    
    //Output Fahrenheit Array
    cout<<"Fahrenheit: ";
    prntAry(frn,SIZE);
    cout<<endl;
    
    //Convert to Celsius
    for(int i=0;i<SIZE;i++){
        cel[i]=fToC(frn[i]);
    }
    
    //Output Celsius array
    cout<<"Celsius: ";
    prntAry(cel,SIZE);
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

int fToC(short frn){
    int cel;
    cel=(frn-32)*5/9;
    return cel;
}
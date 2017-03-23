/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <cstdlib>   //Random generator
#include <ctime>     //Random seed
#include <iostream>  //Input/Output objects
#include <iomanip>   //Format output

using namespace std; //Namespace used in system library

//User libraries
#include "Weather.h"

//Global constants
//enum Months {JAN,FEB,MAR,APR,MAY,JUN,  //Months of the year
//             JUL,AUG,SEP,OCT,NOV,DEC};
             
const int MONTHS=12;             

//Function prototypes
void fillAry(Weather[]);    
void prntAry(Weather[]);

void getAvg(Weather[]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declare variables
    
    //Declare array
    Weather data[MONTHS];    

    fillAry(data);
    getAvg(data);

    
    //Exit program
    return 0;
}

void fillAry(Weather data[]){
    for(int i=0;i<MONTHS;i++){
        data[i].rain=(rand()%1000)/100.0f;
        data[i].higT=rand()%40+60;
        data[i].lowT=rand()%100-40;
        data[i].avgT=(data[i].higT+data[i].lowT)/2;
    }
}

void getAvg(Weather data[]){
    float avgRain,
          avgHig,
          avgLow,
          avgAvg;  
    
    for(int i=0;i<MONTHS;i++){
        avgRain+=data[i].rain;
        avgHig+=data[i].higT;
        avgLow+=data[i].lowT;
        avgAvg+=data[i].avgT;
    }
    
    avgRain/=MONTHS;
    avgHig/=MONTHS;
    avgLow/=MONTHS;
    avgAvg/=MONTHS;
    
    cout<<"Average Annual Rainfall: "<<fixed<<setprecision(2)<<avgRain<<" in."<<endl;
    cout<<"Average Annual High    : "<<fixed<<setprecision(2)<<avgHig<<" F"<<endl;
    cout<<"Average Annual Low     : "<<fixed<<setprecision(2)<<avgLow<<" F"<<endl;
    cout<<"Average Annual Average : "<<fixed<<setprecision(2)<<avgAvg<<" F"<<endl;
}

void prntAry(Weather data[]){
    for(int i=0;i<MONTHS;i++){
        cout<<"Total Monthly Rainfall: "
                <<fixed<<setprecision(2)<<data[i].rain<<"in."<<endl;
        cout<<"Monthly high: "
                <<fixed<<setprecision(1)<<data[i].higT<<"F"<<endl;
        cout<<"Monthly low: "
                <<fixed<<setprecision(1)<<data[i].lowT<<"F"<<endl;
        cout<<"Monthly average: "
                <<fixed<<setprecision(1)<<data[i].avgT<<"F"<<endl;
        cout<<endl;
    }
}
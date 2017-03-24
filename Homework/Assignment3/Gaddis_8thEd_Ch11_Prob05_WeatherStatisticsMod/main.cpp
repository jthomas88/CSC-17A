/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on March 23, 2017, 3:50 PM
 * Purpose: Weather Data
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
const int MONTHS=12; //Number of months in a year    

enum year {JAN,FEB,MAR,APR,MAY,JUN, 
           JUL,AUG,SEP,OCT,NOV,DEC};

//Function prototypes
void fillAry(Weather[]);    
void prntAry(Weather[],string[]);

void getData(Weather[],string[]);
void findHig(Weather[],string[]);
void findLow(Weather[],string[]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declare array for weather data
    Weather data[MONTHS]; 
    
    //Array for months of the year
    string year[]={"JAN","FEB","MAR","APR","MAY","JUN",
                 "JUL","AUG","SEP","OCT","NOV","DEC"};

    //Fill array with weather data
    fillAry(data);
    
    //Output data month by month
    prntAry(data,year);
    
    //Generate statistics
    getData(data,year);
    
    //Exit program
    return 0;
}

void fillAry(Weather data[]){
    for(int i=JAN;i<=DEC;i++){
        data[i].rain=(rand()%1000)/100.0f; //Random value between 0.00"-9.99"
        data[i].higT=rand()%40+60;  //Random temperature between 60F - 99F
        data[i].lowT=rand()%100-40; //Random temperature between -40F - 59F
        data[i].avgT=(data[i].higT+data[i].lowT)/2; //Average of high and low
    }
}

void getData(Weather data[],string m[]){
    //Declare variable to hold totals
    Weather totals;  
    
    //Get totals
    for(int i=JAN;i<=DEC;i++){
        totals.rain+=data[i].rain; //Add together rain data from all months
        totals.avgT+=data[i].avgT; //Add together averages from all months
    }
    
    //Output total rainfall
    cout<<"Total Rainfall  : "<<fixed<<setprecision(2)<<totals.rain<<" in."<<endl;
    
    //Calculate Averages
    totals.rain/=MONTHS;
    totals.avgT/=MONTHS;
    
    //Output annual averages
    cout<<"Annual Average  : "<<fixed<<setprecision(1)<<totals.avgT<<" F"<<endl;
    cout<<"Average Rainfall: "<<fixed<<setprecision(2)<<totals.rain<<" in."<<endl;
    
    //Find and output annual high
    findHig(data,m);
    
    //Find and output annual low
    findLow(data,m);
}

void prntAry(Weather data[],string m[]){
    for(int i=JAN;i<=DEC;i++){
        cout<<m[i]<<endl;
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

void findHig(Weather data[],string m[]){
    short high=data[0].higT; //Initialize high to first value in array
    string curMon;           //Corresponding month to the annual high
    
    //Find annual high
    for(int i=JAN;i<=DEC;i++){
        if(data[i].higT>high){
            high=data[i].higT;
            curMon=m[i];
        }
    }
    
    //Output annual high
    cout<<"Annual High     : "<<curMon<<' '<<high<<" F"<<endl;
}

void findLow(Weather data[],string m[]){
    short low=data[0].lowT; //Initialize high to first value in array
    string curMon;          //Corresponding month to annual low
    
    //Find annual low
    for(int i=JAN;i<=DEC;i++){
        if(data[i].lowT<low){
            low=data[i].lowT;
            curMon=m[i];
        }
    }
    
    //Output annual low
    cout<<"Annual Low      : "<<curMon<<' '<<low<<" F"<<endl;
}
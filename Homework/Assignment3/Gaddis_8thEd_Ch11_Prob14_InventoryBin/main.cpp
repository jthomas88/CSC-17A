/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //I/O format

using namespace std; //Namespace used in system library

//User libraries
#include "Bin.h"

//Global constants

//Enumerators
enum parts {VALV,BRNG,BUSH,COUP,FLNG,GEAR,GHOU,VGRP,CABL,RODD};

//Function Prototypes
void initBin(Bin[]);
void dispBin(Bin[]);
void addPart(Bin[]);
void remPart(Bin[]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare Variables
    const int SIZE=10; //Number of bins
    int cho;           //User inputted choice
    
    //Declare Array
    Bin inv[SIZE];   
    
    //Initialize array to starting values
    initBin(inv);
    
    //Start Menu
    do{
        cout<<"1. Add parts to bin"<<endl;
        cout<<"2. Remove parts from bin"<<endl;
        cout<<"3. Display bin contents"<<endl<<endl;
        cout<<"Press 0 to exit the program"<<endl;
        cin>>cho;
        switch(cho){
            case 0:break;
            case 1:
                addPart(inv);
                break;
            case 2:
                remPart(inv);
                break;
            case 3:
                dispBin(inv);
                break;
            default:
                cout<<"Please choose a valid option.";
                cout<<endl<<endl;
                break;
        }
    }while(cho!=0);
    
    //Exit program
    return 0;
}

//Initialize Bins Function
void initBin(Bin inv[]){
    inv[VALV].name="Valve";
    inv[VALV].stok=10;
    
    inv[BRNG].name="Bearing";
    inv[BRNG].stok=5;
    
    inv[BUSH].name="Bushing";
    inv[BUSH].stok=15;
    
    inv[COUP].name="Coupling";
    inv[COUP].stok=21;
    
    inv[FLNG].name="Flange";
    inv[FLNG].stok=7;
    
    inv[GEAR].name="Gear";
    inv[GEAR].stok=5;
    
    inv[GHOU].name="Gear Housing";
    inv[GHOU].stok=5;
    
    inv[VGRP].name="Vacuum Gripper";
    inv[VGRP].stok=25;
    
    inv[CABL].name="Cable";
    inv[CABL].stok=18;
    
    inv[RODD].name="Rod";
    inv[RODD].stok=12;
}

//Add Parts Function
void addPart(Bin inv[]){
    int cho;      //User inputted choice
    int add=0;    //Number of parts to be added
    bool isAdd=0; //Flag to confirm parts have been added
    
    //Prompt user
    cout<<"Select a bin to add parts to."<<endl<<endl;
    for(int i=VALV;i<=RODD;i++){
        cout<<i+1<<". "<<inv[i].name<<endl;
    }
    //Input choice
    cin>>cho;
    do{
        //Prompt user
        cout<<"How many parts are you adding?"<<endl;
        //Input choice
        cin>>add;    
        //Deny part add if total exceeds 30 parts
        if(inv[cho-1].stok+add>30){
            cout<<"Maximum capacity is 30 parts. Please add a smaller amount."<<endl;
        }
        //Add parts if parts fit
        else{
            inv[cho-1].stok+=add;
            cout<<"Added "<<add<<" parts to "<<inv[cho-1].name;
            isAdd=1;
        }  
    }while(!isAdd); //Continue looping until parts have been added    
    cout<<endl<<endl;
}

//Remove Parts Function
void remPart(Bin inv[]){
    int cho;
    int rem=0;
    bool isRem=0;
    cout<<"Select a bin to add parts to."<<endl<<endl;
    for(int i=VALV;i<=RODD;i++){
        cout<<i+1<<". "<<inv[i].name<<endl;
    }
    cin>>cho;
    do{
        cout<<"How many parts are you removing?"<<endl;
        cin>>rem;    
        if(inv[cho-1].stok-rem<0){
            cout<<"There are only "<<inv[cho-1].stok<<" parts."<<endl;
        }
        else{
            inv[cho-1].stok-=rem;
            cout<<"Removed "<<rem<<" parts from "<<inv[cho-1].name;
            isRem=1;
        }  
    }while(!isRem);
    cout<<endl<<endl;
}

//Display Bin Function
void dispBin(Bin inv[]){
    for(int i=VALV;i<=RODD;i++){
        cout<<left<<setw(20)<<inv[i].name<<": "<<inv[i].stok;
        cout<<endl;
    }
    cout<<endl<<endl;
}
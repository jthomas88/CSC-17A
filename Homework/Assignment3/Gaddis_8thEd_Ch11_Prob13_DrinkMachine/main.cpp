/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream> //Object I/O
#include <iomanip>  //I/O format

  //Input/Output objects

using namespace std; //Namespace used in system library

//User libraries
#include "Drinks.h"

//Global constants
enum drinks {COLA,RB,LEMLIM,GRAPE,CREAM}; //Drink type enumerator

//Function prototypes
int  prompt(Drink[],int&);
void initMch(Drink[]);
void drnkSim(Drink[]);

void paymnt(Drink[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    const int size=5;    //Number of drinks
    Drink machine[size]; //Dink machine object
    
    //Initialize drinks
    initMch(machine);
    
    //Begin simulation
    drnkSim(machine);

    //Exit program
    return 0;
}

void initMch(Drink machine[]){
    //Declare name, cost, and initial quantity for all drinks
    machine[COLA].name="Cola";
    machine[COLA].cost=0.75f;
    machine[COLA].stok=20;
    
    machine[RB].name="Root Beer";
    machine[RB].cost=0.75f;
    machine[RB].stok=20;
    
    machine[LEMLIM].name="Lemon-Lime";
    machine[LEMLIM].cost=0.75f;
    machine[LEMLIM].stok=20;
    
    machine[GRAPE].name="Grape Soda";
    machine[GRAPE].cost=0.80f;
    machine[GRAPE].stok=20;
    
    machine[CREAM].name="Cream Soda";
    machine[CREAM].cost=0.80f;
    machine[CREAM].stok=20;
}

void paymnt(Drink machine[],int cho){
    float entrd,money=0.0f; //Initialize money entered and total money to 0
    do{
        //Prompt user for input
        cout<<"Enter your money now"<<endl;
        //Input money
        cin>>money;
        //Add money to total if it does not exceed maximum bill taken
        if(money<=1.0f)entrd+=money;
        //Prompt user for more money if total has not been reached
        if(entrd<machine[cho-1].cost){
            cout<<"Insufficient funds. Please enter "
                <<machine[cho-1].cost-entrd<<" more cents."<<endl;
        }
        //Prompt user to enter smaller amount if amount exceeds maximum
        if(money>1.0f){
            cout<<"Sorry! Maximum bill accepted is $1"<<endl;
        }
    }while(entrd<machine[cho-1].cost||money>1.0f);
    //Decrement 1 from quantity
    machine[cho-1].stok--;
    cout<<"*bzzt* *clunk* Enjoy your drink!"<<endl;
    //Output change owed
    cout<<"Your change is "<<entrd-machine[cho-1].cost<<" cents";
    cout<<endl<<endl;
}

void drnkSim(Drink machine[]){
    int   cho; //User inputted choice
    float money,entrd=0.00f;
    do{
        //Prompt user for drink choice
        prompt(machine,cho);
        //Money Menu
        switch(cho){
            case 0:
                break;
            case 1:
                paymnt(machine,cho);
                break;
            case 2:
                paymnt(machine,cho);
                break;
            case 3:
                paymnt(machine,cho);
                break;
            case 4:
                paymnt(machine,cho);
                break;
            case 5:
                paymnt(machine,cho);;
                break;
            default:
                cout<<"Invalid choice! Please select from the provided options.";
                cout<<endl<<endl;
                break;
        }
        //Reinitialize back to zero
        money,entrd=0.00f;
    }while(cho!=0);
}

int prompt(Drink machine[],int &cho){
    //Prompt user for choice
    cout<<"Select your drink"<<endl;
    cout<<"1. "<<setw(11)<<left<<machine[COLA].name
               <<machine[COLA].cost<<" cents"
               <<setw(6)<<right<<"qty. "<<machine[COLA].stok<<endl;
    cout<<"2. "<<setw(11)<<left<<machine[RB].name
               <<machine[RB].cost<<" cents"
               <<setw(6)<<right<<"qty. "<<machine[RB].stok<<endl;
    cout<<"3. "<<setw(11)<<left<<machine[LEMLIM].name
               <<machine[LEMLIM].cost<<" cents"
               <<setw(6)<<right<<"qty. "<<machine[LEMLIM].stok<<endl;
    cout<<"4. "<<setw(11)<<left<<machine[GRAPE].name
               <<fixed<<setprecision(2)<<machine[GRAPE].cost<<" cents"
               <<setw(6)<<right<<"qty. "<<machine[GRAPE].stok<<endl;
    cout<<"5. "<<setw(11)<<left<<machine[CREAM].name
               <<fixed<<setprecision(2)<<machine[CREAM].cost<<" cents"
               <<setw(6)<<right<<"qty. "<<machine[CREAM].stok<<endl;
    cout<<"0. End Transaction"<<endl;
    //User enters choice
    cin>>cho;
     //Return choice   
    return cho;
}
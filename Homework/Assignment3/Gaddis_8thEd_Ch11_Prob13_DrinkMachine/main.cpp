/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>
#include <iomanip>

#include "Drinks.h"  //Input/Output objects

using namespace std; //Namespace used in system library

//User libraries

//Global constants
enum drinks {COLA,RB,LEMLIM,GRAPE,CREAM};

//Function prototypes
int prompt(Drink[],int&);
void initMch(Drink[]);
void drnkSim(Drink[]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    const int size=5;
    Drink machine[size];
    
    //Initialize drinks
    initMch(machine);
    
    //Begin simulation
    drnkSim(machine);

    //Exit program
    return 0;
}

void initMch(Drink machine[]){
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

void drnkSim(Drink machine[]){
    int   cho;
    float money,entrd=0.00f;
    do{
        //Reinitialize back to zero
        money,entrd=0.00f;
        //Prompt user for drink choice
        prompt(machine,cho);
        //Money Menu
        switch(cho){
            case 0:
                break;
            case 1:
                do{
                    cout<<"Enter your money now"<<endl;
                    cin>>money;
                    if(money<=1.0f)entrd+=money;
                    if(entrd<machine[COLA].cost){
                        cout<<"Insufficient funds. Please enter "
                            <<machine[COLA].cost-entrd<<" more cents."<<endl;
                    }
                    if(money>1.0f){
                        cout<<"Sorry! Maximum bill accepted is $1"<<endl;
                    }
                }while(entrd<machine[COLA].cost||money>1.0f);
                machine[COLA].stok--;
                cout<<"*bzzt* *clunk* Enjoy your drink!"<<endl;
                cout<<"Your change is "<<entrd-machine[COLA].cost<<" cents";
                cout<<endl<<endl;
                break;
            case 2:
                do{
                    cout<<"Enter your money now"<<endl;
                    cin>>money;
                    if(money<=1.0f)entrd+=money;
                    if(entrd<machine[RB].cost){
                        cout<<"Insufficient funds. Please enter "
                            <<machine[RB].cost-entrd<<" more cents."<<endl;
                    }
                    if(money>1.0f){
                        cout<<"Sorry! Maximum bill accepted is $1"<<endl;
                    }
                }while(entrd<machine[RB].cost||money>1.0f);
                machine[RB].stok--;
                cout<<"*bzzt* *clunk* Enjoy your drink!"<<endl;
                cout<<"Your change is "<<entrd-machine[RB].cost<<" cents";
                cout<<endl<<endl;
                break;
            case 3:
                do{
                    cout<<"Enter your money now"<<endl;
                    cin>>money;
                    if(money<=1.0f)entrd+=money;
                    if(entrd<machine[LEMLIM].cost){
                        cout<<"Insufficient funds. Please enter "
                            <<machine[LEMLIM].cost-entrd<<" more cents."<<endl;
                    }
                    if(money>1.0f){
                        cout<<"Sorry! Maximum bill accepted is $1"<<endl;
                    }
                }while(entrd<machine[LEMLIM].cost||money>1.0f);
                machine[LEMLIM].stok--;
                cout<<"*bzzt* *clunk* Enjoy your drink!"<<endl;
                cout<<"Your change is "<<entrd-machine[LEMLIM].cost<<" cents";
                cout<<endl<<endl;
                break;
            case 4:
                do{
                    cout<<"Enter your money now"<<endl;
                    cin>>money;
                    if(money<=1.0f)entrd+=money;
                    if(entrd<machine[GRAPE].cost){
                        cout<<"Insufficient funds. Please enter "
                            <<machine[GRAPE].cost-entrd<<" more cents."<<endl;
                    }
                    if(money>1.0f){
                        cout<<"Sorry! Maximum bill accepted is $1"<<endl;
                    }
                }while(entrd<machine[GRAPE].cost||money>1.0f);
                machine[GRAPE].stok--;
                cout<<"*bzzt* *clunk* Enjoy your drink!"<<endl;
                cout<<"Your change is "<<entrd-machine[GRAPE].cost<<" cents";
                cout<<endl<<endl;
                break;
            case 5:
                do{
                    cout<<"Enter your money now"<<endl;
                    cin>>money;
                    if(money<=1.0f)entrd+=money;
                    if(entrd<machine[CREAM].cost){
                        cout<<"Insufficient funds. Please enter "
                            <<machine[CREAM].cost-entrd<<" more cents."<<endl;
                    }
                    if(money>1.0f){
                        cout<<"Sorry! Maximum bill accepted is $1"<<endl;
                    }
                }while(entrd<machine[CREAM].cost||money>1.0f);
                machine[CREAM].stok--;
                cout<<"*bzzt* *clunk* Enjoy your drink!"<<endl;
                cout<<"Your change is "<<entrd-machine[CREAM].cost<<" cents";
                cout<<endl<<endl;
                break;
            default:
                cout<<"Invalid choice! Please select from the provided options.";
                cout<<endl<<endl;
                break;
        }
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
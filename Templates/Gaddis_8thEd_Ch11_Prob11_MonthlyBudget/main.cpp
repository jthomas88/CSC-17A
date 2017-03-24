/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std; //Namespace used in system library

//User libraries
#include "Budget.h"

//Global constants

//Function prototypes
void fillAry(Budg);
void prntAry(Budg);
void chkBudg(Budg,Budg);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declare variables
    Budg ideal;    
    Budg real;
    
    //Generate monthly spending report
    fillAry(real);
    
    //Display monthly spending report
    cout<<"Ideal Budget"<<endl;
    prntAry(ideal);
    cout<<endl;
    
    cout<<"This Month's Budget"<<endl;
    prntAry(real);
    cout<<endl;
    
    //Check budget surpluses/deficits;
    chkBudg(ideal,real);
    
    //Process Values
    
    //Exit program
    return 0;
}

void fillAry(Budg b){
    b.hous=rand()%500;b.totl+=b.hous;
    b.util=rand()%500;b.totl+=b.util;
    b.hexp=rand()%60000/1000;b.totl+=b.hexp;
    b.trns=rand()%60000/1000;b.totl+=b.trns;
    b.food=rand()%60000/1000;b.totl+=b.food;
    b.meds=rand()%60000/1000;b.totl+=b.meds;
    b.insr=rand()%60000/1000;b.totl+=b.insr;
    b.entr=rand()%60000/1000;b.totl+=b.entr;
    b.clot=rand()%60000/1000;b.totl+=b.clot;
    b.misc=rand()%60000/1000;b.totl+=b.misc;
}
void prntAry(Budg b){
    cout<<"Housing       : $"<<fixed<<setprecision(2)<<b.hous<<endl;
    cout<<"Utilities     : $"<<fixed<<setprecision(2)<<b.util<<endl;
    cout<<"Home Expenses : $"<<fixed<<setprecision(2)<<b.hexp<<endl;
    cout<<"Transportation: $"<<fixed<<setprecision(2)<<b.trns<<endl;
    cout<<"Food          : $"<<fixed<<setprecision(2)<<b.food<<endl;
    cout<<"Medical       : $"<<fixed<<setprecision(2)<<b.meds<<endl;
    cout<<"Insurance     : $"<<fixed<<setprecision(2)<<b.insr<<endl;
    cout<<"Entertainment : $"<<fixed<<setprecision(2)<<b.entr<<endl;
    cout<<"Clothing      : $"<<fixed<<setprecision(2)<<b.clot<<endl;
    cout<<"Miscellaneous : $"<<fixed<<setprecision(2)<<b.misc<<endl;
    cout<<"Total Monthly : $"<<fixed<<setprecision(2)<<b.totl<<endl;
}
void chkBudg(Budg a,Budg b){
    cout<<"Housing       : $"<<(a.hous>b.hous)?a.hous-b.hous:b.hous-a.hous;
    cout<<endl;
    cout<<"Utilities     : $"<<(a.util>b.util)?a.util-b.util:b.util-a.util;
    cout<<endl;
    cout<<"Home Expenses : $"<<(a.hexp>b.hexp)?a.hexp-b.hexp:b.hexp-a.hexp;
    cout<<endl;
    cout<<"Transportation: $"<<(a.trns>b.trns)?a.trns-b.trns:b.trns-a.trns;
    cout<<endl;
    cout<<"Food          : $"<<(a.food>b.food)?a.food-b.food:b.food-a.food;
    cout<<endl;
    cout<<"Medical       : $"<<(a.meds>b.meds)?a.meds-b.meds:b.meds-a.meds;
    cout<<endl;
    cout<<"Insurance     : $"<<(a.insr>b.insr)?a.insr-b.insr:b.insr-a.insr;
    cout<<endl;
    cout<<"Entertainment : $"<<(a.entr>b.entr)?a.entr-b.entr:b.entr-a.entr;
    cout<<endl;
    cout<<"Clothing      : $"<<(a.clot>b.clot)?a.clot-b.clot:b.clot-a.clot;
    cout<<endl;
    cout<<"Miscellaneous : $"<<(a.misc>b.misc)?a.misc-b.misc:b.misc-a.misc;
    cout<<endl;
    cout<<"Total Monthly : $"<<(a.totl>b.totl)?a.totl-b.totl:b.totl-a.totl;
}
/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random generator
#include <ctime>     //Random seed
#include <iomanip>   //Format output

using namespace std; //Namespace used in system library

//User libraries
#include "MovData.h" //Movie data struct
#include "Weather.h" //Weather data struct
#include "Budget.h"  //Budget struct
#include "Student.h" //Student data struct
#include "Drinks.h"  //Drink data struct
#include "Bin.h"     //Inventory bin struct

//Enumerators
enum year {JAN,FEB,MAR,APR,MAY,JUN,       //Months of the year
           JUL,AUG,SEP,OCT,NOV,DEC};
           
enum drinks {COLA,RB,LEMLIM,GRAPE,CREAM}; //Drink type enumerator

enum parts {VALV,BRNG,BUSH,COUP,FLNG,     //Parts within the bins
            GEAR,GHOU,VGRP,CABL,RODD};

//Global constants
const int MONTHS=12; //Number of months in a year 

//Function prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();
void prob10();

//Problem 1 Functions
void prtMov1(MovData);

//Problem 2 Functions
void prtMov2(MovData);

//Problem 3 Functions
void fillAry(Weather[]);    
void prntAry(Weather[],string[]);

void getData(Weather[],string[]);
void findHig(Weather[],string[]);
void findLow(Weather[],string[]);

//Problem 4 Functions
void filAry4(Weather[]);
void prtAry4(Weather[],string[]);

void getDta4(Weather[],string[]);
void fndHig4(Weather[],string[]);
void fndLow4(Weather[],string[]);

//Problem 5 Functions
void fillAry(Budg&);
void prntAry(Budg);
void chkBudg(Budg,Budg);

//Problem 6 Functions
void initAry(Student*,int,string[]);
void prntAry(Student*,int);
void destroy(Student[],int);

//Problem 7 Functions
int  prompt(Drink[],int&);
void initMch(Drink[]);
void drnkSim(Drink[]);
void paymnt(Drink[],int);

//Problem 8 Functions
void initBin(Bin[]);
void dispBin(Bin[]);
void addPart(Bin[]);
void remPart(Bin[]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declare variables
    int menuCho;
    
    //Open Menu
    do{
        cout<<"1)  Problem 1: Movie Data"<<endl;
        cout<<"2)  Problem 2: Movie Profit"<<endl;
        cout<<"3)  Problem 3: Weather Statistics"<<endl;
        cout<<"4)  Problem 4: Weather Statistics (Enum Mod)"<<endl;
        cout<<"5)  Problem 5: Monthly Budget"<<endl;
        cout<<"6)  Problem 6: Course Grade"<<endl;
        cout<<"7)  Problem 7: Drink Machine"<<endl;
        cout<<"8)  Problem 8: Inventory Bin"<<endl;
        cin>>menuCho;
        switch(menuCho){
            case 1: prob1();cout<<endl<<endl;break;
            case 2: prob2();cout<<endl<<endl;break;
            case 3: prob3();cout<<endl<<endl;break;
            case 4: prob4();cout<<endl<<endl;break;
            case 5: prob5();cout<<endl<<endl;break;
            case 6: prob6();cout<<endl<<endl;break;
            case 7: prob7();cout<<endl<<endl;break;
            case 8: prob8();cout<<endl<<endl;break;
        }
    }while(menuCho>0&&menuCho<=8);  
    
    //Exit program
    return 0;
}

void  prob1(){
    cout<<"Problem 1: Movie Data"<<endl;
    //Declare variables
    MovData mov1,mov2;
    
    //Define objects
    mov1={"The Godfather","Francis Ford Coppola",1972,178};
    mov2={"The Room","Tommy Wiseau",2003,99};
    
    //Display Output
    prtMov1(mov1);
    cout<<endl;
    prtMov1(mov2);

}
void  prob2(){
    cout<<"Problem 2: Movie Profit"<<endl;
    //Declare variables
    MovData mov1,mov2;
    
    //Define objects
    mov1={"The Godfather","Francis Ford Coppola",1972,178,6,245};
    mov2={"The Room","Tommy Wiseau",2003,99,6,10};
    
    //Display Output
    prtMov2(mov1);
    cout<<endl;
    prtMov2(mov2);
    
}
void  prob3(){
    cout<<"Problem 3: Weather Statistics"<<endl;
    //Declare array for 
    Weather data[MONTHS]; 
    //Array for months of the year
    string year[MONTHS]={"JAN","FEB","MAR","APR","MAY","JUN", 
                         "JUL","AUG","SEP","OCT","NOV","DEC"};

    //Fill array with weather data
    fillAry(data);
    
    //Output data month by month
    prntAry(data,year);
    
    //Generate statistics
    getData(data,year);
}
void  prob4(){
    cout<<"Problem 4: Weather Statistics (Enum Mod)"<<endl;
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
}
void  prob5(){
    cout<<"Problem 5: Monthly Budget"<<endl;
    //Declare variables
    Budg ideal;    
    Budg real;
    
    //Define ideal budget
    ideal.hous=500.00f;ideal.totl+=ideal.hous;
    ideal.util=150.00f;ideal.totl+=ideal.util;
    ideal.hexp= 65.00f;ideal.totl+=ideal.hexp;
    ideal.trns= 50.00f;ideal.totl+=ideal.trns;
    ideal.food=250.00f;ideal.totl+=ideal.food;
    ideal.meds= 30.00f;ideal.totl+=ideal.meds;
    ideal.insr=100.00f;ideal.totl+=ideal.insr;
    ideal.entr=150.00f;ideal.totl+=ideal.entr;
    ideal.clot= 75.00f;ideal.totl+=ideal.clot;
    ideal.misc= 50.00f;ideal.totl+=ideal.misc;
    
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
}
void  prob6(){
    cout<<"Problem 6: Course Grade"<<endl;
    //Random Name Generator
    string names[]={"John","Joe","Sally","Tim","Maude",
                    "Mark","Luke","Mary","Victor","Louise",
                    "Henry","Claudius","Helena","Elaine","Joey"};
    
    //Declare random size of dynamic array (5-9)
    int size=rand()%5+5;
    
    //Allocate Memory
    Student *array;
    array=new Student[size];
    
    //Initialize Array Values
    initAry(array,size,names);
    
    //Output Array Data
    prntAry(array,size);
    
    //Destroy Test Array
    destroy(array,size);
    
    //Deallocate Memory
    delete []array;
}
void  prob7(){
    cout<<"Problem 7: Drink Machine"<<endl;
    //Declaration of variables
    const int size=5;    //Number of drinks
    Drink machine[size]; //Dink machine object
    
    //Initialize drinks
    initMch(machine);
    
    //Begin simulation
    drnkSim(machine);
}
void  prob8(){
    cout<<"Problem 8: Inventory Bin"<<endl;
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
}

//Problem 1 Functions
void prtMov1(MovData movie){
    cout<<"Title:   "<<movie.title<<endl;
    cout<<"Directed by "<<movie.drctr<<endl;
    cout<<"Year:    "<<movie.year<<endl;
    cout<<"Runtime: "<<movie.runtm<<" mins."<<endl;
}

//Problem 2 Functions
void prtMov2(MovData movie){
    cout<<"Title:   "<<movie.title<<endl;
    cout<<"Directed by "<<movie.drctr<<endl;
    cout<<"Year:    "<<movie.year<<endl;
    cout<<"Runtime: "<<movie.runtm<<" mins."<<endl;
    cout<<"Net Earnings: $"<<movie.grss-movie.bdgt<<'m'<<endl;
}

//Problem 3 Functions
void fillAry(Weather data[]){
    for(int i=0;i<MONTHS;i++){
        data[i].rain=(rand()%1000)/100.0f; //Random value between 0.00"-9.99"
        data[i].higT=rand()%40+60;  //Random temperature between 60F - 99F
        data[i].lowT=rand()%100-40; //Random temperature between -40F - 59F
        data[i].avgT=(data[i].higT+data[i].lowT)/2; //Average of high and low
    }
}
void getData(Weather data[],string m[]){
    //Declare variable to hold totals
    Weather totals={0,0,0,0};  
    
    //Get totals
    for(int i=0;i<MONTHS;i++){
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
    for(int i=0;i<MONTHS;i++){
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
    short  high=data[0].higT; //Initialize high to first value in array
    string curMon=m[0];            //Corresponding month to the annual high
    
    //Find annual high
    for(int i=0;i<MONTHS;i++){
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
    string curMon=m[0];     //Corresponding month to annual low
    
    //Find annual low
    for(int i=1;i<MONTHS;i++){
        if(data[i].lowT<low){
            low=data[i].lowT;
            curMon=m[i];
        }
    }    
    //Output annual low
    cout<<"Annual Low      : "<<curMon<<' '<<low<<" F"<<endl;
}

//Problem 4 Functions
void filAry4(Weather data[]){
    for(int i=JAN;i<=DEC;i++){
        data[i].rain=(rand()%1000)/100.0f; //Random value between 0.00"-9.99"
        data[i].higT=rand()%40+60;  //Random temperature between 60F - 99F
        data[i].lowT=rand()%100-40; //Random temperature between -40F - 59F
        data[i].avgT=(data[i].higT+data[i].lowT)/2; //Average of high and low
    }
}
void getDta4(Weather data[],string m[]){
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
    fndHig4(data,m);
    
    //Find and output annual low
    fndLow4(data,m);
}
void prtAry4(Weather data[],string m[]){
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
void fndHig4(Weather data[],string m[]){
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
void fndLow4(Weather data[],string m[]){
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

//Problem 5 Functions
void fillAry(Budg &b){
    //Fill each array with random amounts 0.0-500.0
    b.hous=rand()%5000*0.1;b.totl+=b.totl;
    b.util=rand()%5000*0.1;b.totl+=b.util;
    b.hexp=rand()%5000*0.1;b.totl+=b.hexp;
    b.trns=rand()%5000*0.1;b.totl+=b.trns;
    b.food=rand()%5000*0.1;b.totl+=b.food;
    b.meds=rand()%5000*0.1;b.totl+=b.meds;
    b.insr=rand()%5000*0.1;b.totl+=b.insr;
    b.entr=rand()%5000*0.1;b.totl+=b.entr;
    b.clot=rand()%5000*0.1;b.totl+=b.clot;
    b.misc=rand()%5000*0.1;b.totl+=b.misc;
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
    cout<<"Housing       : $"<<a.hous-b.hous;cout<<endl;
    cout<<"Utilities     : $"<<a.util-b.util;cout<<endl;
    cout<<"Home Expenses : $"<<a.hexp-b.hexp;cout<<endl;
    cout<<"Transportation: $"<<a.trns-b.trns;cout<<endl;
    cout<<"Food          : $"<<a.food-b.food;cout<<endl;
    cout<<"Medical       : $"<<a.meds-b.meds;cout<<endl;
    cout<<"Insurance     : $"<<a.insr-b.insr;cout<<endl;
    cout<<"Entertainment : $"<<a.entr-b.entr;cout<<endl;
    cout<<"Clothing      : $"<<a.clot-b.clot;cout<<endl;
    cout<<"Miscellaneous : $"<<a.misc-b.misc;cout<<endl;
}

//Problem 6 Functions
void initAry(Student *a,int n,string rndName[]){
    //Initialize Random Name and ID Number
    for(int i=0;i<n;i++){
        a[i].name=rndName[rand()%15]; //Selects random name from list
        a[i].stuID=rand()%9000+1000;  //Random 4-digit ID
    }
    //Initialize Random Test Scores
    for(int i=0;i<n;i++){
        a[i].tstSize=rand()%10+1; //Random number of tests 1-10
        a[i].tests=new int [a[i].tstSize]; //Allocate memory for test scores
        for(int j=0;j<a[i].tstSize;j++){            
            a[i].tests[j]=rand()%100; //Assign each array element a score 0-99
        }
    }
    //Find average
    for(int i=0;i<n;i++){
        float total=0; //Initialize total to zero
        for(int j=0;j<a[i].tstSize;j++){            
            total+=a[i].tests[j]; //Add test scores to total
        }
        a[i].avg=total/a[i].tstSize; //Calculate average
    }
    //Determine letter grade
    for(int i=0;i<n;i++){
        (a[i].avg>90)?a[i].grade='A': //A for grade 90<x<100
        (a[i].avg>80)?a[i].grade='B': //B for grade 80<x<91
        (a[i].avg>70)?a[i].grade='C': //C for grade 70<x<81
        (a[i].avg>60)?a[i].grade='D': //D for grade 60<x<71
                      a[i].grade='F'; //F for grade  0<x<61
    } 
    
        
}
void prntAry(Student *a,int n){
    for(int i=0;i<n;i++){
        cout<<"Name: "<<a[i].name<<endl;
        cout<<"ID #: "<<a[i].stuID<<endl;
        cout<<"Test: ";
        for(int j=0;j<a[i].tstSize;j++){            
            cout<<a[i].tests[j]<<' ';
        }
        cout<<endl;
        cout<<"Avrg: "<<fixed<<setprecision(2)<<a[i].avg<<endl;
        cout<<"Grad: "<<a[i].grade<<endl;
        cout<<endl<<endl;
    }
}
void destroy(Student a[],int n){
    delete []a->tests;
}

//Problem 7 Functions
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
int  prompt(Drink machine[],int &cho){
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

//Problem 8 Functions
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
void dispBin(Bin inv[]){
    for(int i=VALV;i<=RODD;i++){
        cout<<left<<setw(20)<<inv[i].name<<": "<<inv[i].stok;
        cout<<endl;
    }
    cout<<endl<<endl;
}
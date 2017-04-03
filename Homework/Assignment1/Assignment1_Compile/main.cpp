/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on 03/03/17, 10:30 PM
 * Purpose: Assignment 1 CSC-17A
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Ouput format
#include <cstdlib>   //Random generator
#include <ctime>     //Random seed
#include <fstream>   //File I/O

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int USD=100;     //Dollar conversion
const int PERCENT=100; //Percent conversion
const int MON=3;       //2D Array Dimension

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

//Problem 1 functions
void fillAry(short[],int);   //Fills array with values 0 - 99
void prntAry(short[],int);   //Outputs array
int cToF(short);             //Celsius-to-Fahrenheit conversion

//Problem 2 functions
void fillAry(float[],char);  //Fills array with random values
void prntAry(float[],char);  //Ouputs formatted array
float exchnge(float,float);  //Converts USD to given currency

//Problem 3 functions
float adjust(float,int,int); //Adjusts recipe for desired yield

//Problem 4 functions
float bmicalc(int,int);      //Calculate BMI

//Problem 5 functions
bool isLeap(short);          //Checks if leap year is false

//Problem 6 functions
int popChng(int,int,float);  //Population growth calculation

//Problem 7 functions
int fToC(short);             //Fahrenheit-to-Celcius conversion

//Problem 8 functions
void fillAry(char[][MON],int); //Fill array with random char values
void prntAry(char[][MON],int); //Output array
void wthrTly(char[][MON],string[],int); //Tallys weather patterns

//Problem 9 functions     
void fillAry(int[],int);     
void prntAry(int[],int);
int  linSrch(int[],int,int);   //Linear search
int  binSrch(int[],int,int);   //Binary search
void slctSrt(int [],int);      //Selection sort

//Problem 10 Functions
void copyAry(int[],int[],int); //Copy array
void slctp10(int[],int);       //Selection sort w/ counter
void bubbSrt(int[],int);       //Bubble sort

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare variables
    int menuCho;
    
    //Open Menu
    do{
        cout<<"1)  Problem  1: Celsius-to-Fahrenheit"<<endl;
        cout<<"2)  Problem  2: Currency Conversion"<<endl;
        cout<<"3)  Problem  3: Cookie Recipe"<<endl;
        cout<<"4)  Problem  4: BMI Calculator"<<endl;
        cout<<"5)  Problem  5: Leap Years"<<endl;
        cout<<"6)  Problem  6: Population Change Calculator"<<endl;
        cout<<"7)  Problem  7: Fahrenheit-to-Celsius"<<endl;
        cout<<"8)  Problem  8: Weather Data"<<endl;
        cout<<"9)  Problem  9: Search Benchmarks"<<endl;
        cout<<"10) Problem 10: Sort Benchmarks"<<endl;
        cin>>menuCho;
        switch(menuCho){
            case 1: prob1();break;
            case 2: prob2();break;
            case 3: prob3();break;
            case 4: prob4();break;
            case 5: prob5();break;
            case 6: prob6();break;
            case 7: prob7();break;
            case 8: prob8();break;
            case 9: prob9();break;
            case 10:prob10();break;
        }
    }while(menuCho>0&&menuCho<=10);  
    
    //Exit program
    return 0;
}

void  prob1(){
    cout<<"Problem 1"<<endl;
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
}
void  prob2(){
    cout<<"Problem 2"<<endl;
    //Init random seed
    srand(time(0));
    
    //Declare constants
    const char SIZE=5;       //Array size
    
    const float YEN=112.26f; //Current YEN-to-USD exchange rate
    const float EUR=  0.94f; //Current EUR-to-USD exchange rate
    
    
    //Declare array
    float amts[SIZE]; //Random test amounts in USD
    
    //Fill array with random dollar amounts $0.01 - $10.00
    fillAry(amts,SIZE);
    
    //Output USD
    cout<<"Dollar amounts in USD: "<<endl;
    prntAry(amts,SIZE);
    cout<<endl;
    
    //Convert to EUR and output
    cout<<"Amounts converted to EUR: "<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<exchnge(amts[i],EUR);
        if(i<SIZE-1)cout<<", ";
    }
    cout<<endl;
    
    //Convert to YEN and output
    cout<<"Amounts converted to YEN: "<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<exchnge(amts[i],YEN);
        if(i<SIZE-1)cout<<", ";
    }
    cout<<endl<<endl;
}
void  prob3(){
    cout<<"Problem 3"<<endl;
     //Declare Constants
    int const COOKIE=48; //Yield of original recipe
    
    //Declaration of variables
    float sug=1.5f,  //Sugar (in cups) needed for original yield of 48 cookies
          btr=1.0f,  //Butter (in cups) needed for original yield of 48 cookies
          flr=2.75f; //Flour (in cups) needed for original yield of 48 cookies 
    int   yield;     //User's desired yield
    
    //Prompt user for input
    cout<<"How many cookies would you like to make?"<<endl;
    cin>>yield;
    cout<<endl;
    
    //Calculate quantities and output
    cout<<"Recipe for "<<yield<<" cookies"<<endl;
    cout<<"Flour:  "<<adjust(flr,yield,COOKIE)<<" cups\n"; //Flour calculation
    cout<<"Sugar:  "<<adjust(sug,yield,COOKIE)<<" cups\n"; //Sugar calc
    cout<<"Butter: "<<adjust(btr,yield,COOKIE)<<" cups\n"; //Butter calc
    cout<<endl<<endl;
}
void  prob4(){
    cout<<"Problem 4"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    short hgt,wgt;     //Height in inches and weight in lbs, respectively
    
    //Assign random test values
    hgt=rand()%36+48;  //Random height between 4'6" - 6'6"
    wgt=rand()%160+80; //Random weight between 80 lbs - 220 lbs 
    
    //Output height, weight, and BMI
    cout<<"Your height: "<<hgt/12<<'\''<<hgt%12<<'\"'<<endl;
    cout<<"Your weight: "<<wgt<<" lbs."<<endl;
    cout<<"Your BMI:    "<<bmicalc(hgt,wgt);
    cout<<endl;
    
    //Determine BMI range
    if(bmicalc(hgt,wgt)<18.5){ //If user is in underweight range
        cout<<"Clickety Clack! You're underweight Mr. Skeleton!";
    }
    else if(bmicalc(hgt,wgt)>25){ //If user is in overweight range
        cout<<"Lay of the Doritos, tubby! You're overweight!";
    }
    else{ //If user is in healthy range
        cout<<"Congratulations! You're a healthy weight for your height!";
    }
    cout<<endl<<endl;
}
void  prob5(){
    cout<<"Problem 5"<<endl;
    //Declare Variables
    int  mn;  //User inputted month
    short yr; //User inputted year
    
    //Explain Program
    cout<<"This program will determine how many days are in a given year.\n";
    
    //Prompt for input
    cout<<"Enter a month (1-12): ";
    cin>>mn;
    cout<<"Enter a year: ";
    cin>>yr;
    
    //Output number of days
    switch(mn){
        //All months with 31 days
        case 1:case 3:case 5:case 7:case 8:
        case 10:case 12: cout<<"31 days";break;
        //All months with 30 days
        case 4:case 6:case 9:case 11: cout<<"30 days";break;
        //Adds extra day to Feb is bool function is true
        case 2:cout<<28+isLeap(yr)<<" days.";
    }
    cout<<endl<<endl;
}
void  prob6(){
    cout<<"Problem 6"<<endl;
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
    cout<<endl<<endl;
}
void  prob7(){
    cout<<"Problem 7"<<endl;
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
}
void  prob8(){
    cout<<"Problem 8"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declare constants
    const int MON=3;  //Number of months being recorded
    const int DAY=30; //Number of days per month being measured
    
    //Declare arrays
    char weather[DAY][MON]; //3 x 30 weather data array
    string months[MON]={"June","July","August"}; //Corresponding array of months
    
    //Declare file objects and open
    ofstream write;
    write.open("rainorshine.dat");
    
    //Fill array with random values
    fillAry(weather,DAY);
    
    //Output Array
    prntAry(weather,DAY);
    
    //Calculate and output results
    wthrTly(weather,months,DAY);
    
    //Close file
    write.close();
    cout<<endl<<endl;
}
void  prob9(){
    cout<<"Problem 9"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=100;
    int search=rand()%90+10;
    int array[SIZE]={};  //50 element array
    
    //Populate array with random elements
    fillAry(array,SIZE);
    cout<<endl;
    
    //Output array
    cout<<"Original Array"<<endl;
    prntAry(array,SIZE);
    cout<<endl;
    
    //Test efficiency of linear search
    linSrch(array,search,SIZE);
    cout<<endl;
    
    //Test efficiency of binary search
    slctSrt(array,SIZE);
    cout<<"Sorted Array"<<endl;
    prntAry(array,SIZE);
    binSrch(array,search,SIZE);
    cout<<endl<<endl;
}
void prob10(){
    cout<<"Problem 10"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=100;
    int bubArry[SIZE]={};//100 element array for bubble sort
    int slcArry[SIZE]={};//100 element array for selection sort
    
    //Populate first array with random elements
    fillAry(bubArry,SIZE);
    
    //Copy values of first array to second array
    copyAry(bubArry,slcArry,SIZE);
    
    //Output first array
    cout<<"Bubble Array"<<endl;
    prntAry(bubArry,SIZE);
    cout<<endl;
    
    //Output second array
    cout<<"Selection Array"<<endl;
    prntAry(slcArry,SIZE);
    cout<<endl;
    
    //Test efficiency of bubble sort
    cout<<"Bubble Sorted Array"<<endl;
    bubbSrt(bubArry,SIZE);
    cout<<endl;
    prntAry(bubArry,SIZE);
    cout<<endl;
    
    //Test efficiency of linear sort
    cout<<"Selection Sorted Array"<<endl;
    slctp10(slcArry,SIZE);
    cout<<endl;
    prntAry(slcArry,SIZE);
    cout<<endl<<endl;
}

//Problem 1 Functions
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

//Problem 2 Functions
void fillAry(float a[],char n){
    srand(time(0));
    int   rndi; //Random int value
    float rndf; // Int value converted to float
    
    for(int i=0;i<n;i++){
        rndi=rand()%999+1;                //Creates random number between 1-1000
        rndf=static_cast<float>(rndi)/USD;//Convert random number to float
        a[i]=rndf;                        //Assign value to corresponding memory
    }    
}
void prntAry(float a[],char n){
    for(int i=0;i<n;i++){
        //Output money amount with 2 pt precision
        cout<<fixed<<setprecision(2)<<'$'<<a[i];
        if(i<n-1)cout<<", "; //Prevents comma at the end of the output
    }
}
float exchnge(float usd,float c){
    float cnv;  //Converted rate
    cnv=usd*c;  //Multiply original value by exchange rate
    return cnv; //Return new converted rate
}

//Problem 3 Functions
float adjust(float ing,int yield,int orig){
    //Find yield for one cookie, then multiply by new yield
    float adj=(ing/orig)*yield; 
    //Output new yield
    return adj;
}

//Problem 4 Functions
float bmicalc(int hgt,int wgt){
    float bmi;               //Holds BMI value
    bmi=(wgt*703)/(hgt*hgt); //BMI calculation formula (weight*703/height^2)
    return bmi;              //Return calcualted BMI
}

//Problem 5 Functions
bool isLeap(short yr){
    if((yr%4==0&&yr%100!=0)||(yr%400==0&&yr%100==0)){
        return 1;
    }
    else{
        return 0;
    }
}

//Problem 6 Functions
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

//Problem 7 Functions
int fToC(short frn){
    int cel;
    cel=(frn-32)*5/9;
    return cel;
}

//Problem 8 Functions
void fillAry(char a[][MON],int n){
    for(int i=0;i<MON;i++){
        for(int j=0;j<n;j++){
            do{
                char wthr=rand()%26+65; //Generate random letter
                a[i][j]=wthr;           //Set array spot to letter
            //Check if it is R,C,or S    
            }while(a[i][j]!=67&&a[i][j]!=82&&a[i][j]!=83);            
        }
    }
}
void prntAry(char a[][MON],int n){
    for(int i=0;i<MON;i++){        
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<' ';
            if(j==29)cout<<endl;
        }
    }
}
void wthrTly(char a[][MON],string m[],int n){
    int rain,clou,sunn;       //Rain, Cloudy and Sunny counters
    for(int i=0;i<MON;i++){
        sunn=0;rain=0;clou=0; //Set all values
        for(int j=0;j<n;j++){             
            switch(a[i][j]){
                case 'R': rain++;break; //Tally rain counter
                case 'S': sunn++;break; //Tally sun counter
                case 'C': clou++;break; //Tally cloud counter
            }            
        }
        cout<<m[i]<<endl;
        cout<<"Sunny Days : "<<sunn<<endl;
        cout<<"Cloudy Days: "<<clou<<endl;
        cout<<"Rainy Days : "<<rain<<endl;
        cout<<endl;        
    }
}

//Problem 9 Functions
void fillAry(int array[],int size){
    for(int i=0;i<size;i++){
        array[i]=rand()%90+10;
    }
}
void prntAry(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<' ';
        if(i%10==9)cout<<endl;
    }
}
int  linSrch(int array[],int search,int size){
    for(int i=0;i<size;i++){
        if(search==array[i]){
            cout<<"Linear: "<<search<<" required "<<i+1<<" searches to find.";
            cout<<endl;
            return search;
        }
    }
    cout<<"Linear: "<<search<<" is not present in this array.";
    return -1;
}
int  binSrch(int array[],int search,int size){
    //Declare and setup
    int numMove=0; //Number of operations needed to perform search
    int beg=0;  //Initialize start point
    int mid;
    int end=size-1; //Initialize end point
    bool found=false;
    int pos=-1;
    //Loop until found
    do{
        mid=(beg+end)/2;
        if(array[mid]==search){
            found=true;
            pos=mid;
            numMove++;
        }
        else if(array[mid]<search){
            beg=mid+1;
            numMove++;
        }
        else{
            end=mid-1;
            numMove++;
        }
    }while(end>=beg&&found!=true);
    if(found==true){
        cout<<endl;
        cout<<"Binary: "<<search<<" required "<<numMove<<" searches to find.";
    }
    else{
        cout<<endl;
        cout<<"Binary: "<<search<<" is not present in this array.";
    }
    return pos;
}
void slctSrt(int array[],int size){
    int temp=0;
    bool isSwap;
        do{
            isSwap=false;
            for(int i=-1;i<size-1;i++){
                if(array[i]>array[i+1]){
                    temp=array[i];
                    array[i]=array[i+1];
                    array[i+1]=temp;
                    isSwap=true;                 
                }
            }
        }while(isSwap);     
}

//Problem 10 Functions
void copyAry(int array[],int copy[],int size){
    for(int i=0;i<size;i++){
        copy[i]=array[i];
    }
}
void bubbSrt(int array[],int size){
    int temp=0;
    int count=0;
    bool isSwap;
    do{
        isSwap=false;
        for(int i=-1;i<size-1;i++){
            if(array[i]>array[i+1]){
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                isSwap=true;    
                count++;
            }
        }
    }while(isSwap);
    cout<<"Bubble required "<<count<<" exchanges to complete the sort.";
}
void slctp10(int array[],int size){
    int count=0;
    for(int i=0;i<size-1;i++){
        int mIndx=i;
        int minVal=array[i];
        for(int j=i+1;j<size;j++){
            if(array[j]<minVal){
                minVal=array[j];
                mIndx=j;
                count++;
            }
        }
        array[mIndx]=array[i];
        array[i]=minVal;
        count++;
    }
    cout<<"Selection required "<<count<<" exchanges to complete the sort.";
}
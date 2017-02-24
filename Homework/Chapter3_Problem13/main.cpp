/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Format Output
#include <cstdlib>   //Random number generator
#include <ctime>     //Random seed

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int   USD=100; //Dollar conversion

//Function prototypes
void fillAry(float[],char); //Fills array with random values
void prntAry(float[],char); //Ouputs formatted array

float exchnge(float,float); //Converts USD to given currency

//Execution begins here
int main(int argc, char** argv) 
{
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
    cout<<endl;
    
    //Exit program
    return 0;
}

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
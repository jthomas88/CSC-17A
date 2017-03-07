/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on March 06, 2017, 10:30 PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random number generator
#include <ctime>     //Random seed
#include <fstream>   //File I/O


using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int MON=3;  //Number of months being recorded

//Function prototypes
void fillAry(char[][MON],int); //Fill array with random char values
void prntAry(char[][MON],int); //Output array

void wthrTly(char[][MON],string[],int); //Tallys weather patterns

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declare constants
    
    const int DAY=30; //Number of days per month being measured
    
    //Declare arrays
    char weather[DAY][MON]; //3 x 30 weather data array
    string months[MON]={"June","July","August"}; //Corresponding array of months
    
    //Declare file objects and open
    ofstream write;
    write.open("rainorshine.dat");
    
    //Fill array with random values
    fillAry(weather,DAY);
    
    //Output array
    prntAry(weather,DAY);
    
    //Calculate and output results
    wthrTly(weather,months,DAY);
    
    //Close file
    write.close();
    
    //Exit program
    return 0;
}

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
/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
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
const int MON=3; //Number of months being recorded

//Function prototypes
void fillAry(char[][MON],int); //Fill array with random char values
void prntAry(char[][MON],int); //Output array

void wthrTly(char[][MON],int); //Tallys weather patterns

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declare constants
    const int DAY=30; //Number of days per month being measured
    
    //Declare arrays
    char weather[DAY][MON];
    
    
    //Declare file objects and open
    ofstream write;
    write.open("rainorshine.dat");
    
    //Fill array with random values
    fillAry(weather,DAY);
    
    //Output array
    prntAry(weather,DAY);
    
    //Calculate and output results
    wthrTly(weather,DAY);
    
    //Close file
    //write.close();
    
    //Exit program
    return 0;
}

void fillAry(char a[][MON],int n){
    for(int i=0;i<MON;i++){
        for(int j=0;j<n;j++){
            do{
                char wthr=rand()%26+65;
                a[i][j]=wthr;
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

void wthrTly(char a[][MON],int n){
    int rain,clou,sunn=0; //Rain, Cloudy and Sunny counters
    for(int i=0;i<MON;i++){
        for(int j=0;j<n;j++){ 
            switch(a[i][j]){
                case 'R': rain++;break;
                case 'S': sunn++;break;
                case 'C': clou++;break;
            }            
        }
        cout<<"Sunny Days : "<<sunn<<endl;
        cout<<"Cloudy Days: "<<clou<<endl;
        cout<<"Rainy Days : "<<rain<<endl;
        cout<<endl;
        sunn=0;rain=0;clou=0;
    }
}

void mstRain(){
    
}
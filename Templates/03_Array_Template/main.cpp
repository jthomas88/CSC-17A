/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on November 17, 2016, 12:10 PM
 * Purpose: Calculate annual rainfall data
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random generator
#include <ctime>     //Random seed
#include <iomanip>   //Formatting

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int SIZE=12;     //Number of months in the year

//Function prototypes

//Fill and Print Functions
void fillAry(float[]);
void prntAry(string[],float[]);

//Search Functions
float findHig(float[],int&);
float findLow(float[],int&);

//Totaling functions
float sum(float[]);
float avg(float[]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
            
    //Declaration of variables
    int count=0; //Month array element assignment
    
    float  rainfl[SIZE]={};
    string months[SIZE]={"Jan","Feb","Mar","Apr",
                         "May","Jun","Jul","Aug",
                         "Sep","Oct","Nov","Dec"};
    
    //Fill Array
    fillAry(rainfl);
    
    //Output Array
    prntAry(months,rainfl);
    cout<<endl<<endl;
    
    //Find highest value and output
    findHig(rainfl,count);
    cout<<"Month with most rainfall: "<<months[count];
    cout<<" ("<<findHig(rainfl,count)<<"\")";
    cout<<endl;
    
    //Find lowest value and output
    findLow(rainfl,count);
    cout<<"Month with least rainfall: "<<months[count];
    cout<<" ("<<findLow(rainfl,count)<<"\")";
    cout<<endl;
    
    //Find total rainfall and output
    cout<<"Total annual rainfall: "<<sum(rainfl)<<"\"";
    cout<<endl;
    
    //Find average rainfall and output
    cout<<"Average monthly rainfall: "<<avg(rainfl)<<"\"";
    cout<<endl;
    
    //Process Values
    
    //Exit program
    return 0;
}

//Find Highest
float findHig(float array[],int &count){
    float high=0;
    for(int i=0;i<SIZE;i++){
        if(array[i]>high){
            high=array[i];
            count=i;
        }
    }
    return high;
}

//Find Lowest
float findLow(float array[],int &count){
    float high=0;
    float low=0;
    for(int i=0;i<SIZE;i++){
        if(array[i]>high){
            high=array[i];
        }
    }
    for(int i=0;i<SIZE;i++){
        if(array[i]<high){
            low=array[i];        
            high=low;
            count=i;
        }
    }
    return low;
}

//Fill Array
void fillAry(float array[]){
    int random;
    for(int i=0;i<SIZE;i++){
        random=rand()%200;
        array[i]=static_cast<float>(random)/100;
    }
}

//Print Array
void prntAry(string names[],float array[]){
    int count=0;
    for(int i=0;i<SIZE;i++){
        cout<<names[i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<setprecision(2)<<fixed<<array[i]<<' ';
    }
}

float sum(float array[]){
    float total=0;
    for(int i=0;i<SIZE;i++){
        total+=array[i];
    }
    return total;
}

float avg(float array[]){
    float average=0;
    for(int i=0;i<SIZE;i++){
        average+=array[i];
    }
    average=average/SIZE;
    return average;
}
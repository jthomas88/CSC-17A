/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random generator
#include <ctime>     //Random seed

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
float bmicalc(int,int);

//Execution begins here
int main(int argc, char** argv) 
{
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
    
    //Exit program
    return 0;
}

//BMI calculation function
float bmicalc(int hgt,int wgt){
    float bmi;               //Holds BMI value
    bmi=(wgt*703)/(hgt*hgt); //BMI calculation formula (weight*703/height^2)
    return bmi;              //Return calcualted BMI
}
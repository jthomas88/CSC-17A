/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
float adjust(float,int,int);

//Execution begins here
int main(int argc, char** argv) 
{
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
    
    //Exit program
    return 0;
}

float adjust(float ing,int yield,int orig){
    //Find yield for one cookie, then multiply by new yield
    float adj=(ing/orig)*yield; 
    //Output new yield
    return adj;
}
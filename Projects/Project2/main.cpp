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
enum Horizon{A,B,C,D,E,F,G,H,I,J};

//Function prototypes
void dispMap();

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    char map[6][J];
    
    //Display Map
    dispMap();
    
    //Exit program
    return 0;
}

void dispMap(){
    for(int i=0;i<6;i++){
        for(int j=0;j<=J;j++){
            cout<<"|  "<<' ';
            if(j==9)cout<<'|';
        }
        cout<<endl<<"-----------------------------------------"<<endl;
    }
}
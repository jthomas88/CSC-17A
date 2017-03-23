/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on March 22, 2017, 5:00 PM
 * Purpose: Movie Data
 */

//System Libraries
#include <iostream>  //Input/Output objects


using namespace std; //Namespace used in system library

//User libraries
#include "MovData.h"

//Global constants

//Function prototypes
void prntMov(MovData);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare variables
    MovData mov1,mov2;
    
    //Define objects
    mov1={"The Godfather","Francis Ford Coppola",1972,178};
    mov2={"The Room","Tommy Wiseau",2003,99};
    
    //Display Output
    prntMov(mov1);
    cout<<endl;
    prntMov(mov2);
    
    //Exit program
    return 0;
}

void prntMov(MovData movie){
    cout<<"Title:   "<<movie.title<<endl;
    cout<<"Directed by "<<movie.drctr<<endl;
    cout<<"Year:    "<<movie.year<<endl;
    cout<<"Runtime: "<<movie.runtm<<" mins."<<endl;
}
/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <fstream>

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    bool tst=1;
    int  poo=2340000;
    
    char *ptr1;
    char *ptr2;
    
    fstream file;
    
    //tst=reinterpret_cast<char*>(&tst);
    
    file.open("data.dat", ios::out|ios::binary);
    file.write(reinterpret_cast<char*>(&poo),sizeof(poo));
    file.close();
    
    poo=5;
    
    file.open("data.dat",ios::in|ios::binary);
    file.read(reinterpret_cast<char*>(&poo),sizeof(poo));
    cout<<poo;
    file.close();
    
    //Input Values
    
    //Process Values
    
    //Exit program
    return 0;
}
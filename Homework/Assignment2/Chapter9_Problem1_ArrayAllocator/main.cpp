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
int *getMem(int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare Variables
    int arraySz; //User defined array size
    
    //Input Values
    cout<<"Enter the desired array size: ";
    cin>>arraySz;
    
    //Allocate memory
    int *array=getMem(arraySz);
    
    //Display address
    cout<<endl;
    cout<<"The location of the array is: "<<array;
    
    //Free memory
    delete []array;
    
    //Exit program
    return 0;
}

int *getMem(int arraySz){
    int *ptr=0;
    ptr=new int[arraySz];
    for(int i=0;i<arraySz;i++){
        ptr[i]=i;
    }
    return ptr;
}
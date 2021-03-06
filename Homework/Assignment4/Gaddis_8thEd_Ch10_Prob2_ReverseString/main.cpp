/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: Reverse C-String
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstring>   //Character Array Functionality

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
void reverse(char *,int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Obtain string and assign to memory
    const int MAXSIZE=25;
    char *input;
    input=new char[MAXSIZE+1];
    
    //Receive value for string
    cout<<"Enter a string up to 10 characters in length: "<<endl;
    cin.getline(input,MAXSIZE);
    
    //Reverse string
    reverse(input,MAXSIZE);
    
    //Delete memory
    delete[]input;
    
    //Exit program
    return 0;
}

//Reverse String Function
void reverse(char *input,int n){
    for(int i=n-1;i>=0;i--){
        cout<<input[i];
    }
}
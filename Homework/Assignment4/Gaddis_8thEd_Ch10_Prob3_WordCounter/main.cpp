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
int wrdCnt(char *,int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Obtain string and assign to memory
    const int MAXSIZE=25;
    char *input;
    input=new char[MAXSIZE+1];
    
    //Receive value for string
    cout<<"Enter a string up to 25 characters in length: "<<endl;
    cin.getline(input,MAXSIZE);
    
    //Count words
    cout<<"Number of words: "<<wrdCnt(input,MAXSIZE);
    
    //Delete memory
    delete[]input;
    
    //Exit program
    return 0;
}

//Reverse String Function
int wrdCnt(char *input,int n){
    int count;
    input[0]!='\0'?count=1:count=0;
    for(int i=0;i<n-1;i++){
        if(input[i]=='\0'){
            return count;
        }
        if(input[i]==' '){
            count++;
        }
    }
    return count;
}
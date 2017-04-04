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
bool isValid(char *,int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Obtain string and assign to memory
    const int MAXSIZE=25;
    char *input;
    input=new char[MAXSIZE+1];
    
    
    //Receive value for string
    do{
        cout<<"Enter a string up to 25 characters in length: "<<endl;
        cin.getline(input,MAXSIZE);
        cout<<endl;
    }while(!isValid(input,MAXSIZE));
    cout<<"The password is valid."<<endl;
    
    
    //Count words
    
    
    //Delete memory
    delete[]input;
    
    //Exit program
    return 0;
}

//Reverse String Function
bool isValid(char *input,int n){
    int size=0;    
    bool isLn,isUp,isDg=0;    
    
    for(int i=0;i<n;i++){
        if(input[i]!='\0')size++;        
    }
    size>=6?isLn=true:cout<<"Password needs to be longer."<<endl;
    
    for(int i=0;i<n;i++){
        if(isupper(input[i]))isUp=true;
    }    
    if(isUp==0)cout<<"Needs at least one uppercase."<<endl;
    
    for(int i=0;i<n;i++){
        if(isdigit(input[i]))isDg=true;
    }
    if(isDg==0)cout<<"Needs at least one digit."<<endl;
    
    if(isLn==true&&isUp==true&&isDg==true){
        return true;
    }
    else{
        return false;
    }
}
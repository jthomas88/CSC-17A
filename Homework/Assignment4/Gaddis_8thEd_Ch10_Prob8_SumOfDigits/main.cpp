/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: Reverse C-String
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstring>   //Character Array Functionality
#include <cstdlib>   //ato1 function
#include <cmath>

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
int sumDig(char *,int);
int power(int,int);

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
    cout<<"Total: "<<sumDig(input,MAXSIZE);
    
    //Delete memory
    delete[]input;
    
    //Exit program
    return 0;
}

//Reverse String Function
int sumDig(char *input,int n){
    int total=0;
    int num;
    int size=0;
    
    for(int i=0;i<n;i++){
        if(input[i]!='\0')size++;
    }
    
    num=atoi(input);
    
    for(int i=0;i<size;i++){
        total+=num%(10);
        cout<<total<<endl;
        num/=10;
        cout<<num<<endl;
    }
    return total;
}

int power(int base,int exp){
    int power=base;
    for(int i=0;i<exp;i++){
        power*=base;
    }
    return power;
}
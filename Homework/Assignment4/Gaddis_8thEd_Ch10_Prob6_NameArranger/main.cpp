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
int vwlCnt(char *,int,int[]);
int cnsCnt(char *,int,int[]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Obtain string and assign to memory
    const int MAXSIZE=25;
    char *input;
    input=new char[MAXSIZE+1];
    
    int vowels[]={65,69,73,79,85,97,101,105,111,117}; //Vowel ASCII Codes
    
    //Receive value for string
    cout<<"Enter a string up to 25 characters in length: "<<endl;
    cin.getline(input,MAXSIZE);
    
    //Count words
    cout<<"Number of vowels: "<<vwlCnt(input,MAXSIZE,vowels);
    cout<<endl;
    cout<<"Number of consonants: "<<cnsCnt(input,MAXSIZE,vowels);
    
    //Delete memory
    delete[]input;
    
    //Exit program
    return 0;
}

//Reverse String Function
int vwlCnt(char *input,int n,int vowels[]){
    int count=0;
    for(int i=0;i<n-1;i++){
        if(input[i]=='\0'){
            return count;
        }
        for(int j=0;j<10;j++){
            if(input[i]==vowels[j])count++;
        }
    }
    return count;
}

int cnsCnt(char *input,int n,int vowels[]){
    int count=0;
    bool isVowel;
    for(int i=0;i<n-1;i++){
        isVowel=1;
        if(input[i]=='\0'){
            return count;
        }
        for(int j=0;j<10;j++){                
            input[i]!=vowels[j]?isVowel=0:isVowel=1;            
        }
        if(isVowel==0){
            count++;  
        }
    }
    return count;
}
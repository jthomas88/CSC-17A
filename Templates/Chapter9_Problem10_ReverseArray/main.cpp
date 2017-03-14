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
int  *getMem(int);
void prntAry(int *,int);
int  *revMem(int *,int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare variables
    int size=50;
    
    //Initialize Array
    int *array=getMem(size);
    
    //Output Array
    cout<<"Original Array: "<<endl;
    prntAry(array,size);
    cout<<endl;
    
    //Copy and Reverse Array
    int *paral=revMem(array,size);
    
    //Output Reversed Array
    cout<<"Reversed Array: "<<endl;
    prntAry(paral,size);
    
    //Delete Array
    delete []array;
    delete []paral;
    
    //Exit program
    return 0;
}

int *getMem(int n){
    int *a;
    a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=i%10; 
    }
    return a;
}

int *revMem(int *a,int n){
    int *b;
    b=new int[n];
    for(int i=0,j=n-1;i<n,j>=0;i++,j--){
        b[j]=a[i];
    }
    return b;
}

void prntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
        if(i%10==9)cout<<endl;
    }
}
/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on March 06, 2017, 10:30 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random Numbers
#include <ctime>     //Random Seed
#include <fstream>   //File I/O

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
void fillAry(int[],int);
void prntAry(int[],int);

int  linSrch(int[],int,int);
int  binSrch(int[],int,int);

void slctSrt(int [],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=100;
    int search=rand()%90+10;
    int array[SIZE]={};  //50 element array
    
    //Populate array with random elements
    fillAry(array,SIZE);
    cout<<endl;
    
    //Output array
    cout<<"Original Array"<<endl;
    prntAry(array,SIZE);
    cout<<endl;
    
    //Test efficiency of linear search
    linSrch(array,search,SIZE);
    cout<<endl;
    
    //Test efficiency of binary search
    slctSrt(array,SIZE);
    cout<<"Sorted Array"<<endl;
    prntAry(array,SIZE);
    binSrch(array,search,SIZE);
    
    //Exit program
    return 0;
}

void fillAry(int array[],int size){
    for(int i=0;i<size;i++){
        array[i]=rand()%90+10;
    }
}

void prntAry(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<' ';
        if(i%10==9)cout<<endl;
    }
}

int linSrch(int array[],int search,int size){
    for(int i=0;i<size;i++){
        if(search==array[i]){
            cout<<"Linear: "<<search<<" required "<<i+1<<" searches to find.";
            cout<<endl;
            return search;
        }
    }
    cout<<"Linear: "<<search<<" is not present in this array.";
    return -1;
}

int  binSrch(int array[],int search,int size){
    //Declare and setup
    int numMove=0; //Number of operations needed to perform search
    int beg=0;  //Initialize start point
    int mid;
    int end=size-1; //Initialize end point
    bool found=false;
    int pos=-1;
    //Loop until found
    do{
        mid=(beg+end)/2;
        if(array[mid]==search){
            found=true;
            pos=mid;
            numMove++;
        }
        else if(array[mid]<search){
            beg=mid+1;
            numMove++;
        }
        else{
            end=mid-1;
            numMove++;
        }
    }while(end>=beg&&found!=true);
    if(found==true){
        cout<<endl;
        cout<<"Binary: "<<search<<" required "<<numMove<<" searches to find.";
    }
    else{
        cout<<endl;
        cout<<"Binary: "<<search<<" is not present in this array.";
    }
    return pos;
}

void slctSrt(int array[],int size){
    int temp=0;
    bool isSwap;
        do{
            isSwap=false;
            for(int i=-1;i<size-1;i++){
                if(array[i]>array[i+1]){
                    temp=array[i];
                    array[i]=array[i+1];
                    array[i+1]=temp;
                    isSwap=true;                 
                }
            }
        }while(isSwap);     
}
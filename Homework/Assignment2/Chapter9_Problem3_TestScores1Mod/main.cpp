/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random generator
#include <ctime>     //Random Seed
#include <iomanip>   //Output format

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
int   *getMem(int);
void  prtScor(int,int *);
void  sortScr(int,int *);
float avg(int,int *);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declare Variables
    int arraySz; //User defined array size
    
    //Input Values
    cout<<"Enter the number of tests: ";
    cin>>arraySz;
    
    //Allocate memory
    int *array=getMem(arraySz);
    
    //Display unsorted scores
    cout<<"Unsorted list of scores: "<<endl;
    prtScor(arraySz,array);
    cout<<endl<<endl;
    
    //Sort Scores
    sortScr(arraySz,array);
    
    //Output sorted array
    cout<<"Sorted list of scores: "<<endl;
    prtScor(arraySz,array);
    cout<<endl<<endl;
    
    //Output average scores
    cout<<"Class Average w/ lowest score dropped: "
        <<fixed<<setprecision(2)<<avg(arraySz,array);
    
    //Free memory
    delete []array;
    
    //Exit program
    return 0;
}

int *getMem(int arraySz){
    int *ptr=0;
    ptr=new int[arraySz];
    for(int i=0;i<arraySz;i++){
        ptr[i]=rand()%100;
    }
    return ptr;
}

void prtScor(int arraySz,int *scores){
    for(int i=0;i<arraySz;i++){
        cout<<setw(2)<<right<<scores[i]<<' ';
        if(i%10==9)cout<<endl;
    }
}

void sortScr(int arraySz,int *scores){
    bool isSort;
    int  temp;
    do{
        isSort=false;
        for(int i=0;i<arraySz;i++){
            if(scores[i]>scores[i+1]){
                temp=scores[i];
                scores[i]=scores[i+1];
                scores[i+1]=temp;
                isSort=true;
            }
        }
    }while(isSort);    
}

float avg(int size,int *scores){
    float total=0;
    for(int i=1;i<size;i++){
        total+=scores[i];
    }
    return total/size-1;
}
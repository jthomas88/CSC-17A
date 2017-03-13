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
int    *getScr(int);
string *getNam(int);
void   prtScor(int,int *,string *);
void   sortScr(int,int *,string *);
float  avg(int,int *);

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
    int    *scores=getScr(arraySz);
    string *names =getNam(arraySz);
    
    //Display unsorted scores
    cout<<"Unsorted list of scores: "<<endl;
    prtScor(arraySz,scores,names);
    cout<<endl<<endl;
    
    //Sort Scores
    sortScr(arraySz,scores,names);
    
    //Output sorted array
    cout<<"Sorted list of scores: "<<endl;
    prtScor(arraySz,scores,names);
    cout<<endl<<endl;
    
    //Output average scores
    cout<<"Class Average w/ lowest score dropped: "
        <<fixed<<setprecision(2)<<avg(arraySz,scores);
    
    //Free memory
    delete []scores;
    delete []names;
    
    //Exit program
    return 0;
}

int *getScr(int arraySz){
    int *ptr=0;
    ptr=new int[arraySz];
    for(int i=0;i<arraySz;i++){
        ptr[i]=rand()%100;
    }
    return ptr;
}

string *getNam(int arraySz){
    char rndLtr;
    string *ptr=0;
    ptr=new string[arraySz];
    for(int i=0;i<arraySz;i++){
        rndLtr=rand()%26+48;
        ptr[i]=rndLtr;
    }
    return ptr;
}

void prtScor(int arraySz,int *scores,string *names){
    for(int i=0;i<arraySz;i++){
        cout<<names[i]<<": "<<setw(2)<<right<<scores[i]<<endl;
    }
}

void sortScr(int arraySz,int *scores,string *names){
    bool   isSort;
    int    temp;
    string tmpNm;
    
    do{
        isSort=false;
        for(int i=0;i<arraySz-1;i++){
            if(scores[i]>scores[i+1]){
                temp=scores[i];
                scores[i]=scores[i+1];
                scores[i+1]=temp;
                
                tmpNm=names[i];
                names[i]=names[i+1];
                names[i+1]=tmpNm;
                
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
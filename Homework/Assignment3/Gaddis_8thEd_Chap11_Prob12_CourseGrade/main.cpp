/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std; //Namespace used in system library

//User libraries
#include "Student.h"

//Global constants

//Function prototypes
void initAry(Student*,int,string[]);
void prntAry(Student*,int);
void destroy(Student[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Random Name Generator
    string names[]={"John","Joe","Sally","Tim","Maude",
                    "Mark","Luke","Mary","Victor","Louise",
                    "Henry","Claudius","Helena","Elaine","Joey"};
    
    //Declare random size of dynamic array
    int size=rand()%5+5;
    
    //Allocate Memory
    Student *array;
    array=new Student[size];
    
    //Initialize Array Values
    initAry(array,size,names);
    cout<<endl;
    
    //Output Array Data
    prntAry(array,size);
    
    //Destroy Test Array
    destroy(array,size);
    
    //Deallocate Memory
    delete []array;
    
    //Exit program
    return 0;
}

void initAry(Student *a,int n,string rndName[]){
    //Initialize Random Name and ID Number
    for(int i=0;i<n;i++){
        a[i].name=rndName[rand()%15];
        a[i].stuID=rand()%9000+1000;
    }
    //Initialize Random Test Scores
    for(int i=0;i<n;i++){
        a[i].tstSize=rand()%10+1;
        a[i].tests=new int [a[i].tstSize];
        for(int j=0;j<a[i].tstSize;j++){            
            a[i].tests[j]=rand()%100;
        }
    }
    //Find average
    for(int i=0;i<n;i++){
        float total=0;
        for(int j=0;j<a[i].tstSize;j++){            
            total+=a[i].tests[j];
        }
        a[i].avg=total/a[i].tstSize;
    }
    for(int i=0;i<n;i++){
        (a[i].avg>90)?a[i].grade='A':
        (a[i].avg>80)?a[i].grade='B':
        (a[i].avg>70)?a[i].grade='C':
        (a[i].avg>60)?a[i].grade='D':
                      a[i].grade='F';
    }
    
        
}

void prntAry(Student *a,int n){
    for(int i=0;i<n;i++){
        cout<<"Name: "<<a[i].name<<endl;
        cout<<"ID #: "<<a[i].stuID<<endl;
        cout<<"Test: ";
        for(int j=0;j<a[i].tstSize;j++){            
            cout<<a[i].tests[j]<<' ';
        }
        cout<<endl;
        cout<<"Avrg: "<<fixed<<setprecision(2)<<a[i].avg<<endl;
        cout<<"Grad: "<<a[i].grade<<endl;
        cout<<endl<<endl;
    }
}

void destroy(Student a[],int n){
    delete []a->tests;
}
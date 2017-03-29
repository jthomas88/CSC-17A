/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random number generator
#include <ctime>     //Random seed
#include <iomanip>   //I/O Format

using namespace std; //Namespace used in system library

//User libraries
#include "Student.h" //Student data struct

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
    
    //Declare random size of dynamic array (5-9)
    int size=rand()%5+5;
    
    //Allocate Memory
    Student *array;
    array=new Student[size];
    
    //Initialize Array Values
    initAry(array,size,names);
    
    //Output Array Data
    prntAry(array,size);
    
    //Destroy Test Array
    destroy(array,size);
    
    //Deallocate Memory
    delete []array;
    
    //Exit program
    return 0;
}

//Fill array with random values
void initAry(Student *a,int n,string rndName[]){
    //Initialize Random Name and ID Number
    for(int i=0;i<n;i++){
        a[i].name=rndName[rand()%15]; //Selects random name from list
        a[i].stuID=rand()%9000+1000;  //Random 4-digit ID
    }
    //Initialize Random Test Scores
    for(int i=0;i<n;i++){
        a[i].tstSize=rand()%10+1; //Random number of tests 1-10
        a[i].tests=new int [a[i].tstSize]; //Allocate memory for test scores
        for(int j=0;j<a[i].tstSize;j++){            
            a[i].tests[j]=rand()%100; //Assign each array element a score 0-99
        }
    }
    //Find average
    for(int i=0;i<n;i++){
        float total=0; //Initialize total to zero
        for(int j=0;j<a[i].tstSize;j++){            
            total+=a[i].tests[j]; //Add test scores to total
        }
        a[i].avg=total/a[i].tstSize; //Calculate average
    }
    //Determine letter grade
    for(int i=0;i<n;i++){
        (a[i].avg>90)?a[i].grade='A': //A for grade 90<x<100
        (a[i].avg>80)?a[i].grade='B': //B for grade 80<x<91
        (a[i].avg>70)?a[i].grade='C': //C for grade 70<x<81
        (a[i].avg>60)?a[i].grade='D': //D for grade 60<x<71
                      a[i].grade='F'; //F for grade  0<x<61
    } 
    
        
}

//Output Array
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

//Deallocate memory
void destroy(Student a[],int n){
    delete []a->tests;
}
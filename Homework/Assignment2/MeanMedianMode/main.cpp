/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
int  *genAry(int);
void prntAry(int,int *);
int  mean(int,int *);
int  median(int,int *);
void mode(int n, int *a);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declare Variable
    int size=99;
    
    //Initialize Array
    int *array=genAry(size);
    
    //Output Array
    cout<<"Original Array: "<<endl;
    prntAry(size,array);
    cout<<endl;
    
    //Find Mean
    cout<<"Mean of array: "<<mean(size,array);
    cout<<endl;
    
    //Find Median
    cout<<"Median of array: "<<median(size,array);
    cout<<endl;
    
    //Find Mode
    mode(size,array);
    
    //Delete Memory
    delete []array;
    
    //Exit program
    return 0;
}

int *genAry(int n){
    int *ptr=0;
    ptr=new int[n];
    for(int i=0;i<n;i++){
        ptr[i]=rand()%100;
    }
    return ptr;
}

void prntAry(int n,int *a){
    for(int i=0;i<n;i++){
        cout<<setw(2)<<right<<a[i]<<' ';
        if(i%10==9)cout<<endl;
    }
}

void sortAry(int n,int *a){
    bool isSort;
    int  temp;
    do{
        isSort=false;
        for(int i=0;i<n;i++){
            if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                isSort=true;
            }
        }
    }while(isSort);    
}

int mean(int n,int *a){
    int total=0;
    for(int i=0;i<n;i++){
        total+=a[i];
    }
    return total/n;
}

int median(int n,int *a){
    sortAry(n,a);
    if(n%2==1){
        return a[n/2+1];
    }
    else{
        return (a[n/2]+a[n/2+1])/2;
    }
}

void mode(int n, int *a){
    int unique=0;
    int counter=0;
    bool isSort;
    sortAry(n,a);
    //do{
        for(int i=0;i<n-1;i++){
        if(a[i]!=a[i+1]){
            unique=a[i];counter=0;cout<<"Unique number: "<<unique<<endl;
        }
        if(a[i]==a[i+1]){
            counter++;cout<<"Counter: "<<counter<<endl;
        }
    }
    //}while(isSort);
    
}
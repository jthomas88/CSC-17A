/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on March 23, 2017, 4:40 PM
 * Purpose: Customer Accounts
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std; //Namespace used in system library

//User libraries
#include "Acct.h"

//Global constants

//Function prototypes
Acct addAcct(Acct *,int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declare variables
    Acct *array;  
    int cho;
    int size=0; //Size of database
    
    //Declare Array
    array=new Acct[size];
    
    //Display Menu Options
    do{
        cout<<"1. Add account"<<endl;
        cout<<"2. Edit Account"<<endl;
        cout<<"3. Display Account"<<endl;
        cout<<endl;
        cin>>cho;
        
        switch(cho){
            case 1:
                addAcct(array,size);
                break;
            case 2:break;
            case 3:break;            
        }
    }while(cho!=0);
    
    //Delete Array
    delete []array;
    
    //Exit program
    return 0;
}

void dspAcct(){
    
}
void chgAcct(){
    
}
Acct addAcct(Acct *org,int size){
    //Declare variable
    int place=0;
    Acct *a=nullptr;    
    cout<<"place var succ"<<endl;
    //Add to size of array
    size++;    
    cout<<"size up succ"<<endl;
    //Create new array according to new size
    a=new Acct[size];
    cout<<"create new succ"<<endl;
    //Copy from old to new
    for(int i=0;i<size-1;i++){
        a[i].name=org[i].name;
        a[i].addr=org[i].addr;
        //a[i]->phon[i]=org[i]->phon[i];
        a[i].blnc=org[i].blnc;
        a[i].paid=org[i].paid;
        a[i].isFill=1;
    }
    cout<<"copy succ"<<endl;
    //Delete old smaller array
    delete[]org;
    cout<<"delete succ"<<endl;
    //Find new place in array
    for(int i=0;i<size;i++){
        if(a[i].isFill==1)place++;       
    }
    cout<<"find place succ"<<endl;    
    //Add account information to new entry
    cout<<"Enter the following as prompted"<<endl<<endl;
    cout<<"First and last name of the account holder:"<<endl;
    cin>>a[place].name;
    cout<<"Home Address: "<<endl;
    cin>>a[place].addr;
    cout<<"Phone Number: "<<endl;
    cin>>a[place].phon;
    cout<<"Current Balance: "<<endl;
    cin>>a[place].blnc;
    cout<<"Date Last Paid (MM/DD/YY): "<<endl;
    cin>>a[place].paid;
    //Return array with new entry
    return *a;
}
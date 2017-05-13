/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>
#include <iomanip>

#include "DivSale.h"  //Input/Output objects

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare constants
    const int QUAR=4; //Number of quarters in a year
    
    //Declaration of variables
    DivSale *region;  //Different regions of sales
    int   size;
    float sales;
    float total=0.0f;
    
    cout<<"Enter the number of sales regions: ";
    cin>>size;
    cout<<endl;
    
    region=new DivSale[size];
    
    //Input Values
    for(int i=0;i<size;i++){
        for(int j=0;j<4;j++){
            cout<<"Enter sales for region "<<i+1<<": ";
            cin>>sales;
            region[i].setQ(sales,j);      
            cout<<endl;
        }
        total+=region[i].getT();
    }
    
    
    //Output table
    for(int i=0;i<size;i++){
        cout<<"Region "<<i+1<<": ";
        for(int j=0;j<4;j++){
            cout<<fixed<<setprecision(2)<<setw(10)<<region[i].getQ(j);
        }
        cout<<endl;
    }
    
    cout<<endl;
    cout<<"Total: "<<total;
    
    //Delete memory
    delete []region;
    
    //Exit program
    return 0;
}
/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Output format

using namespace std; //Namespace used in system library

//User libraries
#include "Inventory.h"

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare object
    Inventory inv;
    //Declare Variables
    int   item,qty;
    float cost;
    //Input item number
    do{
        cout<<"Enter the item number: ";
        cin>>item;
        cout<<endl;
    }while(item<0);
    inv.setItem(item);
    //Input quantity
    do{
        cout<<"Enter the available quantity: ";
        cin>>qty;
        cout<<endl;
    }while(qty<0);
    inv.setQty(qty);
    //Input price per unit
    do{
        cout<<"Enter the cost per unit: ";
        cin>>cost;
        cout<<endl;
    }while(cost<0);
    inv.setCost(cost);
    //Calculate total
    inv.setTtl();
    //Output results
    cout<<"Item #  : "<<inv.getItem()<<endl;
    cout<<"Stock   : "<<inv.getQty()<<endl;
    cout<<"Per unit: $"<<fixed<<setprecision(2)<<inv.getCost()<<endl;
    cout<<"Total   : $"<<fixed<<setprecision(2)<<inv.getTtl()<<endl;
    //Exit program
    return 0;
}
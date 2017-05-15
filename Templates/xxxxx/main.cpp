/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    int num;
    
    //Input Data
    cout<<"Input a number 1-50"<<endl;
    cin>>num;
    
    //Map Inputs to Outputs and Process the Data
    if (num %2 !=0)
    {
        num = (num/2)+1;
    }
    else
    {
        num /=2;
    }
    for (int linnm=0; linnm<num; linnm++)
    {
        for (int i=0; i<=linnm;i++)
            cout<<" ";
            cout<<'*';
        
            
        for (int x= (num-linnm) *2; x>1; x--)
            cout<<" ";
        cout<<'*'<<endl;
        
            
    }
    
    //Exit program
    return 0;
}
/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <fstream>


using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    fstream comp;
    int count=0;
    int cho;
    
    //Open file
    
    
    string line;
    
    
    cout<<"Please enter the file name of the poem you'd like to view."<<endl;
    cout<<"Files to choose from: "<<endl;
    cout<<"poem1.txt - A Clear Midnight by Walt Whitman"<<endl;
    cout<<"poem2.txt - Bacchus by Ralph Waldo Emerson"<<endl;
    cout<<"poem3.txt - Electra on Azalea Path by Sylvia Plath"<<endl;
    cout<<"poem4.txt - The Road not Taken by Robert Frost"<<endl;
    cout<<"poem5.txt - Sick by Shel Siverstein"<<endl;
    cin>>line;
    cin.ignore();
    comp.open(line.c_str());
    
    cout<<endl<<endl;
    
    while(comp){
        getline(comp,line);
        cout<<line<<endl;
        count++;
        if(count==20){      
            cout<<"(STRIKE A KEY TO CONTINUE READING)"<<endl;
            cin.ignore();            
            count=0;
        }        
    }
    
    //Close file
    comp.close();
    
    //Exit program
    return 0;
}
/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random generator
#include <ctime>     //Random seed

using namespace std; //Namespace used in system library

//User libraries
#include "Coin.h"
//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    //Declaration of variables
    Coin quar,nick,dime;
    int tot=0; //Total money user has
    //Set values
    quar.setVal(25);
    dime.setVal(10);
    nick.setVal(5);
    //Start game
    
    do{
        cout<<"Press ENTER to flip the coins."<<endl;
        cin.ignore();
        
        if(quar.toss()==1){
            tot+=quar.getVal();
            cout<<"Quarter flipped heads. You gained 25 cents."<<endl;
        }
        if(dime.toss()==1){
            tot+=dime.getVal();
            cout<<"Dime flipped heads. You gained 10 cents."<<endl;
        }
        if(nick.toss()==1){
            tot+=nick.getVal();
            cout<<"Nickel flipped heads. You gained 5 cents."<<endl;
        }
        cout<<"Your end of turn total is: "<<tot<<" cents."<<endl;
    }while(tot<100);
    
    if(tot==100){
        cout<<"Congratulations! You win!"<<endl;
    }
    else{
        cout<<"Sorry! You lose!"<<endl;
    }
    
    //Exit program
    return 0;
}
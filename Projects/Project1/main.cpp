/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//User libraries
#include "Lemming.h"

//Global constants

//Function prototypes
void initSts(Lemming,int,int,float);

int divide(Lemming,Lemming);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare lemmings
    Lemming player;
    Lemming enemy;
    cout<<'a';
    
    //Initialize values
    initSts(player,50,1,0.5f);
    initSts(enemy,10,1,0.5f);
    cout<<'b';
    
    //Initial Memory Allocation
    player.army=new int[player.size];
    enemy.army=new int[enemy.size];
    cout<<'c';
    
    //Division Phase
    if(player.size>=enemy.size)divide(player,enemy);
    cout<<'d';
    
    //Combat Phase
    
    //Regroup Phase
    
    //Delete Arrays
    delete player.army;
    delete enemy.army;
    cout<<'e';
            
    //Exit program
    return 0;
}

void initSts(Lemming l,int size, int power, float dodge){
    l.size=size;
    l.ppL=power;
    l.dodge=dodge;
}

int divide(Lemming pl,Lemming en){
    int squad;
    
    do{
        cout<<"Your Army : "<<pl.size<<" units"<<endl;
        cout<<"Enemy Army: "<<en.size<<" units"<<endl;
        cout<<"You may have a squad of up to "
            <<pl.size/en.size<<" for this battle."<<endl;  
        cout<<"Input squad size: "<<endl;
        cin>>squad;
        if(squad>pl.size/en.size)cout<<"Refer to your maximum squad size and "
                                     <<"input a valid number."<<endl;
        else if(squad<1)cout<<"Squad size must be at least 1."<<endl;
        else cout<<"You have selected a squad size of "<<squad;
    }while(squad<=pl.size/en.size&&squad<1);
    
    return squad;
}
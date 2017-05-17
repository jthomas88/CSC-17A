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
#include "Player.h"
//Global constants
enum Horizon{A,B,C,D,E,F,G,H,I,J};

//Function prototypes
void dispMap(char[][10]);
void fillMap(char[][10]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare objects 
    Player player;
    //Declaration of variables
    char map[6][J+1]={};
    
    //Fill Map
    fillMap(map);
    
    //Display Map
    dispMap(map);
    
    //Set Point
    player.buyLand(map);
    
    //Display Map
    dispMap(map);
    
    //Exit program
    return 0;
}

void fillMap(char map[][10]){
    for(int i=0;i<6;i++){
        for(int j=0;j<=J;j++){
            map[i][j]=' ';
        }
    }
}

void dispMap(char map[][10]){
    for(int i=0;i<6;i++){
        for(int j=0;j<=J;j++){
            cout<<"| "<<map[i][j]<<' ';
            if(j==9)cout<<'|';
        }
        cout<<endl;
    }
}
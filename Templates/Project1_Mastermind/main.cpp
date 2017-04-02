/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>
#include <ctime>

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
void genCode(char[]);
void dspCode(char[]);
char guess(int,char[],char[][10]);

char check(char[],char[],char[]);
void dspPins(char[][10],char[]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    char hist[4][10]={};
    
    char code[4]={};
    char gues[4]={};
    char pins[4]={'-','-','-','-'};
    
    int turn=1;
    
    //Generate Code
    genCode(code);
    
    //Output HUD
    cout<<"X X X X"<<endl<<endl;
    
    //Display Code
    dspCode(code);
    cout<<endl<<endl;
    
    for(int i=0;i<10;i++){
        //Prompt user for guess
        guess(turn,gues,hist);

        //Check answer
        check(pins,code,gues);

        //Output Answer
        dspPins(hist,pins);
        
        //Increment turn
        turn++;
    }
    
    //Exit program
    return 0;
}

void genCode(char code[]){
    for(int i=0;i<4;i++){
        code[i]=rand()%10+48;
    }
}
void dspCode(char code[]){
    for(int i=0;i<4;i++){
        cout<<code[i]<<' ';
    }
}
void dspPins(char hist[][10],char pins[]){
    for(int i=9;i>=0;i--){
        for(int j=0;j<4;j++){
            //cout<<hist[j][i]<<' ';
            cout<<pins[j]<<' ';
        }
        cout<<endl<<endl;
    }
}

char guess(int turn,char gues[],char hist[][10]){
    cin>>gues;
    for(int i=9;i>=0;i--){
        for(int j=0;j<4;j++){
            hist[j][turn-1]=gues[j];
        }
    }
    return *gues;
}
char check(char pins[],char code[],char gues[]){
    int count=0;
    while(count<4){
        for(int i=0;i<4;i++){
            if(code[count]==gues[i]){
                pins[i]='X';
            }
        }
        count++;
    }
    for(int i=0;i<4;i++){
        if(code[i]==gues[i]){
            pins[i]='O';
        }
    }    
}


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
#include <fstream>
#include <string>
#include <cstring>

using namespace std; //Namespace used in system library

//User libraries
#include "Lemming.h"
#include "Hud.h"

//Global constants
const int PERCENT=100;

//Function prototypes
void initSts(Lemming&,int,char,float);
void initLif(Lemming&);
Hud  initHud(Hud&);

void startOp(Hud&,Lemming&);
void prntIns(char[]);

void battle(Lemming&,Lemming,Hud&,int);
void divide(Lemming&,Lemming&);
void combat(Lemming&,Lemming&);
Hud  plunder(Hud&,Lemming,Lemming,int);
void regrou(Lemming&);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declare Variables
    int  cho;
    int  day=1;
    char file[]="instructions.dat";
    
    //Declare lemmings
    Lemming player;
    Lemming enemy;
    
    //Declare HUD
    Hud hud;
    
    //Initialize values
    initSts(enemy,10,4,0.5f);
    
    //Initial Memory Allocation   
    enemy.isDead=new bool[enemy.size];
    
    //Set all lemmings to 'alive'
    initLif(enemy);
    
    //Display title screen
    
    //Display Options
    do{
        cout<<"1. New Game"<<endl;
        cout<<"2. Load Game"<<endl;
        cout<<"3. Instructions"<<endl;
        cin>>cho;
        if(cho>3||cho<1)cout<<"Invalid option!"<<endl;
        
        switch(cho){
        case 1: 
            //Introduction
            initHud(hud);
            startOp(hud,player);        
            break;
        case 2:
            //loadGam();
            break;
        case 3:
            //Display Instructions
            prntIns(file);
            cout<<endl;
            break;
        }
        
    }while(cho>2||cho<1);
    
    
    
    //Display Menu
    do{
        //Display HUD and options
        do{
        cout<<"Day "<<day<<endl;
        cout<<"Troops: "<<player.size<<endl;
        cout<<"Gold  : "<<hud.gold<<endl;
        cout<<"Food  : "<<hud.food<<endl;
        cout<<"Morale: "<<hud.morale<<endl;
        cout<<endl;
        cout<<"1. Next Battle"<<endl;
        cout<<"2. Marketplace"<<endl;
        cout<<"3. Rest"<<endl;
        cin>>cho;
        }while(cho>3||cho<1);
        
        //Option Branches
        switch(cho){
        case 1:
            //Commence Battle
            battle(player,enemy,hud,day);
            break;
        case 2:
            //market();
            break;
        case 3:
            //rest();
            break;
        default:
            cout<<"Invalid choice"<<endl;
        }    
        
        //Increment in-game day
        day++;
        
        //Save Progress
        //saveGam();
    }while(player.size>0);
    
    
    
    
    
    //Delete Arrays
    delete []player.isDead;
    delete []enemy.isDead;
            
    //Exit program
    return 0;
}

//Initializers
void initSts(Lemming &l,int size,char gift,float dodge){
    l.size=size;
    l.gift=gift;
    l.dodge=dodge;
}
void initLif(Lemming &l){
    for(int i=0;i<l.size;i++){
        l.isDead[i]=0;        
    }
}
Hud  initHud(Hud &h){
    h.gold=100;
    h.food=100;
    h.morale=0.0f;
    
    return h;
}

//Introduction Function
void startOp(Hud &h,Lemming &l){    
    int cho;
    
    cout<<"Greetings!"<<endl<<endl;
    cout<<"You have been selected to spearhead our new"<<endl
        <<"military project! You will be granted "<<h.gold<<" gold as"<<endl
        <<"a starting grant. Use as you'd like! But remember that"<<endl
        <<"this is all you're getting from us. You'll have to get"<<endl
        <<"more money on your own. In any case, good luck commander!"<<endl
        <<"Make us proud."<<endl<<endl;
    cout<<"~ Project LEMMING"<<endl<<endl;

    //Prompt User for Initial Army Size
    do{
        cout<<"How many lemmings will you purchase? (5 Gold/Lemming)"<<endl;
        cin>>l.size;
    }while(l.size<1&&l.size>h.gold/5);
    //Subtract price from total
    h.gold-=(l.size*5);
    
    do{
        cout<<"Select a gift:"<<endl;
        cout<<"1. Luck O' The Irish (Starting gold+,Gold find+)"<<endl;
        cout<<"2. Band of Brothers(Morale boosts+,Morale decrease-)"<<endl;
        cout<<"3. Party Animals (Rest Bonus+)"<<endl;
        cout<<"4. I don't like gifts."<<endl;
        cin>>cho;
    }while(cho>4||cho<1);
    
    //Initialize player with declared army size
    initSts(l,l.size,cho,0.5f);
    
    //Initial player memory allocation
    l.isDead=new bool[l.size];
    
    //Set all lemmings to 'alive'
    initLif(l);
    
    //Display Confirmation 
    cout<<"You will start with "<<l.size<<" lemmings."<<endl;
        
}

//Output Functions
void prntIns(char file[]){
    string line;
    ifstream read;
    read.open(file);
    getline(read,line);
        while(getline(read,line)){
            cout<<line<<endl;
        }
    read.close();
}

//Battle Phases
void battle(Lemming &player,Lemming enemy,Hud &h,int day){
    do{
        //Division Phase
        cout<<"Division Phase"<<endl;
        if(player.size>=enemy.size)divide(player,enemy);
        cout<<endl<<endl;

        //Combat Phase
        cout<<"Combat Phase"<<endl;
        combat(player,enemy);
        cout<<endl<<endl;

        //Plunder Phase
        plunder(h,enemy,player,day);
        
        //Regroup Phase
        regrou(player);
        regrou(enemy);

    }while(player.size!=0&&enemy.size!=0);
}
void divide(Lemming &pl,Lemming &en){
    do{
        cout<<"Your Army : "<<pl.size<<" units"<<endl;
        cout<<"Enemy Army: "<<en.size<<" units"<<endl;
        cout<<"You may have a squad of up to "
            <<pl.size/en.size<<" for this battle."<<endl;  
        cout<<"Input squad size: "<<endl;
        cin>>pl.squad;
        if(pl.squad>pl.size/en.size){
            cout<<"Refer to your maximum squad size and "
                <<"input a valid number."<<endl;
        }
        else if(pl.squad<1){
            cout<<"Squad size must be at least 1."<<endl;
        }
        else{
            cout<<"You have selected a squad size of "<<pl.squad;
        }
    }while(pl.squad>(pl.size/en.size)||pl.squad<1);
    en.squad=1;
}
void combat(Lemming &pl,Lemming &en){
    int count=0;
    int pdef=0;
    int edef=0;
    pl.defeat=0;
    en.defeat=0;    

    for(int i=0;i<en.size;i++){
        cout<<"Squad "<<i+1<<" begin"<<endl;
        do{            
            //Roll for FS (0=player FS,1=enemy FS)
            if(rand()%2==0){
                cout<<"Player strikes first!"<<endl;
                if(en.dodge*100>rand()%100){
                    cout<<"Attack from player missed!"<<endl;
                }
                else{
                    cout<<"Attack successful!"<<endl;
                    en.isDead[i]=1;
                    edef++;
                }
            }
            else{
                cout<<"Enemy strikes first!"<<endl;
                if(en.dodge*100>rand()%100){
                    cout<<"Attack from Enemy missed!"<<endl;
                }
                else{
                    cout<<"Attack successful!"<<endl;
                    pl.isDead[i*pl.squad+count]=1;
                    pdef++;
                }
            }
            count++;
        }while((edef<en.squad&&pdef<pl.squad)&&count<pl.squad);
        cout<<endl;
       
        pl.defeat+=pdef;
        en.defeat+=edef;
        
        count=0;
        pdef=0;
        edef=0;
    }     
   
    cout<<endl;    
    cout<<"Status Report: "<<endl;
    cout<<"Player Casualties: "<<pl.defeat<<endl;
    cout<<"Enemy Casualties : "<<en.defeat<<endl;
    cout<<endl;
    
    cout<<"Key: 0 = alive, 1 = dead"<<endl<<endl;
    
    cout<<"Player Army"<<endl;
    for(int i=0;i<pl.size;i++){
        cout<<pl.isDead[i];
        if(i%50==49)cout<<endl;
    }
    cout<<endl;
    
    cout<<"Enemy Army"<<endl;
    for(int i=0;i<en.size;i++){
        cout<<en.isDead[i];
        if(i%50==49)cout<<endl;
    }
    cout<<endl;
    
}
void regrou(Lemming &l){
    //Initialize counter
    int count=0;
    //Check for dead lemmings
    for(int i=0;i<l.size;i++){
        if(l.isDead[i]==0)count++;
    }
    //Set new army size
    l.size=count;
    //Delete old array
    delete []l.isDead;
    //Initialize new array with new size
    l.isDead=new bool[count];
    //Set all new lemmings to 'alive'
    for(int i=0;i<l.size;i++){
        l.isDead[i]=0;
    }
}
Hud plunder(Hud &h,Lemming en,Lemming pl,int day){
    for(int i=0;i<en.defeat;i++){
        h.food+=rand()%(day*5);
        h.gold+=rand()%(day*5);
        h.morale+=static_cast<float>(en.defeat)/100;
        h.morale-=static_cast<float>(pl.defeat)/100;
    }
    return h;
}

//Enemy Function
Lemming enemy(){
    
}
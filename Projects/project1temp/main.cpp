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
#include "Lemming.h"

//Global constants

//Function prototypes
void initSts(Lemming&,int,int,float);
void initLif(Lemming&);

void divide(Lemming&,Lemming&);
void combat(Lemming&,Lemming&);
void regrou(Lemming&);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declare lemmings
    Lemming player;
    Lemming enemy;
    
    //Initialize values
    initSts(player,50,1,0.5f);
    initSts(enemy,10,1,0.5f);
    
    //Initial Memory Allocation
    player.isDead=new bool[player.size];    
    enemy.isDead=new bool[enemy.size];
    
    //Set all lemmings to 'alive'
    initLif(player);
    cout<<endl;
    initLif(enemy);
    cout<<endl;
    
    //Initiate Battle
    do{
        //Division Phase
        cout<<"Division Phase"<<endl;
        if(player.size>=enemy.size)divide(player,enemy);
        cout<<endl<<endl;

        //Combat Phase
        cout<<"Combat Phase"<<endl;
        combat(player,enemy);
        cout<<endl<<endl;

        //Regroup Phase
        regrou(player);
        regrou(enemy);
        
    }while(player.size!=0&&enemy.size!=0);
    
    //Delete Arrays
    delete []player.isDead;
    delete []enemy.isDead;
            
    //Exit program
    return 0;
}

//Initializers
void initSts(Lemming &l,int size, int power, float dodge){
    l.size=size;
    l.ppL=power;
    l.dodge=dodge;
}
void initLif(Lemming &l){
    for(int i=0;i<l.size;i++){
        l.isDead[i]=0;        
    }
}



//Battle Phases
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
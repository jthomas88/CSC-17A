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

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int SIZE=10; //Size of 2D Array

//Function prototypes
void genCode(char[]);

void dspCode(char[]);
void dspPins(char[][SIZE],char[][SIZE]);
void dspTtl(char[]);

char guess(int,char[],char[][SIZE]);
char ai(int,char[],char[][SIZE],char[][SIZE]);

char check(char[][SIZE],char[],char[],int);
void sortPin(char[][SIZE],int);

bool isDupe(char[]);
bool isWin(char[][SIZE],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    int  turn=1; //Counter for which number guess the player is on
    char temp;   //Placeholder for start menu input
    
    //Declare Reset Color Buffer Code
    string reset="\033[0m";
    
    //Declare file name
    char file[]="title.txt";
    
    //Declare arrays 
    char hist[4][SIZE]={};              //Array holding previous guesses
    char code[4]={'1','1','3','1'};     //Computer generated answer code
    char gues[4]={};                    //User generated guess
    char trak[4]={'0','0','0','0'}; 
    char pins[4][SIZE]={'-','-','-','-',//Pins to determine correct or incorrect
                      '-','-','-','-',
                      '-','-','-','-',
                      '-','-','-','-',
                      '-','-','-','-',
                      '-','-','-','-',
                      '-','-','-','-',
                      '-','-','-','-',
                      '-','-','-','-',
                      '-','-','-','-'};
     
    //Output Game Title
    dspTtl(file);
    
    //Prompt user with instructions and input
    cout<<"The computer will generate a random nonrepeating 4-digit code"<<
    endl<<"containing numbers 1-6"<<endl<<endl;
    cout<<"You have 10 attempts to crack the code."<<endl<<endl;
    cout<<"Press ENTER to start"<<endl;
    cin.get(temp);
    
    //Generate Code
    //for(int i=0;i<100;i++){
    //    genCode(code);   
        dspCode(code);
        cout<<endl;
    //}
    
    for(int i=0;i<SIZE;i++){
        //Output HUD
        cout<<" ?  ?  ?  ? "<<endl<<endl;
        
        //Output Game Board
        dspPins(hist,pins);
        
        //Prompt user for guess
        cout<<"Enter your guess:"<<endl;
        //ai(turn,trak,pins,hist);
        guess(turn,gues,hist);

        //Check answer
        check(pins,code,gues,turn);
        
        //Sort pins so as to not give away answer
        sortPin(pins,turn);
        
        //Reset color buffer
        cout<<reset;
        
        //Check if game is won
        if(isWin(pins,turn)==0){
            cout<<"A winner is you!"<<endl;
            cout<<"You cracked the code in "<<turn<<" guesses!"<<endl;
            return isWin(pins,turn);
        }
        
        //Increment turn
        turn++;
        
        //Make space
        cout<<endl<<endl<<endl<<endl
            <<endl<<endl<<endl<<endl;
    }
    //Display loser message
    if(isWin(pins,turn)==1){
        cout<<"Loser!"<<endl;
        cout<<"The code was: "<<endl;
        dspCode(code);
        cout<<reset;
    }
    
    //Exit program
    return 0;
}

//Generator functions
void genCode(char code[]){
    for(int i=0;i<4;i++){
        //Generate random character 1-7
        code[i]=rand()%10+48;
    }
}
//Truth functions
bool isDupe(char code[]){
    //Return value
    bool dupe;   
    //Compare each value against each successive value in the code
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            //Indicate there is a duplicate if there is one present
            if(code[i]==code[j])dupe=true;
        }
    }
    //Return T/F
    return dupe;
}
bool isWin(char pins[][SIZE],int turn){
    //Set default to !win
    bool win=1;
    //Check if each value is correct
    for(int i=0;i<4;i++){
        //If all correct set bool to win
        if(pins[i][turn-1]=='O'){
            win=0;
        }
        //Otherwise, keep !win
        else{
            win=1;
        }
    }
    //Return T/F
    return win;
}
//Display functions    
void dspCode(char code[]){
    string col;   //Color code corresponding to number inputted
    string color; //Color code template
    
    for(int i=0;i<4;i++){
        //col=code[i]; //Set code to corresponding number
        //color="\033[4"+col+"m"; //Set color
        //cout<<color<<' '<<code[i]<<' '; //Output number and bg color
        cout<<code[i]<<' ';
    }
}
void dspPins(char hist[][SIZE],char pins[][SIZE]){
    string col;             //Color code corresponding to number inputted
    string color;           //Color code template
    string reset="\033[0m"; //Reset color buffer code
    //Output pins
    for(int i=9;i>=0;i--){
        for(int j=0;j<4;j++){
            //Assign color for X or O
            if(pins[j][i]=='O')col="1";
            if(pins[j][i]=='X')col="7";
            //Set color to template
            color="\033[4"+col+"m";
            //Output pin with bg color
            if(pins[j][i]!='-'){
                cout<<color<<' '<<pins[j][i]<<' ';
                //Reset color buffer
                cout<<reset;
            }
            //Output default pin value w/o color
            else{
                cout<<' '<<pins[j][i]<<' ';
            }
        }
        
        //Reset color buffer
        cout<<reset;
        
        //Output code
        for(int j=0;j<4;j++){
            //Assign color for corresponding number
            col=hist[j][i];
            //Set color to template
            color="\033[4"+col+"m";
            //Output number with bg color
            if(hist[j][i]>'0'){
                cout<<color<<' '<<hist[j][i]<<' ';
                //Reset color buffer
                cout<<reset;
            }
            //Output default number value w/o color
            else{
                cout<<' '<<hist[j][i]<<' ';
            }
        }
        
        //Reset color buffer
        cout<<reset;
        cout<<endl<<endl;
    }
}
void dspTtl(char file[]){
    string line;   //String to hold line
    ifstream read; //File stream object
    //Open file
    read.open(file);
    //Get first line
    getline(read,line);
    //Output for as long as there is data to be read
    while(getline(read,line)){
        cout<<line<<endl;
    }
    //Close file
    read.close();
}
//Game process functions
char guess(int turn,char gues[],char hist[][SIZE]){
    //Input answer
    cin>>gues;
    //Assign guess to current spot on 'previous guesses' array
    for(int i=9;i>=0;i--){
        for(int j=0;j<4;j++){
            hist[j][turn-1]=gues[j];
        }
    }
    //Return guessed value
    return *gues;
}
char check(char pins[][SIZE],char code[],char gues[],int turn){
    //Check for correct numbers in incorrect spot
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(code[i]==gues[j]){
                pins[j][turn-1]='X';
                j=4;
            }
        }      
    }
    
    sortPin(pins,turn);
    
    //Check for correct number/correct spot
    for(int i=0;i<4;i++){
        if(code[i]==gues[i]){
            pins[i][turn-1]='O';
        }
    }    
}
void sortPin(char pins[][SIZE],int turn){
    char temp; //Temporary holder variable
    
    //Sort '-' to the back
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(pins[j][turn-1]=='-'){
                temp=pins[j+1][turn-1];
                pins[j+1][turn-1]=pins[j][turn-1];
                pins[j][turn-1]=temp;
            }
        }
    }
    //Sort 'O' to come before 'X'
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(pins[j][turn-1]=='X'&&pins[j+1][turn-1]=='O'){
                temp=pins[j+1][turn-1];
                pins[j+1][turn-1]=pins[j][turn-1];
                pins[j][turn-1]=temp;
            }
        }
    }
}


/*
char ai(int turn,char trak[],char pins[][SIZE],char hist[][SIZE]){
    //Input answer
    if(turn==1){
        for(int i=0;i<4;i++){
            trak[i]++;
        }
    }
    if(turn>1){
        for(int i=0;i<4;i++){
            if(pins[i][turn-2]=='-'){
                trak[i]++;
            }
            if(pins[i][turn-2]=='X'){
                //trak[i+1]
            }
        }
    }
   
    if(turn==1){
        trak[0]++;
        trak[1]++;
        trak[2]++;
        trak[3]++;
    }
    if(pins[0][turn-2]=='-'&&turn>1){
        trak[0]++;
        trak[1]++;
        trak[2]++;
        trak[3]++;
    }
    if(pins[0][turn-2]=='O'){
        trak[1]++;
        trak[2]++;
        trak[3]++;
    }
    if(pins[0][turn-2]=='X'){
        char temp;
        temp=trak[0];
        trak[0]=trak[1];
        trak[1]=temp;
    }

    //Assign guess to current spot on 'previous guesses' array
    for(int i=9;i>=0;i--){
        for(int j=0;j<4;j++){
            hist[j][turn-1]=trak[j];
        }
    }
    //Return guessed value
    return *trak;
}
 * */
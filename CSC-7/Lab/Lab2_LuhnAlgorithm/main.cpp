/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on March 14, 2017, 11:00 PM
 * Purpose: Lab 2 Luhn Algorithm
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random Generator
#include <ctime>     //Random Seed
#include <iomanip>   //Output Format

using namespace std; //Namespace used in system library

//User libraries
#include "CrdCard.h" //Credit Card Structure

//Global constants
const int PERCENT=100; //Percent conversion

//Function prototypes
void genCC(CrdCard,char []);   //Generates valid credit card number
void flipDig(CrdCard,char []); //Randomly changes one digit in card number
bool validCC(CrdCard,char[]);  //Checks for valid number within genCC
bool validFp(CrdCard,char[]);  //Checks for valid number after number flip

void prntCC(CrdCard,char[]);   //Outputs card number

void cnsldt(CrdCard,char[]);   //Combines double digit numbers
void dblDig(CrdCard,char[]);   //Doubles value of every other number

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    int repeat=10000;            //Number of iterations of loop
    int choice;                  //Selection of credit card type
    int valid=0;                 //Counter of valid numbers
    CrdCard visa,amex,mscd,disc; //4 different card types
    
    //Define Cards
    //Set card number length
    visa.length=16;
    mscd.length=16;
    disc.length=16;
    amex.length=15;
    //Set starting digit
    visa.startDg='4';
    mscd.startDg='5';
    disc.startDg='6';
    amex.startDg='3';
    
    //Define Arrays
    char visaCrd[visa.length];
    char mscdCrd[mscd.length];
    char discCrd[disc.length];
    char amexCrd[amex.length];
    
    //Select card type to test
    cout<<"Select a card type:"<<endl<<endl;
    cout<<"1. Visa"<<endl;
    cout<<"2. MasterCard"<<endl;
    cout<<"3. Discover"<<endl;
    cout<<"4. American Express"<<endl;
    
    //Begin test
    do{
        //Prompt for input
        cin>>choice;
        //Branch to selected card type
        switch(choice){
            //Visa
            case 1:
                //Loop 10,000 times
                for(int i=0;i<repeat;i++){
                    //Generate valid number
                    genCC(visa,visaCrd);
                    //Flip random digit
                    flipDig(visa,visaCrd);
                    //If card is valid, tally up valid counter
                    if(validFp(visa,visaCrd)==0)valid++;
                }
                break;
            //MasterCard
            case 2:
                for(int i=0;i<repeat;i++){
                    genCC(mscd,mscdCrd);
                    flipDig(mscd,mscdCrd);
                    if(validFp(mscd,mscdCrd)==0)valid++;
                }
                break;
            //Discover    
            case 3:
                for(int i=0;i<repeat;i++){
                    genCC(disc,discCrd);
                    flipDig(disc,discCrd);
                    if(validFp(disc,discCrd)==0)valid++;
                }
                break;
            //American Express    
            case 4:
                for(int i=0;i<repeat;i++){
                    genCC(amex,amexCrd);
                    flipDig(amex,amexCrd);
                    if(validFp(amex,amexCrd)==0)valid++;
                }
                break;
        }
    }while(choice<0&&choice>=4); //Test for valid input
    
    //Calculate percent valid
    float pctVal=static_cast<float>(valid)/static_cast<float>(repeat);
    
    //Output Results
    cout<<"Number of valid cards  : "<<valid<<endl;
    cout<<"Number of invalid cards: "<<repeat-valid<<endl;
    cout<<"Percent valid          : "<<fixed<<setprecision(2)<<pctVal*PERCENT<<endl;

    //Exit program
    return 0;
}

void prntCC(CrdCard cc,char ccnum[]){
    for(int i=0;i<cc.length;i++){
        cout<<ccnum[i];
    }
}
void genCC(CrdCard cc,char ccnum[]){
    bool isValid; //Check if number is valid
    char testcc[cc.length]; //Copy of original credit card number array
    ccnum[0]=cc.startDg;  //Initialize starting digit on original number
    testcc[0]=cc.startDg; //Initialize starting digit on copy
    do{
        for(int i=1;i<cc.length;i++){
            ccnum[i]=rand()%10+48; //Assign random digits to cc array
            testcc[i]=ccnum[i];    //Assign identical digit to copy array
        }
        //Double every other digit
        dblDig(cc,testcc);
        //Combine double digits
        cnsldt(cc,testcc);
        //Check if card is valid
        isValid=validCC(cc,testcc);
        //If card is invalid, reset cc number
        if(isValid!=0){
            for(int i=1;i<cc.length;i++){
                ccnum[i]=0;
            }
        }
    }while(isValid!=0); //Continue looping until valid card is made
}
bool validFp(CrdCard cc,char ccnum[]){
    int sum=0; //Initialize sum to zero
    char testcc[cc.length]; //Copy array for cc number
    testcc[0]=cc.startDg;   //Initialize starting digit
    for(int i=1;i<cc.length;i++){
            //Copy array
            testcc[i]=ccnum[i];
        }
    //Double every other digit
    dblDig(cc,testcc);
    //Combine double digits
    cnsldt(cc,testcc);
    for(int i=0;i<cc.length;i++){
        //Add values
        sum+=(testcc[i]-48);
    }
    sum*=9; //Multiply total by 9
    return sum%10; //Mod by 10 for check number
}
bool validCC(CrdCard cc,char ccnum[]){
    int sum=0;
    for(int i=0;i<cc.length;i++){
        //Add values
        sum+=(ccnum[i]-48);
    }
    sum*=9; //Multiply total by 9
    return sum%10; //Mod by 10 for check number
}
void dblDig(CrdCard cc,char ccnum[]){
    //Initialize counter to zero
    int count=0;
    //Double each value
    for(int i=cc.length;i>=0;i--){        
        //Check for every other value
        if(count%2==1){
            ccnum[i]=(ccnum[i]-48)*2+48;
        }
        count++; //Increase counter
    }
}
void cnsldt(CrdCard cc,char ccnum[]){
    int ones; //Ones place holder
    for(int i=0;i<cc.length;i++){
        if(ccnum[i]>9+48){
            ones=(ccnum[i]-48)%10; //Extract first value
            ccnum[i]=(((ccnum[i]-48)/10)+ones)+48; //Extract second value and add to first
        }
    }
}
void flipDig(CrdCard cc,char ccnum[]){
    ccnum[rand()%cc.length]=rand()%10+48;
}
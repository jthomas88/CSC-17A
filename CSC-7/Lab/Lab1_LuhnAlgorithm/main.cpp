/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on March 1, 2017, 09:22
 * Purpose: Validate Credit Cards
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();           //Generate a random digit
void prpLuhn(char[],int); //Prepare the Luhn
void Luhn(char[],int);

void cnvtCrd(char[],int[],int); //Convert char array to ints
void cnsldt(int[],int);         //Consolidate double digit numbers
void prntCrd(int[],int);        //Output card numbers
void dblDig(int[],int);         //Double every other number in card array

bool isValid(int[],int);        //Check if card number is valid

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0))); //Random number seed (unsigned)
    const int SIZE=12;   //Set array size
    
    
    //Declare Arrays
    char crdCard[SIZE];  //Declare card number array
    int  prlCard[SIZE];  //Parallel int array
    
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn Digit"<<endl;
    prpLuhn(crdCard,SIZE-2);
    
    //Output the preLuhn credit card
    cout<<crdCard<<endl;
    
    //Now create a function that fills the last digit
    //using the Luhn Algorithm
    cout<<"The random number with Luhn Encoding, Output Here!"<<endl;

    //Convert char to int
    cnvtCrd(crdCard,prlCard,SIZE);
    
    //Output Parallel int Array
    prntCrd(prlCard,SIZE);
    
    //Double Every Other Number
    dblDig(prlCard,SIZE);
    cout<<endl;
    
    //Output Parallel int Array
    cout<<"Doubled Array"<<endl;
    prntCrd(prlCard,SIZE);
   
    //Consolidate Double Digit Values
    cnsldt(prlCard,SIZE);
    cout<<endl;
    
    //Output consolidated array
    cout<<"Consolidated Array: "<<endl;
    prntCrd(prlCard,SIZE);
    
    //Determine if card is valid
    cout<<endl;
    !isValid(prlCard,SIZE)
            ?cout<<"The card is valid.":cout<<"The card is not valid.";
    
    //Exit Stage Right
    return 0;
}

void prpLuhn(char cc[],int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    //Returns random numbers
    return rand()%10+48;
}

void cnvtCrd(char cc[],int cc2[],int n){
    //Convert ASCII value to number value
    for(int i=0;i<n;i++){
        cc2[i]=cc[i]-48;
    }
}

void prntCrd(int cc[],int n){
    for(int i=0;i<n-2;i++){
        cout<<cc[i]<<' ';
    }
}

void dblDig(int cc[],int n){
    //Double each value
    for(int i=n-2;i>=0;i--){
        //Check for every other value
        if(i%2==1){
            cc[i]*=2;
        }
    }
}

void cnsldt(int cc[],int n){
    int ones;
    for(int i=0;i<n;i++){
        if(cc[i]>9){
            ones=cc[i]%10; //Extract first value
            cc[i]=(cc[i]/10)+ones; //Extract second value and add to first
        }
    }
}

bool isValid(int cc[],int n){
    int sum=0; //Set value to zero
    for(int i=0;i<n-2;i++){
        //Add values
        sum+=cc[i];
    }
    sum*=9; //Multiply total by 9
    return sum%10; //Mod by 10 for check number
}
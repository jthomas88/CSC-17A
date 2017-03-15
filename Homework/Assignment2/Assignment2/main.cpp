/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream> //Input/Output objects
#include <iomanip>  //I/O Format 
#include <cstdlib>  //Random generator
#include <ctime>    //Random seed


using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();
void prob10();

//Problem 1 functions
int *getMem(int);
//Problem 2 functions
void prtScor(int,int *);
void sortScr(int,int *);
float avg(int,int *);
//Problem 4 functions
int *getScr(int);
string *getNam(int);
void prtScor(int,int *,string *);
void sortScr(int,int *,string *);
float avgDrop(int,int *);
//Problem 5 functions
int doSomething(int,int);
//Problem 10 functions
int *getMems(int);
int *revMem(int *,int);
void prntAry(int *,int);
//Problem 11 functions
int *expMem(int *,int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare variables
    int menuCho;
    
    //Open Menu
    do{
        cout<<"1)  Problem 1 : Array Allocator"<<endl;
        cout<<"2)  Problem 2 : Test Scores 1"<<endl;
        cout<<"3)  Problem 3 : Test Scores 1 Mod"<<endl;
        cout<<"4)  Problem 4 : Test Scores 2"<<endl;
        cout<<"5)  Problem 5 : Pointer Rewrite"<<endl;
        cout<<"6)  Problem 10: Reverse Array"<<endl;
        cout<<"7)  Problem 11: Expand Array"<<endl;
        cout<<"8)  Problem H"<<endl;
        cout<<"9)  Problem I"<<endl;
        cout<<"10) Problem J"<<endl;
        cin>>menuCho;
        switch(menuCho){
            case 1: prob1();break;
            case 2: prob2();break;
            case 3: prob3();break;
            case 4: prob4();break;
            case 5: prob5();break;
            case 6: prob6();break;
            case 7: prob7();break;
            case 8: prob8();break;
            case 9: prob9();break;
            case 10:prob10();break;
        }
    }while(menuCho>0&&menuCho<=10);  
    
    //Exit program
    return 0;
}

void  prob1(){
    cout<<"Problem 1"<<endl<<endl;
    //Declare Variables
    int arraySz; //User defined array size
    
    //Input Values
    cout<<"Enter the desired array size: ";
    cin>>arraySz;
    
    //Allocate memory
    int *array=getMem(arraySz);
    
    //Display address
    cout<<endl;
    cout<<"The location of the array is: "<<array;
    cout<<endl<<endl;
    
    //Free memory
    delete []array;
}
void  prob2(){
    cout<<"Problem 2"<<endl<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declare Variables
    int arraySz; //User defined array size
    
    //Input Values
    cout<<"Enter the number of tests: ";
    cin>>arraySz;
    
    //Allocate memory
    int *array=getMem(arraySz);
    
    //Display unsorted scores
    cout<<"Unsorted list of scores: "<<endl;
    prtScor(arraySz,array);
    cout<<endl<<endl;
    
    //Sort Scores
    sortScr(arraySz,array);
    
    //Output sorted array
    cout<<"Sorted list of scores: "<<endl;
    prtScor(arraySz,array);
    cout<<endl<<endl;
    
    //Output average scores
    cout<<"Class Average: "<<fixed<<setprecision(2)<<avg(arraySz,array);
    
    //Free memory
    delete []array;
    
    cout<<endl<<endl;
}
void  prob3(){
    cout<<"Problem 3"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declare Variables
    int arraySz; //User defined array size
    
    //Input Values
    cout<<"Enter the number of tests: ";
    cin>>arraySz;
    
    //Allocate memory
    int *array=getMem(arraySz);
    
    //Display unsorted scores
    cout<<"Unsorted list of scores: "<<endl;
    prtScor(arraySz,array);
    cout<<endl<<endl;
    
    //Sort Scores
    sortScr(arraySz,array);
    
    //Output sorted array
    cout<<"Sorted list of scores: "<<endl;
    prtScor(arraySz,array);
    cout<<endl<<endl;
    
    //Output average scores
    cout<<"Class Average w/ lowest score dropped: "
        <<fixed<<setprecision(2)<<avg(arraySz,array);
    
    //Free memory
    delete []array;
    
    cout<<endl<<endl;
}
void  prob4(){
    cout<<"Problem 4"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declare Variables
    int arraySz; //User defined array size
    
    //Input Values
    cout<<"Enter the number of tests: ";
    cin>>arraySz;
    
    //Allocate memory
    int    *scores=getScr(arraySz);
    string *names =getNam(arraySz);
    
    //Display unsorted scores
    cout<<"Unsorted list of scores: "<<endl;
    prtScor(arraySz,scores,names);
    cout<<endl<<endl;
    
    //Sort Scores
    sortScr(arraySz,scores,names);
    
    //Output sorted array
    cout<<"Sorted list of scores: "<<endl;
    prtScor(arraySz,scores,names);
    cout<<endl<<endl;
    
    //Output average scores
    cout<<"Class Average w/ lowest score dropped: "
        <<fixed<<setprecision(2)<<avgDrop(arraySz,scores);
    
    //Free memory
    delete []scores;
    delete []names;
}
void  prob5(){
    cout<<"Problem 5"<<endl;
    //Declaration of variables
    int x,y;
    
    //Test Function
    doSomething(x,y);
}
void  prob6(){
    cout<<"Problem 10"<<endl;
    //Declare variables
    int size=50;
    
    //Initialize Array
    int *array=getMems(size);
    
    //Output Array
    cout<<"Original Array: "<<endl;
    prntAry(array,size);
    cout<<endl;
    
    //Copy and Reverse Array
    int *paral=revMem(array,size);
    
    //Output Reversed Array
    cout<<"Reversed Array: "<<endl;
    prntAry(paral,size);
    
    //Delete Array
    delete []array;
    delete []paral;
    
    cout<<endl;
}
void  prob7(){
    cout<<"Problem 11"<<endl;
    //Declare variables
    int size=50;
    
    //Initialize Array
    int *array=getMems(size);
    
    //Output Array
    cout<<"Original Array: "<<endl;
    prntAry(array,size);
    cout<<endl;
    
    //Copy and Reverse Array
    int *paral=expMem(array,size);
    
    //Output Reversed Array
    cout<<"Expanded Array: "<<endl;
    prntAry(paral,size*2);
    
    //Delete Array
    delete []array;
    delete []paral;
    
    cout<<endl;
}
void  prob8(){
    cout<<"Problem H"<<endl;
    //Input
    //Process
    //Output
}
void  prob9(){
    cout<<"Problem I"<<endl;
    //Input
    //Process
    //Output
}
void prob10(){
    cout<<"Problem J"<<endl;
    //Input
    //Process
    //Output
}

//Problem 1 Functions
int *getMem(int arraySz){
    int *ptr=0;
    ptr=new int[arraySz];
    for(int i=0;i<arraySz;i++){
        ptr[i]=rand()%100;
    }
    return ptr;
}

//Problem 2 Functions
void prtScor(int arraySz,int *scores){
    for(int i=0;i<arraySz;i++){
        cout<<setw(2)<<right<<scores[i]<<' ';
        if(i%10==9)cout<<endl;
    }
}
void sortScr(int arraySz,int *scores){
    bool isSort;
    int  temp;
    do{
        isSort=false;
        for(int i=0;i<arraySz;i++){
            if(scores[i]>scores[i+1]){
                temp=scores[i];
                scores[i]=scores[i+1];
                scores[i+1]=temp;
                isSort=true;
            }
        }
    }while(isSort);    
}
float avg(int size,int *scores){
    float total=0;
    for(int i=0;i<size;i++){
        total+=scores[i];
    }
    return total/size;
}

//Problem 4 Functions
int *getScr(int arraySz){
    int *ptr=0;
    ptr=new int[arraySz];
    for(int i=0;i<arraySz;i++){
        ptr[i]=rand()%100;
    }
    return ptr;
}
string *getNam(int arraySz){
    char rndLtr;
    string *ptr=0;
    ptr=new string[arraySz];
    for(int i=0;i<arraySz;i++){
        rndLtr=rand()%26+48;
        ptr[i]=rndLtr;
    }
    return ptr;
}
void prtScor(int arraySz,int *scores,string *names){
    for(int i=0;i<arraySz;i++){
        cout<<names[i]<<": "<<setw(2)<<right<<scores[i]<<endl;
    }
}
void sortScr(int arraySz,int *scores,string *names){
    bool   isSort;
    int    temp;
    string tmpNm;
    
    do{
        isSort=false;
        for(int i=0;i<arraySz-1;i++){
            if(scores[i]>scores[i+1]){
                temp=scores[i];
                scores[i]=scores[i+1];
                scores[i+1]=temp;
                
                tmpNm=names[i];
                names[i]=names[i+1];
                names[i+1]=tmpNm;
                
                isSort=true;
            }
        }
    }while(isSort);    
}
float avgDrop(int size,int *scores){
    float total=0;
    for(int i=1;i<size;i++){
        total+=scores[i];
    }
    return total/size-1;
}

//Problem 5 Functions
int doSomething(int x,int y){ 
    int temp=x; 
    x=y*10; 
    y=temp*10; 
    return x+y; 
}

//Problem 10 Functions
int *getMems(int n){
    int *a;
    a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=i%10; 
    }
    return a;
}
int *revMem(int *a,int n){
    int *b;
    b=new int[n];
    for(int i=0,j=n-1;i<n,j>=0;i++,j--){
        b[j]=a[i];
    }
    return b;
}
void prntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
        if(i%10==9)cout<<endl;
    }
}

//Problem 11 Functions
int *expMem(int *a,int n){
    int *b;
    b=new int[n*2];
    for(int i=0;i<n*2;i++){
        b[i]=a[i];
        if(i>n-1)b[i]=0;
    }
    return b;
}
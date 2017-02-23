/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
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

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare variables
    int menuCho;
    
    //Open Menu
    do{
        cout<<"1)  Problem A"<<endl;
        cout<<"2)  Problem B"<<endl;
        cout<<"3)  Problem C"<<endl;
        cout<<"4)  Problem D"<<endl;
        cout<<"5)  Problem E"<<endl;
        cout<<"6)  Problem F"<<endl;
        cout<<"7)  Problem G"<<endl;
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
    cout<<"Problem A"<<endl;
    //Input
    //Process
    //Output
}
void  prob2(){
    cout<<"Problem B"<<endl;
    //Input
    //Process
    //Output
}
void  prob3(){
    cout<<"Problem C"<<endl;
    //Input
    //Process
    //Output
}
void  prob4(){
    cout<<"Problem D"<<endl;
    //Input
    //Process
    //Output
}
void  prob5(){
    cout<<"Problem E"<<endl;
    //Input
    //Process
    //Output
}
void  prob6(){
    cout<<"Problem F"<<endl;
    //Input
    //Process
    //Output
}
void  prob7(){
    cout<<"Problem G"<<endl;
    //Input
    //Process
    //Output
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


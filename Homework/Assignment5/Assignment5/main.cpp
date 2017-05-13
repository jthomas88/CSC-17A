/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Output format
#include <cstdlib>   //Random gen
#include <ctime>     //Random seed

using namespace std; //Namespace used in system library

//User libraries
    //Problem 1
    #include "Date.h"
    //Problem 2
    #include "Inventory.h"
    //Problem 3
    #include "Circle.h"
    //Problem 4
    #include "Populus.h"
    //Problem 5
    #include "Coin.h"
    //Problem 6
    #include "NumDays.h"
    //Problem 7
    #include "Time.h"
    //Problem 9
    #include "DivSale.h"
    //Problem 10
    #include "Fuel.h"
    #include "Odom.h"

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
        cout<<"1)  Problem 1 : Date Class"<<endl;
        cout<<"2)  Problem 2 : Inventory Class"<<endl;
        cout<<"3)  Problem 3 : Circle Class"<<endl;
        cout<<"4)  Problem 4 : Population Class"<<endl;
        cout<<"5)  Problem 5 : Coin Game"<<endl;
        cout<<"6)  Problem 6 : NumDays Class"<<endl;
        cout<<"7)  Problem 7 : Time Off"<<endl;
        cout<<"8)  Problem 8 : Personnel Report"<<endl;
        cout<<"9)  Problem 9 : Corporate Sales"<<endl;
        cout<<"10) Problem 10: Car Simulation"<<endl;
        cin>>menuCho;
        switch(menuCho){
            case 1: prob1(); cout<<endl;break;
            case 2: prob2(); cout<<endl;break;
            case 3: prob3(); cout<<endl;break;
            case 4: prob4(); cout<<endl;break;
            case 5: prob5(); cout<<endl;break;
            case 6: prob6(); cout<<endl;break;
            case 7: prob7(); cout<<endl;break;
            case 8: prob8(); cout<<endl;break;
            case 9: prob9(); cout<<endl;break;
            case 10:prob10();cout<<endl;break;
        }
    }while(menuCho>0&&menuCho<=10);  
    
    //Exit program
    return 0;
}

void  prob1(){
    cout<<"Problem 1"<<endl;
    //Declare object
    Date date;
    //Declare Variables
    int d;
    //Input day
    do{
        cout<<"Enter the day: ";
        cin>>d;
        cout<<endl;
    }while(d>31||d<1);
    date.setDay(d);
    //Input month
    int m;
    do{
        cout<<"Enter the month: ";
        cin>>m;
        cout<<endl;
    }while(m>12||m<1);
    date.setMon(m);
    //Input year
    int y;
    do{
        cout<<"Enter the year: ";
        cin>>y;
        cout<<endl;
    }while(y<1000);
    date.setYea(y);
    //Output results
    cout<<date.mdy1()<<endl;
    cout<<date.mdy2()<<endl;
    cout<<date.dmy()<<endl;
}
void  prob2(){
    cout<<"Problem 2"<<endl;
    //Declare object
    Inventory inv;
    //Declare Variables
    int   item,qty;
    float cost;
    //Input item number
    do{
        cout<<"Enter the item number: ";
        cin>>item;
        cout<<endl;
    }while(item<0);
    inv.setItem(item);
    //Input quantity
    do{
        cout<<"Enter the available quantity: ";
        cin>>qty;
        cout<<endl;
    }while(qty<0);
    inv.setQty(qty);
    //Input price per unit
    do{
        cout<<"Enter the cost per unit: ";
        cin>>cost;
        cout<<endl;
    }while(cost<0);
    inv.setCost(cost);
    //Calculate total
    inv.setTtl();
    //Output results
    cout<<"Item #  : "<<inv.getItem()<<endl;
    cout<<"Stock   : "<<inv.getQty()<<endl;
    cout<<"Per unit: $"<<fixed<<setprecision(2)<<inv.getCost()<<endl;
    cout<<"Total   : $"<<fixed<<setprecision(2)<<inv.getTtl()<<endl;
}
void  prob3(){
    cout<<"Problem 3"<<endl;
    //Declaration of variables
    Circle circle;
    float rad;    
    //Construct object
    Circle();    
    //Enter radius
    do{
        cout<<"Enter the radius of a circle: ";
        cin>>rad;
        cout<<endl;
    }while(rad<0);    
    //Set radius
    circle.setRad(rad);
    //Calculate attributes
    cout<<"Radius       : "<<circle.getRadi()<<endl;
    cout<<"Diameter     : "<<circle.getDiam()<<endl;
    cout<<"Area         : "<<circle.getArea()<<endl;
    cout<<"Circumference: "<<circle.getCirc()<<endl;
}
void  prob4(){
    cout<<"Problem 4"<<endl;
    //Initialize random seed
    srand(time(0));
    //Declaration of variables
    Populus populus;
    unsigned int birth,death,pop;     
    //Construct object
    Populus();    
    //Set Values
    pop=rand()%50000;
    birth=rand()%pop;
    death=rand()%pop;
    populus.setPop(pop);
    populus.setBR(birth);
    populus.setDR(death);
    //Calculate rates
    cout<<"Total population : "<<populus.getPop()<<endl<<endl;
    cout<<"Total births     : "<<populus.getBR()<<endl;
    cout<<"Annual birth rate: "<<fixed<<setprecision(2)
        <<populus.calcCR(pop,birth)<<endl<<endl;
    cout<<"Total deaths     : "<<populus.getDR()<<endl;
    cout<<"Annual death rate: "<<fixed<<setprecision(2)
        <<populus.calcCR(pop,death)<<endl;
}
void  prob5(){
    cout<<"Problem 5"<<endl;
    //Initialize random seed
    srand(time(0));
    //Declaration of variables
    Coin quar,nick,dime;
    int tot=0; //Total money user has
    //Set values
    quar.setVal(25);
    dime.setVal(10);
    nick.setVal(5);
    //Start game    
    do{
        cout<<"Press ENTER to flip the coins."<<endl;
        cin.ignore();
        //Check for quarter flipped heads
        if(quar.toss()==1){
            //Add quarter value
            tot+=quar.getVal();
            cout<<"Quarter flipped heads. You gained 25 cents."<<endl;
        }
        //Check for dime flipped heads
        if(dime.toss()==1){
            //Add dime value
            tot+=dime.getVal();
            cout<<"Dime flipped heads. You gained 10 cents."<<endl;
        }
        //Check for nickel flipped heads
        if(nick.toss()==1){
            //Add nickel value
            tot+=nick.getVal();
            cout<<"Nickel flipped heads. You gained 5 cents."<<endl;
        }
        //Output total
        cout<<"Your end of turn total is: "<<tot<<" cents."<<endl;
    }while(tot<100); //Play until 100 cents or greater is reached
    //Output victory message
    if(tot==100){
        cout<<"Congratulations! You win!"<<endl;
    }
    //Output loss message
    else{
        cout<<"Sorry! You lose!"<<endl;
    }
}
void  prob6(){
    cout<<"Problem 6"<<endl;
    //Declaration of variables
    NumDays emp1,emp2;
    int hrs;
    
    //Prompt for input (Employee 1)
    cout<<"Enter the number of hours employee 1 worked this week: ";
    cin>>hrs;
    emp1.setHrs(hrs);
    
    //Prompt for input (Employee 2)
    cout<<"Enter the number of hours employee 2 worked this week: ";
    cin>>hrs;
    emp2.setHrs(hrs);
    
    cout<<endl;
    
    //Output hours
    cout<<"Employee 1 hours worked: "<<emp1.getHrs()<<endl;
    cout<<"Employee 1 days worked : "<<emp1.getDay()<<endl;
    cout<<endl;
    cout<<"Employee 2 hours worked: "<<emp2.getHrs()<<endl;
    cout<<"Employee 2 days worked : "<<emp2.getDay()<<endl;
    cout<<endl;
    //Showcase overloaded operators
    ++(emp1);
    --(emp2);
    cout<<"Incremented employee 1 hours +1"<<endl;
    cout<<"Employee 1 hours worked: "<<emp1.getHrs()<<endl;
    cout<<"Employee 1 days worked : "<<emp1.getDay()<<endl;
    cout<<endl;
    cout<<"Decremented employee 2 hours -1"<<endl;
    cout<<"Employee 2 hours worked: "<<emp2.getHrs()<<endl;
    cout<<"Employee 2 days worked : "<<emp2.getDay()<<endl;
    cout<<endl;
    cout<<"Sum of hours       : "<<(emp1+emp2).getHrs()<<endl;
    cout<<"Difference of hours: "<<(emp1-emp2).getHrs()<<endl;
}
void  prob7(){
    cout<<"Problem 7"<<endl;
    //Declaration of variables
    Time emp;
    int hrs;  //Hours for a particular set
    string n; //Name and ID holder
    
    //Prompt for name input
    cout<<"Enter employee's name: ";
    cin>>n;
    emp.setNa(n);
    cout<<endl;
    //Prompt for ID input
    cout<<"Enter "<<emp.getNa()<<"'s ID number: ";
    cin>>n;
    emp.setID(n);
    cout<<endl;
    //Input sick hours
    do{
        cout<<"Enter sick hours: ";
        cin>>hrs;
        emp.setMS(hrs);
    }while(hrs<0);
    //Input vaction hours
    do{
        cout<<"Enter vacation hours: ";
        cin>>hrs;
        emp.setMV(hrs);
    }while(hrs<0||hrs>240);
    //Input unpaid hours
    do{
        cout<<"Enter unpaid hours: ";
        cin>>hrs;
        emp.setMU(hrs);
    }while(hrs<0);
    //Output report
    cout<<"Name: "<<emp.getNa()<<endl;
    cout<<"ID #: "<<emp.getID()<<endl;
    cout<<"Sick days    : "<<emp.getMS()<<endl;
    cout<<"Vacation days: "<<emp.getMV()<<endl;
    cout<<"Unpaid days  : "<<emp.getMU()<<endl;
}
void  prob8(){
    cout<<"Problem 8"<<endl;
    //Declare constants
    const int SICK=8;  //Hours of sick leave earned per month
    const int VACA=12; //Hours of vacation earned per month
    //Declaration of variables
    Time emp;
    int mon;
    string n;
    
    //Prompt for name input
    cout<<"Enter employee's name: ";
    cin>>n;
    emp.setNa(n);
    cout<<endl;
    //Prompt for ID input
    cout<<"Enter "<<emp.getNa()<<"'s ID number: ";
    cin>>n;
    emp.setID(n);
    cout<<endl;
    //Enter months worked
    do{
        cout<<"Enter number of months worked: ";
        cin>>mon;
        if(mon<0)cout<<"Months must be a positive number."<<endl;
    }while(mon<0);
    //Calculate number of sick days
    emp.setMV(mon*VACA);
    emp.setMS(mon*SICK);
    //Output report
    cout<<"Name: "<<emp.getNa()<<endl;
    cout<<"ID #: "<<emp.getID()<<endl;
    cout<<"Sick days    : "<<emp.getMS()<<endl;
    cout<<"Vacation days: "<<emp.getMV()<<endl;
}
void  prob9(){
    cout<<"Problem 9"<<endl;
    //Declare constants
    const int QUAR=4; //Number of quarters in a year
    
    //Declaration of variables
    DivSale *region;  //Different regions of sales
    int   size;       //Number of sales regions
    float sales;      //Sales amount holder
    float total=0.0f; //Total sales
    //Enter size of array
    cout<<"Enter the number of sales regions: ";
    cin>>size;
    cout<<endl;
    //Allocate memory
    region=new DivSale[size];
    //Input Values
    for(int i=0;i<size;i++){
        for(int j=0;j<4;j++){
            cout<<"Enter sales for region "<<i+1<<": ";
            cin>>sales;
            region[i].setQ(sales,j);      
            cout<<endl;
        }
        total+=region[i].getT();
    } 
    //Output table
    for(int i=0;i<size;i++){
        cout<<"Region "<<i+1<<": ";
        for(int j=0;j<4;j++){
            cout<<fixed<<setprecision(2)<<setw(10)<<region[i].getQ(j);
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Total: "<<total;
    //Delete memory
    delete []region;
}
void prob10(){
    cout<<"Problem 10"<<endl;
    //Declare constant
    const int MPG=24; //MPG of hypothetical vehicle
    //Declaration of variables
    Odom odom; //Odometer object
    Fuel fuel; //Fuel gauge object
    //Simulate Driving
    do{
        //Output gauge readings
        cout<<"Odometer  : "<<odom.getMile()<<endl;
        cout<<"Fuel Gauge: "<<fuel.getFuel()<<endl;
        //Increment odometer
        odom++;
        //Decrement fuel when MPG has been reached
        if(odom.getMile()%MPG==0)fuel--;
        cout<<endl;
        //Continue until fuel has run out
    }while(fuel.getFuel()>=0);
}


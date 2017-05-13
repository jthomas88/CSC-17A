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
#include "Circle.h"

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
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
    //Exit program
    return 0;
}
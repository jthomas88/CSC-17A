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
void arrSelectSort(int*,int);
void showArray(int*,int);
void showArrPtr(int*[],int);

//Execution begins here
int main(){
    //Initialize random seed
    srand(time(0));
    
    //Declare Size
    int size=20;    
    
    //An array of pointers to int. 
    int *arrPtr=new int[size];

    // Each element of arrPtr is a pointer to int. Make each 
    // element point to an element in the donations array. 
    for(int i=0;i<size;i++) 
        arrPtr[i]=rand()%100; 
        // Sort the elements of the array of pointers. 
        arrSelectSort(arrPtr,size); 
        // Display the donations using the array of pointers. This 
        // will display them in sorted order. 
        cout<<"The donations, sorted in ascending order are: \n"; 
        //showArrPtr(arrPtr,size); 
        // Display the donations in their original order. 
        cout<<"The donations, in their original order are: \n"; 
        showArray(arrPtr,size); 
        return 0; 
}
 
//**************************************************************** 
// Definition of function arrSelectSort. * 
// This function performs an ascending order selection sort on * 
// arr, which is an array of pointers. Each element of array * 
// points to an element of a second array. After the sort, * 
// arr will point to the elements of the second array in * 
// ascending order. * 
//**************************************************************** 
void arrSelectSort(int *arr[],int size){ 
    int startScan, minIndex; 
    int *minElem; 
    for(startScan=0;startScan<(size-1);startScan++){ 
    minIndex=startScan; 
    minElem=arr[startScan]; 
        for(int index=startScan+1;index<size;index++){ 
            if(*(arr[index])<*minElem){ 
                minElem=arr[index]; 
                minIndex=index; 
            } 
        } 
        arr[minIndex]=arr[startScan]; 
        arr[startScan]=minElem; 
    } 
} 

//*********************************************************** 
// Definition of function showArray. * 
// This function displays the contents of arr. size is the * 
// number of elements. * 
//*********************************************************** 
void showArray(const int arr[],int size){ 
    for(int count=0;count<size; count++) 
        cout<<arr[count]<<" "; 
        cout<<endl; 
} 

//*************************************************************** 
// Definition of function showArrPtr. * 
// This function displays the contents of the array pointed to * 
// by arr. size is the number of elements. * 
//*************************************************************** 
 
/*
 
void showArrPtr(int *arr,int size){ 
    for(int count=0;count<size;count++) 
        cout<<*(arr[count])<<" "; 
        cout<<endl; 
}    
 * */
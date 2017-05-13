/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.cpp
 * Author: rcc
 *
 * Created on March 21, 2017, 1:11 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

//User Libraries
#include "GeneralHashFunctions.h"

//Function Prototypes
unsigned int RSHash(const std::string&);
unsigned int JSHash(const std::string&);
unsigned int PJWHash(const std::string&);
unsigned int ELFHash(const std::string&);
unsigned int BKDRHash(const std::string&);
unsigned int SDBMHash(const std::string&);
unsigned int DJBHash(const std::string&);
unsigned int DEKHash(const std::string&);
unsigned int BPHash(const std::string&);
unsigned int FNVHash(const std::string&);
unsigned int APHash(const std::string&);

void  hashFil(bool[],int,int&);
void  testFak(bool[],int);
float dispFp(int,int,int);

//Global constants
const float e=2.7182818; //Universal constant e

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Local Constants
    const int SIZE=500; //Size of bit vector
    const int K=9;      //Number of hashes used
    
    //Declare Variables
    int      count=0; //Counter for number of items in the bit vector
    string   test;    //Holder for hash items
    ifstream read;    //File stream object
    
    //Declare Bit Vector
    bool bitVec[SIZE]={}; 
    
    //Hash random inputs from a file
    hashFil(bitVec,SIZE,count);
    
    //Test fake variable to see if there are any false positives
    testFak(bitVec,SIZE);
    
    //Output Statistics
    cout<<"Bit Vector Size: "<<SIZE<<endl;
    cout<<"Number of elements set: "<<count<<endl;
    cout<<"Number of Hashes: "<<K<<endl;
    cout<<"False Positive rate: "<<dispFp(SIZE,count,K)<<endl;
 
    return 0;
}

//Program functions
void  hashFil(bool bitVec[],int n,int &count){
    //Declare objects
    string   test; //Holder for inputs    
    ifstream read; //File stream Object
    
    //Open File (Hashes)
    read.open("testIn.txt");
    
    //Read contents
    getline(read,test);
    while(getline(read,test)){
        //Hash 9 times
        bitVec[RSHash(test)%n]=1;
        bitVec[JSHash(test)%n]=1;
        bitVec[PJWHash(test)%n]=1;
        bitVec[ELFHash(test)%n]=1;
        bitVec[BKDRHash(test)%n]=1;
        bitVec[SDBMHash(test)%n]=1;
        bitVec[DJBHash(test)%n]=1;
        bitVec[DEKHash(test)%n]=1;
        bitVec[BPHash(test)%n]=1;
        //Increment counter
        count++;
    }
    //Close file
    read.close();
}
void  testFak(bool bitVec[],int n){
    //Declare objects
    string   test; //Holder for inputs    
    ifstream read; //File stream Object
    
    //Open file (False inputs)
    read.open("fakefriends.txt");
    
    //Read contents
    getline(read,test);
    while(getline(read,test)){
        //Output item being tested
        cout<<test<<endl;
        //Output whether or not a false positive is present
        (bitVec[RSHash(test)%n]==1&&
         bitVec[JSHash(test)%n]==1&&
         bitVec[PJWHash(test)%n]==1&&
         bitVec[ELFHash(test)%n]==1&&
         bitVec[BKDRHash(test)%n]==1&&
         bitVec[SDBMHash(test)%n]==1&&
         bitVec[DJBHash(test)%n]==1&&
         bitVec[DEKHash(test)%n]==1&&
         bitVec[BPHash(test)%n]==1)?cout<<"Possible":cout<<"No";
        cout<<endl<<endl;
    }
    
    //Close file
    read.close();
}
float dispFp(int size,int count,int numhash){
    //Items for false pos calculation
    float exp1=((-1*numhash)*(static_cast<float>(count)/size)); //(exp for e)
    float t1=1-pow(e,exp1);                                     //(1-e^exp1)
    float fp=pow(t1,numhash);                                   //(t1^k)
    
    return fp;
}
//Hashes
unsigned int RSHash(const std::string& str){
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = hash * a + str[i];
      a    = a * b;
   }

   return hash;
}
unsigned int JSHash(const std::string& str){
   unsigned int hash = 1315423911;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash ^= ((hash << 5) + str[i] + (hash >> 2));
   }

   return hash;
}
unsigned int PJWHash(const std::string& str){
   unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
   unsigned int ThreeQuarters     = (unsigned int)((BitsInUnsignedInt  * 3) / 4);
   unsigned int OneEighth         = (unsigned int)(BitsInUnsignedInt / 8);
   unsigned int HighBits          = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
   unsigned int hash              = 0;
   unsigned int test              = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = (hash << OneEighth) + str[i];

      if((test = hash & HighBits)  != 0)
      {
         hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
      }
   }

   return hash;
}
unsigned int ELFHash(const std::string& str){
   unsigned int hash = 0;
   unsigned int x    = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = (hash << 4) + str[i];
      if((x = hash & 0xF0000000L) != 0)
      {
         hash ^= (x >> 24);
      }
      hash &= ~x;
   }

   return hash;
}
unsigned int BKDRHash(const std::string& str){
   unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = (hash * seed) + str[i];
   }

   return hash;
}
unsigned int SDBMHash(const std::string& str){
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = str[i] + (hash << 6) + (hash << 16) - hash;
   }

   return hash;
}
unsigned int DJBHash(const std::string& str){
   unsigned int hash = 5381;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = ((hash << 5) + hash) + str[i];
   }

   return hash;
}
unsigned int DEKHash(const std::string& str){
   unsigned int hash = static_cast<unsigned int>(str.length());

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = ((hash << 5) ^ (hash >> 27)) ^ str[i];
   }

   return hash;
}
unsigned int BPHash(const std::string& str){
   unsigned int hash = 0;
   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = hash << 7 ^ str[i];
   }

   return hash;
}
unsigned int FNVHash(const std::string& str){
   const unsigned int fnv_prime = 0x811C9DC5;
   unsigned int hash = 0;
   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash *= fnv_prime;
      hash ^= str[i];
   }

   return hash;
}
unsigned int APHash(const std::string& str){
   unsigned int hash = 0xAAAAAAAA;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ str[i] * (hash >> 3)) :
                               (~((hash << 11) + (str[i] ^ (hash >> 5))));
   }

   return hash;
}
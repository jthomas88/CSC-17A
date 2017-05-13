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

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

#include "GeneralHashFunctions.h"

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

void hcRS(int[],std::string);
void hcPJW(int[],std::string);
void hcELF(int[],std::string);
void hcBKDR(int[],std::string);
void hcSDBM(int[],std::string);
void hcDJB(int[],std::string);
void hcDEK(int[],std::string);
void hcBP(int[],std::string);
void hcFNV(int[],std::string);

void reset(int[]);
void dispRes(int[]);

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    const std::string sample="And it was good."; //Sample nonce
    int count=0;                      //Hash Counter to append
    string hash;                      //String to hold full phrase
    int power[10]={};                 //Array to hold occurrences of each range
    
    //RS Hash stats
    hcRS(power,hash);
    cout<<"RS Hash"<<endl;
    dispRes(power);
    reset(power);
    cout<<endl;
    //PJW Hash stats
    hcPJW(power,hash);
    cout<<"PJW Hash"<<endl;
    dispRes(power);
    reset(power);
    cout<<endl;
    //ELF Hash stats
    hcELF(power,hash);
    cout<<"ELF Hash"<<endl;
    dispRes(power);
    reset(power);
    cout<<endl;
    //BKDR Hash stats
    hcBKDR(power,hash);
    cout<<"BKDR Hash"<<endl;
    dispRes(power);
    reset(power);
    cout<<endl;
    //SDBM Hash stats
    hcSDBM(power,hash);
    cout<<"SDBM Hash"<<endl;
    dispRes(power);
    reset(power);
    cout<<endl;
    //DJB Hash stats
    hcDJB(power,hash);
    cout<<"DJB Hash"<<endl;
    dispRes(power);
    reset(power);
    cout<<endl;
    //DEK Hash stats
    hcDEK(power,hash);
    cout<<"DEK Hash"<<endl;
    dispRes(power);
    reset(power);
    cout<<endl;
    //BP Hash stats
    hcBP(power,hash);
    cout<<"BP Hash"<<endl;
    dispRes(power);
    reset(power);
    cout<<endl<<endl;
    //FNV Hash stats
    hcFNV(power,hash);
    cout<<"FNV Hash"<<endl;
    dispRes(power);
    reset(power);
    cout<<endl<<endl;

    return 0;
}

unsigned int RSHash(const std::string& str)
{
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
unsigned int JSHash(const std::string& str)
{
   unsigned int hash = 1315423911;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash ^= ((hash << 5) + str[i] + (hash >> 2));
   }

   return hash;
}
unsigned int PJWHash(const std::string& str)
{
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
unsigned int ELFHash(const std::string& str)
{
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
unsigned int BKDRHash(const std::string& str)
{
   unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = (hash * seed) + str[i];
   }

   return hash;
}
unsigned int SDBMHash(const std::string& str)
{
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = str[i] + (hash << 6) + (hash << 16) - hash;
   }

   return hash;
}
unsigned int DJBHash(const std::string& str)
{
   unsigned int hash = 5381;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = ((hash << 5) + hash) + str[i];
   }

   return hash;
}
unsigned int DEKHash(const std::string& str)
{
   unsigned int hash = static_cast<unsigned int>(str.length());

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = ((hash << 5) ^ (hash >> 27)) ^ str[i];
   }

   return hash;
}
unsigned int BPHash(const std::string& str)
{
   unsigned int hash = 0;
   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = hash << 7 ^ str[i];
   }

   return hash;
}
unsigned int FNVHash(const std::string& str)
{
   const unsigned int fnv_prime = 0x811C9DC5;
   unsigned int hash = 0;
   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash *= fnv_prime;
      hash ^= str[i];
   }

   return hash;
}
unsigned int APHash(const std::string& str)
{
   unsigned int hash = 0xAAAAAAAA;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ str[i] * (hash >> 3)) :
                               (~((hash << 11) + (str[i] ^ (hash >> 5))));
   }

   return hash;
}

void hcRS(int power[],string nonce){
    int count=0;
    string hash;
    for(int i=0;i<100000;i++){   
        hash=nonce+to_string(count);
        //cout<<RSHash(hash)<<endl;
        if(RSHash(hash)<pow(10,10))power[0]++;
        if(RSHash(hash)<pow(10,9))power[9]++;
        if(RSHash(hash)<pow(10,8))power[8]++;
        if(RSHash(hash)<pow(10,7))power[7]++;
        if(RSHash(hash)<pow(10,6))power[6]++;
        if(RSHash(hash)<pow(10,5))power[5]++;
        if(RSHash(hash)<pow(10,4))power[4]++;
        if(RSHash(hash)<pow(10,3))power[3]++;
        if(RSHash(hash)<pow(10,2))power[2]++;
        count++;
    }
}
void hcPJW(int power[],string nonce){
    int count=0;
    string hash;
    for(int i=0;i<100000;i++){   
        hash=nonce+to_string(count);
        //cout<<PJWHash(hash)<<endl;
        if(PJWHash(hash)<pow(10,10))power[0]++;
        if(PJWHash(hash)<pow(10,9))power[9]++;
        if(PJWHash(hash)<pow(10,8))power[8]++;
        if(PJWHash(hash)<pow(10,7))power[7]++;
        if(PJWHash(hash)<pow(10,6))power[6]++;
        if(PJWHash(hash)<pow(10,5))power[5]++;
        if(PJWHash(hash)<pow(10,4))power[4]++;
        if(PJWHash(hash)<pow(10,3))power[3]++;
        if(PJWHash(hash)<pow(10,2))power[2]++;
        count++;
    }
}
void hcELF(int power[],string nonce){
    int count=0;
    string hash;
    for(int i=0;i<100000;i++){   
        hash=nonce+to_string(count);
        //cout<<ELFHash(hash)<<endl;
        if(ELFHash(hash)<pow(10,10))power[0]++;
        if(ELFHash(hash)<pow(10,9))power[9]++;
        if(ELFHash(hash)<pow(10,8))power[8]++;
        if(ELFHash(hash)<pow(10,7))power[7]++;
        if(ELFHash(hash)<pow(10,6))power[6]++;
        if(ELFHash(hash)<pow(10,5))power[5]++;
        if(ELFHash(hash)<pow(10,4))power[4]++;
        if(ELFHash(hash)<pow(10,3))power[3]++;
        if(ELFHash(hash)<pow(10,2))power[2]++;
        count++;
    }
}
void hcBKDR(int power[],string nonce){
    int count=0;
    string hash;
    for(int i=0;i<100000;i++){   
        hash=nonce+to_string(count);
        //cout<<BKDRHash(hash)<<endl;
        if(BKDRHash(hash)<pow(10,10))power[0]++;
        if(BKDRHash(hash)<pow(10,9))power[9]++;
        if(BKDRHash(hash)<pow(10,8))power[8]++;
        if(BKDRHash(hash)<pow(10,7))power[7]++;
        if(BKDRHash(hash)<pow(10,6))power[6]++;
        if(BKDRHash(hash)<pow(10,5))power[5]++;
        if(BKDRHash(hash)<pow(10,4))power[4]++;
        if(BKDRHash(hash)<pow(10,3))power[3]++;
        if(BKDRHash(hash)<pow(10,2))power[2]++;
        count++;
    }
}
void hcSDBM(int power[],string nonce){
    int count=0;
    string hash;
    for(int i=0;i<100000;i++){   
        hash=nonce+to_string(count);
        //cout<<SDBMHash(hash)<<endl;
        if(SDBMHash(hash)<pow(10,10))power[0]++;
        if(SDBMHash(hash)<pow(10,9))power[9]++;
        if(SDBMHash(hash)<pow(10,8))power[8]++;
        if(SDBMHash(hash)<pow(10,7))power[7]++;
        if(SDBMHash(hash)<pow(10,6))power[6]++;
        if(SDBMHash(hash)<pow(10,5))power[5]++;
        if(SDBMHash(hash)<pow(10,4))power[4]++;
        if(SDBMHash(hash)<pow(10,3))power[3]++;
        if(SDBMHash(hash)<pow(10,2))power[2]++;
        count++;
    }
}
void hcDJB(int power[],string nonce){
    int count=0;
    string hash;
    for(int i=0;i<100000;i++){   
        hash=nonce+to_string(count);
        //cout<<DJBHash(hash)<<endl;
        if(DJBHash(hash)<pow(10,10))power[0]++;
        if(DJBHash(hash)<pow(10,9))power[9]++;
        if(DJBHash(hash)<pow(10,8))power[8]++;
        if(DJBHash(hash)<pow(10,7))power[7]++;
        if(DJBHash(hash)<pow(10,6))power[6]++;
        if(DJBHash(hash)<pow(10,5))power[5]++;
        if(DJBHash(hash)<pow(10,4))power[4]++;
        if(DJBHash(hash)<pow(10,3))power[3]++;
        if(DJBHash(hash)<pow(10,2))power[2]++;
        count++;
    }
}
void hcDEK(int power[],string nonce){
    int count=0;
    string hash;
    for(int i=0;i<100000;i++){   
        hash=nonce+to_string(count);
        //cout<<DEKHash(hash)<<endl;
        if(DEKHash(hash)<pow(10,10))power[0]++;
        if(DEKHash(hash)<pow(10,9))power[9]++;
        if(DEKHash(hash)<pow(10,8))power[8]++;
        if(DEKHash(hash)<pow(10,7))power[7]++;
        if(DEKHash(hash)<pow(10,6))power[6]++;
        if(DEKHash(hash)<pow(10,5))power[5]++;
        if(DEKHash(hash)<pow(10,4))power[4]++;
        if(DEKHash(hash)<pow(10,3))power[3]++;
        if(DEKHash(hash)<pow(10,2))power[2]++;
        count++;
    }
}
void hcBP(int power[],string nonce){
    int count=0;
    string hash;
    for(int i=0;i<100000;i++){   
        hash=nonce+to_string(count);
        //cout<<BPHash(hash)<<endl;
        if(BPHash(hash)<pow(10,10))power[0]++;
        if(BPHash(hash)<pow(10,9))power[9]++;
        if(BPHash(hash)<pow(10,8))power[8]++;
        if(BPHash(hash)<pow(10,7))power[7]++;
        if(BPHash(hash)<pow(10,6))power[6]++;
        if(BPHash(hash)<pow(10,5))power[5]++;
        if(BPHash(hash)<pow(10,4))power[4]++;
        if(BPHash(hash)<pow(10,3))power[3]++;
        if(BPHash(hash)<pow(10,2))power[2]++;
        count++;
    }
}
void hcFNV(int power[],string nonce){
    int count=0;
    string hash;
    for(int i=0;i<100000;i++){   
        hash=nonce+to_string(count);
        //cout<<FNVHash(hash)<<endl;
        if(FNVHash(hash)<pow(10,10))power[0]++;
        if(FNVHash(hash)<pow(10,9))power[9]++;
        if(FNVHash(hash)<pow(10,8))power[8]++;
        if(FNVHash(hash)<pow(10,7))power[7]++;
        if(FNVHash(hash)<pow(10,6))power[6]++;
        if(FNVHash(hash)<pow(10,5))power[5]++;
        if(FNVHash(hash)<pow(10,4))power[4]++;
        if(FNVHash(hash)<pow(10,3))power[3]++;
        if(FNVHash(hash)<pow(10,2))power[2]++;
        count++;
    }
}

void reset(int power[]){
    for(int i=0;i<10;i++){
        power[i]=0;
    }
}
void dispRes(int power[]){
    cout<<"Less than 10^10 : "<<power[0]<<endl;
    cout<<"Less than 10^9  : "<<power[9]<<endl;
    cout<<"Less than 10^8  : "<<power[8]<<endl;
    cout<<"Less than 10^7  : "<<power[7]<<endl;
    cout<<"Less than 10^6  : "<<power[6]<<endl;
    cout<<"Less than 10^5  : "<<power[5]<<endl;
    cout<<"Less than 10^4  : "<<power[4]<<endl;
    cout<<"Less than 10^3  : "<<power[3]<<endl;
    cout<<"Less than 10^2  : "<<power[2]<<endl;
}
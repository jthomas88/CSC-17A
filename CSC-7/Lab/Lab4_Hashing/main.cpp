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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    const std::string horat="Then out spake brave Horatius, "
                            "The Captain of the Gate: "
                            "To every man upon this earth "
                            "Death cometh soon or late. "
                            "And how can man die better "
                            "Than facing fearful odds, "
                            "For the ashes of his fathers, "
                            "And the temples of his gods.";
    
    cout<<"RS Hash"<<endl;
    cout<<RSHash(horat)<<endl<<endl;
    
    cout<<"JS Hash"<<endl;
    cout<<JSHash(horat)<<endl<<endl;
    
    cout<<"PJW Hash"<<endl;
    cout<<PJWHash(horat)<<endl<<endl;
    
    cout<<"ELF Hash"<<endl;
    cout<<ELFHash(horat)<<endl<<endl;
    
    cout<<"BKDR Hash"<<endl;
    cout<<BKDRHash(horat)<<endl<<endl;
    
    cout<<"SDBM Hash"<<endl;
    cout<<SDBMHash(horat)<<endl<<endl;
    
    cout<<"DJB Hash"<<endl;
    cout<<DJBHash(horat)<<endl<<endl;
    
    cout<<"DEK Hash"<<endl;
    cout<<DEKHash(horat)<<endl<<endl;
    
    cout<<"BP Hash"<<endl;
    cout<<BPHash(horat)<<endl<<endl;
    
    cout<<"FNV Hash"<<endl;
    cout<<FNVHash(horat)<<endl<<endl;
    
    cout<<"AP Hash"<<endl;
    cout<<APHash(horat)<<endl<<endl;

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
#include "myheader.h"
/* 
 * File:   rndDgit.cpp
 * Author: Miguel Galvez
 * Purpose: Generate a random digit from 1-9
 * Created on September 25, 2021, 12:00 AM
 */
//Return a random digit
char rndDgit(){
    char rndNum;         //Random number
    rndNum=rand()%10+48; //Ascii Code for numbers '0'=48 and '9'=57
    return rndNum; 
}
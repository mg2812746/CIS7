#include "myheader.h"
/* 
 * File:   genCode.cpp
 * Author: Miguel Galvez
 * Purpose: Mastermind Game
 * Created on September 25, 2021, 12:00 AM
 */
//Randomly Generates a Code to be broken
void genCode(char *key, bool dup, short size){
    //Randomly Generate Code 
    //If duplicates are allowed, generate a 
    //random code with duplicates
    if(dup){
        for(int i=0;i<size;i++){
            key[i]=rndDgit();   //Assign a random character
        }
    //If duplicates are not allowed, generate a code without duplicates
    }else{
        //Start with assigning the first element of key to a random digit 1-9
        key[0]=rndDgit();
        //Then assign a random digit to the next element of key
        for(int i=1;i<size;i++){
            key[i]=rndDgit();
            //While there is a repeated character in the code, try again
            while(chkDup(key,i)) 
                key[i]=rndDgit();
        }
    }
}
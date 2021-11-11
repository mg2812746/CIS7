#include "myheader.h"
/* 
 * File:   whtPegs.cpp
 * Author: Miguel Galvez
 * Purpose: Generate white pegs for Mastermind Game
 * Created on September 25, 2021, 12:00 AM
 */
//Compute Red+White Pegs and Store it into white
void whtPegs(MstrMnd *ptr,unsigned short &white){
    char cpy[ptr->size];          //Copy of the code
    //Copy code into separate array
    strcpy(cpy,ptr->key);
    //Check if there are any matches with the user code and key code copy
    for(int i=0;i<ptr->size;i++){
        for(int j=0;j<ptr->size;j++){
            //If a match was found with corresponding key code, white it out
            //so that it will not reoccur
            if(cpy[i]==ptr->usrCode[j]){
                white++;          //Increment white to get Red+White
                cpy[i]=48;        //Ascii code for 0
            }
        }
    }
}
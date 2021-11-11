#include "myheader.h"
/* 
 * File:   hint.cpp
 * Author: Miguel Galvez
 * Purpose: Displays a hint to the user for mastermind game
 * Created on September 25, 2021, 12:00 AM
 */
//Display hint depending on user code
void hint(MstrMnd *ptr){
    unsigned short red=0,    //Correct numbers in the right spot
                   white=0,  //Correct number but incorrect spot
                   empty=0;    //Incorrect Code      
    //Compute the total number of "red" codes
    for(int i=0;i<ptr->size;i++){
        //If correct code was in correct spot, Increment total correct codes
        if(ptr->key[i]==ptr->usrCode[i]){
            red++;  
        }
    }
    //Return white=red+white
    whtPegs(ptr,white);
    //Subtract off reds from white to get white
    white-=red;
    //Divide white by 2 so we are left with the
    //Correct amount of white pegs
    white/=2;
    //Compute total empty pegs
    empty=(ptr->size)-(red+white);
    //If empty is negative, 0 it and decrement white
    if(empty<0){
        empty++;
        white--;
    }
    //Give appropriate hints
    dspHint(red,white,empty);
}
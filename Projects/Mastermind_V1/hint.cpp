#include <valarray>

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
                   empty;    //Incorrect Code      
    //Compute the total number of "red" codes
    for(int i=0;i<ptr->size;i++){
        //If correct code was in correct spot, Increment total correct codes
        if(ptr->key[i]==ptr->usrCode[i]){
            red++;  
        }
        else{
            for(int j=i+1;j<ptr->size;j++){
                if(ptr->key[i]==ptr->usrCode[j]){
                    white++;
                }
            }
        }
    }
    //Give appropriate hints
    dspHint(red,white,empty);
}
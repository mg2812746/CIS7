#include "myheader.h"
/* 
 * File:   prpGme.cpp
 * Author: Miguel Galvez
 * Purpose: Prepare Mastermind Game
 * Created on September 25, 2021, 12:00 AM
 */
//Prompt User for Mastermind Game Settings
void prpGme(MstrMnd *ptr){
    //Prompt User to allow or not allow duplicates
    allwDup(ptr->dup);
    //Dynamically Allocate Code length
    ptr->size=codLngth();
    //Dynamically Allocate User Input Length
    ptr->usrCode=dupLngth(ptr->size);
    //Dynamically Allocate Key Code Length
    ptr->key=dupLngth(ptr->size);
    //Generate a Code for the game
    genCode(ptr->key,ptr->dup,ptr->size); 
}
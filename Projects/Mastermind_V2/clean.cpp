#include "myheader.h"
/* 
 * File:   clean.cpp
 * Author: Miguel Galvez
 * Purpose: Cleanup dynamic memory from Mastermind Game
 * Created on September 25, 2021, 12:00 AM
 */
//Delete Dynamically Allocated Arrays
void clean(MstrMnd *ptr){
    delete [] ptr->usrCode;
    delete [] ptr->key;
}
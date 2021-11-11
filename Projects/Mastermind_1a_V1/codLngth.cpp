#include "myheader.h"
/* 
 * File:   codLngth.cpp
 * Author: Miguel Galvez
 * Purpose: Prompt player for code length in Mastermind Game
 * Created on September 25, 2021, 12:00 AM
 */
//Determine Length of code
short codLngth(){
    short size;
    //Prompt User for code length
    cout<<"Enter 4,6, or 8 for the code length. ";
    //DEFAULT to 4
    size=4;
    cout<<size<<endl;
    return size;
}
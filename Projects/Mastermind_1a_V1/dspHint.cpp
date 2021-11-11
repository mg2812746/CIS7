#include "myheader.h"
/* 
 * File:   dspHint.cpp
 * Author: Miguel Galvez
 * Purpose: Display a hint for Mastermind Game
 * Created on September 25, 2021, 12:00 AM
 */
//Displays the appropriate hint
void  dspHint(short red,short white,short empty){
    //Display (correct) pegs
    cout<<setw(5)<<red;
    //Display (correct but in wrong spot) pegs
    cout<<setw(5)<<white;
    //Display (incorrect) pegs
    cout<<setw(5)<<empty;
}
#include "myheader.h"
/* 
 * File:   dspHint.cpp
 * Author: Miguel Galvez
 * Purpose: Display a hint for Mastermind Game
 * Created on September 25, 2021, 12:00 AM
 */
//Displays the appropriate hint
void  dspHint(short red,short white,short empty){
    cout<<setw(8)
        <<red<<setw(17)<<white
        <<setw(16)<<red+white<<endl;
}
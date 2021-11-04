#include "myheader.h"
/* 
 * File:   dspHint.cpp
 * Author: Miguel Galvez
 * Purpose: Display a hint for Mastermind Game
 * Created on September 25, 2021, 12:00 AM
 */
//Displays the appropriate hint
void  dspHint(short red,short white,short empty){
    cout<<"Hint:";
    //Display asterisk for red (correct) pegs
    if(red!=0){
        for(int i=0;i<red;i++){
            cout<<"*";
        }
    }
    //Display x for white (correct but in wrong spot) pegs
    if(white!=0){
        for(int i=0;i<white;i++){
            cout<<"x";
        }
    }
    //Display o for empty (incorrect) pegs
    if(empty!=0){
        for(int i=0;i<empty;i++){
            cout<<"o";
        }
    }
    cout<<endl;
}
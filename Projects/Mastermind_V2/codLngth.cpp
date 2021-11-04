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
    cin>>size;
    //INPUT VALIDATION-Make sure correct size was entered
    while(size!=4&&size!=6&&size!=8){
        cout<<"ERROR: Please enter 4, 6, or 8. ";
        cin>>size;
    }
    return size;
}
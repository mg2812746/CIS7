#include "myheader.h"
/* 
 * File:   allwDup.cpp
 * Author: Miguel Galvez
 * Purpose: Prompt user to allow or not allow
 *          duplicates for Mastermind Game
 * Created on September 25, 2021, 12:00 AM
 */
//Prompt User to either allow or not allow duplicates
void allwDup(bool &x){
    short y;        //Test input to check validation
    cout<<"Would you like to allow duplicates?\n"
        <<"Enter 1 for yes or 0 for no. ";
    //DEFAULT TO YES
    y=1;
    cout<<y<<endl;
    x=y;
}
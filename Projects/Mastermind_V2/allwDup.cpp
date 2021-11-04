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
    cin>>y;
    //INPUT VALIDATION-Must be 0 or 1
    while(y!=0&&y!=1){
        cout<<"ERROR: Please enter either 1 for duplicates or 0 "
            <<"for no duplicates. ";
        cin>>y;
    }
    //If input was acceptable, assign it to bool value
    x=y;
    cin.ignore();   //Clear the buffer
}
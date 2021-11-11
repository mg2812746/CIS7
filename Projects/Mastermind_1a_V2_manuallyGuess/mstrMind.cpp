#include "myheader.h"
/* 
 * File:   mstrMind.cpp
 * Author: Miguel Galvez
 * Purpose: Mastermind Game
 * Created on November 9, 2021, 3:14PM
 */
//Mastermind game
void mstrMind(MstrMnd *x){
    const short ATMPS=10000;        //Attempts allowed
    //Display header
    cout<<setw(5)<<"Code"<<setw(10)<<"Guess"<<setw(10)
        <<"#right"<<setw(25)<<"#right in wrong spot"
        <<setw(7)<<"Sum"<<setw(25)<<"Enter code:";
    cin>>x->usrCode;
    //Assign null terminator to end of string
    x->usrCode[4]='\0';
    //Manually enter code
    for(int i=0;i<ATMPS;i++){
        cout<<setw(5)<<x->key<<setw(10)<<x->usrCode;
        hint(x);
        cout<<setw(82)<<"Enter code:";
        cin>>x->usrCode;
    }
}
#include "myheader.h"
/* 
 * File:   mstrMind.cpp
 * Author: Miguel Galvez
 * Purpose: Mastermind Game
 * Created on September 25, 2021, 12:00 AM
 */
//Mastermind game
void mstrMind(MstrMnd *x){
    const short ATMPS=10;        //Attempts allowed
    //Give instructions to User
    cout<<"Enter code in the format: ";
    for(int k=0;k<x->size;k++){
        cout<<"x";
    }
    cout<<" where x is a number 1-9\n";
    cout<<"Symbol for correct numbers in correct spot: *"<<endl;
    cout<<"Symbol for correct numbers in incorrect spot: x"<<endl;
    cout<<"Symbol for incorrect codes: o"<<endl;    
    //Start Mastermind Game 
    for(int trial=0;trial<ATMPS;trial++){
        cout<<"Attempt "<<trial+1<<"/"<<ATMPS<<endl;
        cout<<"enter code: ";
        for(int i=0;i<x->size;i++){
            cin>>x->usrCode[i];
            //INPUT VALIDATION-If incompatible code was entered
            while((x->usrCode[i])>57||(x->usrCode[i])<49){
                cout<<"ERROR: Please enter a digit between 1-9. ";
                cout<<"To replace: "<<x->usrCode[i]<<" \n";
                cin>>x->usrCode[i];
            }
        }
        //If correct code was not entered, provide a hint
        if(strstr(x->key,x->usrCode)==NULL){
            hint(x);
        //Otherwise, user entered the correct code. 
        }else{
            //Congratulate user
            cout<<"CONGRATULATIONS!!! YOU WON THE GAME!";
            //End iteration
            trial=ATMPS;
        }
    }
}
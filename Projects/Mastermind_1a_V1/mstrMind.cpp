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
    cout<<"Code"<<setw(5)<<"Guess"<<setw(7)
        <<"#right"<<setw(15)<<"#right in wrong spot"
        <<setw(7)<<"Sum"<<endl;
    //Assign null terminator to end of string
    x->usrCode[4]='\0';
    //SEQUENTIALLY GENERATE CODE
    for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                for(int k=0;k<=9;k++){
                    for(int z=0;z<=9;z++){
                        x->usrCode[0]=48+i;
                        x->usrCode[1]=48+j;
                        x->usrCode[2]=48+k;
                        x->usrCode[3]=48+z;
        cout<<x->key<<setw(5)<<x->usrCode;
        //If correct code was not entered, provide a hint
                        if(strstr(x->key,x->usrCode)==NULL){
                            hint(x);
                            cout<<endl;
        //Otherwise, user entered the correct code. 
                        }else{
        //Congratulate user
                        cout<<"\nCONGRATULATIONS!!! YOU WON THE GAME!";
                        //End iteration
                        i=10,
                        j=10,
                        k=10,
                        z=10;
                        }
                    }
                }
            }
        }
    }
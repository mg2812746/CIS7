/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Purpose: Mastermind Game
 * Created on September 25, 2021, 12:00 AM
 */
#include "myheader.h"   //Header file
int main(int argc, char** argv){
    //Set Seed for Random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Initialize Variables
    MstrMnd game;       //Mastermind game structure
    MstrMnd *ptr=&game; //Pointer to mastermind structure
    //Prepare Mastermind Game
    prpGme(ptr);        
    //Start Mastermind Game
    mstrMind(ptr); 
    //Cleanup
    clean(ptr);
    return 0;
}
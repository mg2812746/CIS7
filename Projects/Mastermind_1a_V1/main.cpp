/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Purpose: Automate Mastermind Sequentially (Project 1a)
 * Created on November 9, 2021, 3:09 PM
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
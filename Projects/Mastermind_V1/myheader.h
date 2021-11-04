/* 
 * File:   myheader.h
 * Author: Miguel Galvez
 * Created on October 6, 2021, 8:15 PM
 */
#ifndef MYHEADER_H
#define MYHEADER_H
//Libraries
#include <iostream>              //cout,cin
#include <ctime>                 //time()
#include <cstring>               //strstr(),strcpy()
using namespace std;
//Public Structure
struct MstrMnd{                  //Mastermind Structure
    char *usrCode;               //User-entered code
    char *key;                   //Auto-generated key code to be found by user
    short size;                  //Code length
    bool  dup;                   //True to allow duplicates or false otherwise
};
//Function Prototypes
void  prpGme(MstrMnd *);           //Prepare Mastermind Game
void  allwDup(bool &);             //Prompt user to allow duplicates or not
short codLngth();                  //Set Code Length for Mastermind game     
char *dupLngth(short);             //Duplicate Code Length for User Input     
void  genCode(char *,bool,short);  //Generate Code to be Broken by User     
void  mstrMind(MstrMnd *);         //Mastermind game     
void  hint(MstrMnd *);             //Compute the appropriate hint     
void  dspHint(short,short,short);  //Displays Hint     
void  clean(MstrMnd *);            //Cleanup Dynamically Allocated Memory     
char  rndDgit();                   //Returns a random digit     
bool  chkDup(char *,int);          //If there is a duplicate, return true     
#endif /* MYHEADER_H */
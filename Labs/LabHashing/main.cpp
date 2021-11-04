/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on Oct 26th 2021 1:13PM
 * Purpose: To Demonstrate Hash
 */

//System Libraries Here
#include "GeneralHashFunctions.h"
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    char str[]="Then out spake brave Horatius,\n"
               "The Captain of the Gate:\n"
               "To every man upon this earth\n"
               "Death cometh soon or late.\n"
               "And how can man die better\n"
               "Than facing fearful odds,\n"
               "For the ashes of his fathers,\n"
               "And the temples of his gods.\n";  
    unsigned int hash;
    //Input or initialize values Here

    //Display the string to be hashed
    cout<<"String to be hashed: \n"<<str;
    //RSHash
    cout<<setw(10)<<left<<"RSHash:";
    hash=RSHash(str);               
    cout<<hash<<endl;
    //JSHash
    cout<<setw(10)<<"JSHash:";      
    hash=JSHash(str);               
    cout<<hash<<endl;
    //PJWHash
    cout<<setw(10)<<"PJWHash:";     
    hash=PJWHash(str);              
    cout<<hash<<endl; 
    //BKDRHash
    cout<<setw(10)<<"BKDRHash:";    
    hash=BKDRHash(str);             
    cout<<hash<<endl;               
    //SDBMHash
    cout<<setw(10)<<"SDBMHash:";    
    hash=SDBMHash(str);             
    cout<<hash<<endl;
    //DJBHash
    cout<<setw(10)<<"DJBHash:";
    hash=DJBHash(str);
    cout<<hash<<endl;
    //DEKHash
    cout<<setw(10)<<"DEKHash:";
    hash=DEKHash(str);
    cout<<hash<<endl;
    //BPHash
    cout<<setw(10)<<"BPHash:";
    hash=BPHash(str);
    cout<<hash<<endl;
    //FNVHash
    cout<<setw(10)<<"FNVHash:";
    hash=FNVHash(str);
    cout<<hash<<endl;
    //APHash
    cout<<setw(10)<<"APHash:";
    hash=APHash(str);
    cout<<hash<<endl;
    //Cleanup
    return 0;
}
#include "myheader.h"
/* 
 * File:   chkDup.cpp
 * Author: Miguel Galvez
 * Purpose: Determine if there is a duplicate value in array 
 * Created on September 25, 2021, 12:00 AM
 */
//Returns true if duplicate was detected
bool chkDup(char *ptr,int n){
    //Not applicable if we're in the first entry
    if(n!=0){
        //Starting from the first entry, compare the 
        //entry recently entered with each individual entry
        for(int i=0;i<n;i++){
            if(ptr[n]==ptr[i])
                return true;    //If entry is the same, return true
        }
    }
    return false;               //Otherwise return false
}
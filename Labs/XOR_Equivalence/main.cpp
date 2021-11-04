/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on Sept 9th, 2020, 12:30PM
 * Purpose:  Prove Exclusive Or Equivalence
 */

//System Libraries Here
#include <iostream> //Input/Output Stream library
#include <iomanip> //Input/Output Manipulation library
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    bool p,q;
    //Display the Heading
    cout<<"p q ~p ~q p&&q p||q p^q p^q^q p^q^p !(p&&q) !p||!q !(p||q) !p^!q"
        <<"  (p&&q)||~(p||q) = !(p^q)  (p||q)&&~(p&&q) = p^q"<<endl;
    //Display the Rows
    for(int i=0;i<=3;i++){
        i==0?p=true,q=true:     //First Row
        i==1?q=false:           //Second Row
        i==2?p=false,q=true:    //Third Row
        i==3?q=false:q=true;    //Fourth Row
        cout<<(p?'T':'F')<<setw(2)                      //Column 1
            <<(q?'T':'F')<<setw(3)                      //Column 2
            <<(!p?'T':'F')<<setw(3)                     //Column 3
            <<(!q?'T':'F')<<setw(4)                     //Column 4
            <<(p&&q?'T':'F')<<setw(5)                   //Column 5
            <<(p||q?'T':'F')<<setw(4)                   //Column 6
            <<((p^q)?'T':'F')<<setw(5)                  //Column 7
            <<((p^q^q)?'T':'F')<<setw(7)                //Column 8
            <<((p^q^p)?'T':'F')<<setw(6)                //Column 9
            <<((!(p&&q))?'T':'F')<<setw(8)              //Column 10
            <<((!p||!q)?'T':'F')<<setw(7)               //Column 11
            <<((!(p||q))?'T':'F')<<setw(7)              //Column 12
            <<((!p^!q)?'T':'F')<<setw(11)               //Column 13
            <<(((p&&q)||!(p||q))?'T':'F')<<setw(15)     //Column 14
            <<((!(p^q))?'T':'F')<<setw(12)              //Column 15
            <<(((p||q)&&(!(p&&q)))?'T':'F')<<setw(12)   //Column 16
            <<((p^q)?'T':'F')                           //Column 17
            <<endl;
    }
    //Exit
    return 0;
}
/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on Sept 6, 2021, 10:19AM
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function Library
#include <ctime>     //Time Library
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();           //Randomly generates digit characters
void prpLuhn(char[],int); //Prepares the Luhn Sequence
int  cnvrt(char);         //Convert 1 digit char to integer
char cnvrt(int);          //Convert 1 digit integer to a char
void output(char[],int);  //Output the sequence as integers
//Function you are to create
void Luhn(char[],int);    //Calculate and append the Luhn Digit

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Set the Credit Card size
    const int SIZE=17;
    char crdCard[SIZE];
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn Digit"<<endl;
    prpLuhn(crdCard,SIZE-2);
    
    //Output the preLuhn credit card
    cout<<crdCard<<endl;
    output(crdCard,SIZE-2);
    
    //Now create a function that fills the last digit
    //using the Luhn Algorithm
    Luhn(crdCard,SIZE);
    cout<<"The random number with Luhn Encoding, Output Here!"<<endl;
    cout<<"This is working -> "<<crdCard<<endl;
    
    //Exit Stage Right
    return 0;
}

void Luhn(char cc[],int n){
    const char ONE=1;    //Constant Number 1 
    short dup[n];        //Duplicate char array as short array
    short sum=0;         //Sum of All Credit Card Digits Initialized to 0
    //Copy Char Array Contents to Another Short Array
    for(int i=0;i<n-2;i++){
        dup[i]=cnvrt(cc[i]);
    }
    //Double every other digit from right to left
    for(int i=n-3;i>=0;i-=2){
        dup[i]*=2;
        //Sum the Digits of the Products if Greater Than 9
        if(dup[i]>9){
            dup[i]=ONE+(dup[i]%10);
        }
        //Gather the Sum of all Digits
        sum+=dup[i]+dup[i-ONE];
    }
    //Append Last Credit Card Digit
    cc[n-2]=(sum*9%10)+48;
}

void output(char cc[],int n){
    cout<<"The char array output as each integer digit"<<endl;
    for(int i=0;i<n;i++){
        cout<<cnvrt(cc[i]);
    }
    cout<<endl;
}

char  cnvrt(int digit){
    if(digit<0||digit>9){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
    }
    return digit+48;
}

int  cnvrt(char digit){
    if(digit<'0'||digit>'9'){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
    }
    return digit-'0';
}

void prpLuhn(char cc[],int n){

    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    return rand()%10+48;//Ascii Code for numbers '0'=48 and '9'=57
}
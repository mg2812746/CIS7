/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on November 3rd, 2021
 * Purpose: To demonstrate Bloom Filter with 2 Hashes
 */

//System Libraries Here
#include "GeneralHashFunctions.h"
//User Libraries Here

//Function Prototypes Here
void prompt(bool [],char [],unsigned short &);  //Adds string hash to bit vector
void test(bool [],char [], unsigned short,      //Tests string for membership
            short, short,float,unsigned short);
//Program Execution Begins Here
int main(int argc, char** argv){
    //Declare all Variables Here
    const float E=2.71828182;    //Euler's number
    const unsigned short SIZE=30;//Length of string
    const short BIT=16;          //Size of bit array+null
    const short N=15,            //Number of bits
                K=2;             //Number of Hashes
    unsigned short n=0,          //Number of keys used in hash
            elem=0;              //Number of total elements
    char str[SIZE];              //char string
    bool bit[BIT];               //bit array
    //Get strings to store values in bit array
    cout<<"Enter a string or enter 0 to stop: ";
    cin>>str;
    //Begin iteration for strings as long as user didn't enter "0"
    while(str[0]+strlen(str)!=49){
        elem++;
        prompt(bit,str,n);
    }
    //Prompt the user to test a string
    cout<<"Test an element for membership, or enter 0 to stop: ";
    cin>>str;
    //Begin iteration to test hash value as long as user didn't enter "0"
    while(str[0]+strlen(str)!=49){
        test(bit,str,n,K,N,E,elem);
    }
    //Exit
    return 0;
}
//Function Implementation
void prompt(bool bit[],char str[],unsigned short &n){
    //Display hash values
    cout<<"RSHash: "<<RSHash(str)%15<<endl
        <<"APHash: "<<APHash(str)%15<<endl;
    //Put string in hash and assign 1 to valued index 
    //and increment n if not already set
    if(bit[RSHash(str)%15]!=1){bit[RSHash(str)%15]=1;n++;}
    if(bit[APHash(str)%15]!=1){bit[APHash(str)%15]=1;n++;}
    //Prompt User
    cout<<"Enter a string or enter 0 to stop: ";
    cin>>str;
}
void test(bool bit[],char str[], unsigned short n,
            short K, short N,float E,unsigned short elem){
    float probKM,                //Probability of FP
          probFP;                //Probability of False positive 
                                 // using general formula
    //Display the hash value
    cout<<"RSHash: "<<RSHash(str)%15<<endl
        <<"APHash: "<<APHash(str)%15<<endl;
    //Is element in set?
    cout<<"Is the element in the set? ";
    //Are both elements flagged in the same spot?
    //If so, say maybe, if not say yes. 
    ((bit[RSHash(str)%15]+bit[APHash(str)%15])==2)?cout<<"maybe\n":
                                                   cout<<"no\n";
    //Compute general probability of false positive
    probKM=1-pow(E,-1.0*K*elem/N);      
    probFP=probKM*probKM;   //Multiply false positive by power of K
    probFP*=100;            //Create percentage
    //Compute actual probability of false positive
    probKM=1.0*n/N;
    probKM*=probKM;
    probKM*=100;
    //Display probability of false positive
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Probability of a false positive: %"<<probKM<<endl;
    cout<<"Probability of a false positive general formula: %"<<probFP<<endl;
    //Prompt the user to test a string
    cout<<"Test an element for membership, or enter 0 to stop: ";
    cin>>str;
}
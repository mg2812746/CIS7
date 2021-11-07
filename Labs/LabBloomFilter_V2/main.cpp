/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on November 3rd, 2021
 * Purpose: To demonstrate Bloom Filter with 9 Hashes Using 
 *          Random Input From a File
 */

//System Libraries Here
#include "GeneralHashFunctions.h"
//User Libraries Here

//Function Prototypes Here
void prompt(bool [],char [],unsigned short &,
            fstream&);                           //Adds string hash to bit vector
void test(bool [],char [], unsigned short,      //Tests string for membership
            short, short,fstream&,float,
            unsigned short elem);
//Program Execution Begins Here
int main(int argc, char** argv){
    //Declare all Variables Here
    const float E=2.7182818284;  //Euler's number
    const unsigned short SIZE=30;//Length of string
    const short BIT=16;          //Size of bit array+null
    const short N=15,            //Number of bits
                K=9;             //Number of Hashes
    unsigned short  n=0,         //Number of keys used
                    elem=0;      //Number of elements
    char str[SIZE];              //char string
    bool bit[BIT];               //bit array
    fstream in;                  //Input file
    //Open the input file
    in.open("rndInp.txt",ios::in);
    //Get strings to store values in bit array
    in>>str;
    cout<<"Enter a string or enter 0 to stop: "<<str<<endl;
    //Begin iteration for strings as long as user didn't enter "0"
    while(str[0]+strlen(str)!=49){
        elem++;
        prompt(bit,str,n,in);
    }
    //Prompt the user to test a string
    in>>str;
    cout<<"Test an element for membership, or enter 0 to stop: ";
    cout<<str<<endl;
    //Begin iteration to test hash value as long as user didn't enter "0"
    while(str[0]+strlen(str)!=49){
        test(bit,str,n,K,N,in,E,elem);
    }
    //Close File
    in.close();
    //Exit
    return 0;
}
//Function Implementation
void prompt(bool bit[],char str[],unsigned short &n,
            fstream &in){
    //Display hash values
    cout<<"RSHash: "<<RSHash(str)%15<<endl
        <<"JSHash: "<<JSHash(str)%15<<endl
        <<"PJWHash: "<<PJWHash(str)%15<<endl
        <<"ELFHash: "<<ELFHash(str)%15<<endl
        <<"BKDRHash: "<<BKDRHash(str)%15<<endl
        <<"SDBMHash: "<<SDBMHash(str)%15<<endl
        <<"DJBHash: "<<DJBHash(str)%15<<endl
        <<"DEKHash: "<<DEKHash(str)%15<<endl    
        <<"BPHash: "<<BPHash(str)%15<<endl;          
    //If value 
    //Put string in hash and assign 1 to valued index 
    //and increment n if not already set
    if(bit[RSHash(str)%15]!=1){bit[RSHash(str)%15]=1;n++;}
    if(bit[JSHash(str)%15]!=1){bit[JSHash(str)%15]=1;n++;}
    if(bit[PJWHash(str)%15]!=1){bit[PJWHash(str)%15]=1;n++;}
    if(bit[ELFHash(str)%15]!=1){bit[ELFHash(str)%15]=1;n++;}
    if(bit[BKDRHash(str)%15]!=1){bit[BKDRHash(str)%15]=1;n++;}
    if(bit[SDBMHash(str)%15]!=1){bit[SDBMHash(str)%15]=1;n++;}
    if(bit[DJBHash(str)%15]!=1){bit[DJBHash(str)%15]=1;n++;}
    if(bit[DEKHash(str)%15]!=1){bit[DEKHash(str)%15]=1;n++;}
    if(bit[BPHash(str)%15]!=1){bit[BPHash(str)%15]=1;n++;}
    //Prompt User
    in>>str;
    cout<<"Enter a string or enter 0 to stop: "<<str<<endl;
}
void test(bool bit[],char str[], unsigned short n,
            short K, short N,fstream &in,float E,
            unsigned short elem){
    float probKM,
          probFP;                //Probability of False positive 
                                 // = 1-e^(-km/n))^k
    //Display the hash value
    cout<<"RSHash: "<<RSHash(str)%15<<endl
        <<"JSHash: "<<JSHash(str)%15<<endl
        <<"PJWHash: "<<PJWHash(str)%15<<endl
        <<"ELFHash: "<<ELFHash(str)%15<<endl
        <<"BKDRHash: "<<BKDRHash(str)%15<<endl
        <<"SDBMHash: "<<SDBMHash(str)%15<<endl
        <<"DJBHash: "<<DJBHash(str)%15<<endl
        <<"DEKHash: "<<DEKHash(str)%15<<endl    
        <<"BPHash: "<<BPHash(str)%15<<endl; 
    //Is element in set?
    cout<<"Is the element in the set? ";
    //Are all elements flagged in the same spot?
    //If so, say maybe, if not say yes. 
    bit[RSHash(str)%15]+bit[JSHash(str)%15]+
    bit[PJWHash(str)%15]+bit[ELFHash(str)%15]+       
    bit[BKDRHash(str)%15]+bit[SDBMHash(str)%15]+        
    bit[DJBHash(str)%15]+bit[DEKHash(str)%15]+
    bit[BPHash(str)%15]==9?cout<<"maybe\n":
                           cout<<"no\n";
    //Compute probability of false positive
    probFP=1-pow(E,-1.0*K*elem/N);
    probFP=pow(probFP,K);
    probFP*=100;   //Create percentage
    probKM=1.0*n/N;
    cout<<"n:"<<n<<endl;
    probKM=pow(probKM,K);
    probKM*=100;
    //Display probability of false positive
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Probability of a false positive: %"<<probKM<<endl;
    cout<<"Probability of a false positive general formula: %"<<probFP<<endl;
    //Prompt the user to test a string
    cout<<"Test an element for membership, or enter 0 to stop: ";
    in>>str;
    cout<<str<<endl;
}
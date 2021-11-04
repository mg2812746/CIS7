/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on Sept 22, 2021, 10:37PM
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function Library
#include <ctime>     //Time Library
#include <iomanip>   //Setprecision(), fixed
using namespace std;

//Global Constants

//Enumerated Data Type
enum CrdCard{AMEX,VISA,MSTRCRD,DSCVR,ALL};     
//Function Prototypes
char rndDgit();             //Randomly generates digit characters
char *genCC(CrdCard );       //Returns a valid credit card number   
void flipDig(char []);      //Randomly flip one digit from the CC number
bool validCC(char []);      //Determine if the result is a valid CC
void prpLuhn(char [], int);  //Prepare credit card number for Luhn
void Luhn(char cc[], int ); //Calculate and append the Luhn Digit
int  cnvrt(char);           //Convert 1 digit char to integer
char cnvrt(int);            //Convert 1 digit integer to a char
short rndDblDgit(char cc[]);  //Generates a random digit from 0-max digit

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables Here
    CrdCard type=ALL;          //Credit Card Type
    const unsigned int RUN=10000;//Number of Test Cases
    char *ptr;                   //Pointer to credit card number
    unsigned int valid;          //Total Valid Cards After Flip
    unsigned int invalid;        //Total Invalid Cards After Flip
    float prcntV;       //Percent of valid cards
    //Get Digits for Credit Card
    for(int i=0;i<RUN;i++){
    //Generate Discover Credit Card Numbers
    ptr=(genCC(type));  
    //Randomly Flip One Digit
    flipDig(ptr);
    //Tally valid cards
    if(validCC(ptr)) valid++;
    //Cleanup Dynamic Allocation When Iteration Ends
    delete [] ptr;
    }
    //Assign invalid cards to the total runs minus total valid runs
    invalid=RUN-valid;
    prcntV=(static_cast<float>(valid)/RUN)*100;
    cout<<fixed<<setprecision(2)<<"Percentage of total valid cards: "
        <<"%"<<prcntV<<endl;
    //Exit Stage Right
    return 0;
}
//Randomly generates digit characters
char rndDgit(){
    return rand()%10+48; //Ascii Code for numbers '0'=48 and '9'=57
}
//Randomly generates a digit 0-max digit of specific type of card
short rndDblDgit(char cc[]){
    short dblDgit;       //Our random digit between 0 and 16
    char max;           //Maximum number of digits
    dblDgit=rand()%100;
    cc[0]=='5'?max=15:
    cc[0]=='4'?max=15:
               max=14;   
    while(dblDgit>max) dblDgit=rand()%100;
    return dblDgit;
}
//Returns a valid credit card number
char *genCC(CrdCard type){
    //Prep Credit Card Depending on Type
    char *ptr;
    short all;
    if(type==ALL){
        short randNum;
        randNum=rndDgit();
        while(randNum>51) randNum=rndDgit();
        randNum==48?all=AMEX:
        randNum==49?all=VISA:
        randNum==50?all=MSTRCRD:
                    all=DSCVR;
    }else{
        type==AMEX?   all=AMEX:
        type==VISA?   all=VISA:
        type==MSTRCRD?all=MSTRCRD:
                      all=DSCVR;
    } 
    switch(all){
        case AMEX:
            ptr= new char [16];
            ptr[0]='3';
            //second digit is either 7 or four 50/50 chance
            rndDgit()<=52?ptr[1]='7':    
                         ptr[1]='4';
            prpLuhn(ptr,14);
            Luhn(ptr,16);
            break;
        case VISA:
            ptr= new char [17];
            ptr[0]='4';
            prpLuhn(ptr,15);
            Luhn(ptr,17);
            break;
        case MSTRCRD:
            //second digit is at most 5 
            char num;
            num=rndDgit();
            while(num>53) num=rndDgit();
            ptr= new char [17];
            ptr[0]='5';
            ptr[1]=num;
            prpLuhn(ptr,15);
            Luhn(ptr,17);
            break;
        case DSCVR:
            ptr= new char [16];
            ptr[0]='6';
            ptr[1]='0';
            ptr[2]='1';
            ptr[3]='1';
            prpLuhn(ptr,14);
            Luhn(ptr,16);
            break;
        default:
            cout<<"Incompatible Card Type. "<<endl;
            exit(EXIT_FAILURE);
    }
    return ptr;
}     
//Randomly flip one digit from the CC number
void flipDig(char cc[]){
    cc[rndDblDgit(cc)]=rndDgit();
}  
//Determine if the result is a valid CC
bool validCC(char cc[]){
    char ccLast;    //Takes the last digit of credit card
    char max;       //Maximum number of digits
    bool valid;     //Truth value for valid or invalid
    cc[0]=='5'?max=17, ccLast=cc[15]:
    cc[0]=='4'?max=17, ccLast=cc[15]:
               max=16, ccLast=cc[14];   
    Luhn(cc, max);
    cc[max-2]==ccLast?valid=true:valid=false;
    return valid;
}
void prpLuhn(char cc[], int n){
    //Create a random cc in prep for Luhn checksum
    char strt;     //Starting value to assign digits
    //Assign starting value depending on credit card type
    cc[0]=='6'?strt=4:
    cc[0]=='4'?strt=1:
               strt=2;
                      
    for(int i=strt;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n+1;i<=n+2;i++){
        cc[i]='\0';
    }
}
//Calculate and append the Luhn Digit
void Luhn(char cc[],int n){
    const char ONE=1;    //Constant Number 1 
    short dup[n];        //Duplicate char array as short array
    short sum=0;         //Sum of All Credit Card Digits Initialized to 0
    //Copy Char Array Contents to Another Short Array
    for(int i=0;i<n-2;i++){
        dup[i]=cnvrt(cc[i]);
    }
    //Double every other digit from right to left
    for(int i=n-1;i>=0;i-=2){
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
//Convert 1 digit integer to a char
char cnvrt(int digit){
    if(digit<0||digit>9){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
    }
    return digit+48;
}
//Convert 1 digit char to integer
int cnvrt(char digit){
    if(digit<'0'||digit>'9'){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
    }
    return digit-'0';
}



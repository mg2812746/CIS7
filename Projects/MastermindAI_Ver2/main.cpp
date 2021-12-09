/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on December 8, 2021, 4:34 PM
 * Purpose: Mastermind Project AI version 2
 * Description: We will start the algorithm by starting the guess with
 *              the first two possible codes "0011" and then continue 
 *              our algorithm from there depending on our pegs.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

//Function Prototypes
string AI(char,char);
bool eval(string,string,char &,char &);
string set();

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    string code,guess;  //code to break, and current guess
    char rr,rw;         //right digit in right place vs. wrong place
    int nGuess;         //number of guesses
    
    //Initialize Values
    nGuess=0;
    code=set();
    rr=rw=0;
    
    //Loop until solved and count to find solution
    do{
       nGuess++;
       guess=AI(rr,rw);
    }while(eval(code,guess,rr,rw)&&nGuess<16);
    //Check evaluation
    cout<<nGuess<<" "<<code<<" "<<guess<<endl;
    guess=AI(rr,rw);
    
    //Exit the program
    return 0;
}

string AI(char rr,char rw){
    //Define helper functions here
    void (*print)(string [],char [],char [],int,int)=
        [] (string g[],char r[],char w[],int nb,int ne){ 
            for(int i=nb;i<=ne;i++){
                cout<<g[i]<<" "
                    <<static_cast<int>(r[i])<<" "
                    <<static_cast<int>(w[i])<<endl;
            }
    };
    
    //Save the historical values of guesses and results
    static const int SIZE=10000;//How many guesses to save
    static string aGuess[SIZE]; //Save the guesses
    static char grr[SIZE];      //Save right guess in right spot
    static char grw[SIZE];      //Save right guess in wrong spot
    static int guess=0;         //Increment the guess number
    string sGuess="0000";       //Size the guest string
    
    //Store the results from the last guess
    grr[guess]=rr;
    grw[guess]=rw;
    
    //Test the helper function
    if(rr==4)print(aGuess,grr,grw,
            guess-10>0?guess-10:0,guess);
    if(guess==0){
        sGuess="0011";  //Guess first two possible codes
    }
    //When 0011 is evaluated
    if(guess==1){
        //If there were no pegs, increment to the next set of codes
        if(rr==0&&rw==0){
            sGuess="2233";    
        //If there were pegs, test 1111
        }else if(rr>0||rw>0){
            sGuess="1111";    //Resulting guess will be "1111"
        }
    }else if(guess==2){
        //If we tested 1111 as string and we get no pegs
        //then we know that 0 is the white peg. 
        if(sGuess=="1111"&&rr+rw==0){
            sGuess[0]=0;
            sGuess[1]=2;
            sGuess[2]=2;
            sGuess[3]=2;  //set Guess to "0222" 
        //If we got a peg from 1111, but it is not the same number 
        //as last time, that implies 
        }else if(sGuess=="1111"&&rr+rw!=0){
            
        }
        //If 
        if(sGuess=="2233"&&rr+rw==0){
            
        }
    }
    aGuess[++guess]=sGuess;//Save the result
    //Return the result
    return sGuess;
}
//Evaluates right code in right spot (red) and 
//right code in wrong spot (white)
bool eval(string code,string guess,char &rr,char &rw){
    string check="    ";
    rr=0,rw=0;
    //Check how many are right place
    for(int i=0;i<code.length();i++){
        if(code[i]==guess[i]){
            rr++;
            check[i]='x';
            guess[i]='x';
        }
    }
    //Check how many are wrong place
    for(int j=0;j<code.length();j++){
        for(int i=0;i<code.length();i++){
            if((i!=j)&&(code[i]==guess[j])&&(check[i]==' ')){
                rw++;
                check[i]='x';
                break;
            }
        }
    }
    
    //Found or not
    if(rr==4)return false;
    return true;
}
//Generates code to be solved by AI
string set(){
    string code="0000";
    for(int i=0;i<code.length();i++){
        code[i]=rand()%10+'0';
    }
    return code;
}

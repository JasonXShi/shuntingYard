/* main file
 * written by jason shi
 * 2/8/18
 */

#include <cstring>
#include "Node.h"
#include <iostream>
#include <cstdlib>
using namespace std; 

int main(){
    while(1){
        char* input = new char[100];
        cout << "Enter an expression to be outputted as postfix (Insert spaces between each token:" << endl;
        cin.getline(input, 100);
        //output as postfix
        //go through the char[] and push things to their places
            for(int i = 0; i<strlen(input); i++){
                //if is a digit
                //elseif is an operator
                
            }
        //give the option to output as prefix, infix, or postfix
        while(1){
            char* input2 = new char[5];
            cout << "Convert to prefix, infix, postfix, or exit? (PRE, IN, POST, EXIT)" << endl;
            cin.getline(input2, 5);
            if(strcmp(input2, "PRE")==0){
            
            }else if(strcmp(input2, "IN")==0){
                
            }else if(strcmp(input2, "POST")==0){
                //print out the original thing
            }else if(strcmp(input2, "EXIT")==0){
                break;
            }
        }   
    }
}

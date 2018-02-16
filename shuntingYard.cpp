/* main file
 * written by jason shi
 * 2/8/18
 */

#include <cstring>
#include "Node.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <map>
using namespace std; 

int main(){
    while(1){

        char* input = new char[100];
        cout << "Enter an expression to be outputted as postfix (Insert spaces between each token):" << endl;
        cin.getline(input, 100);
        vector<char*> v;
        char* token=strtok(input, " ");
        while(token != NULL){
            v.push_back(token);
            token = strtok(NULL, " ");
        }
        map<char, int> map;
        map['-'] = 2;
        map['+'] = 2;
        map['*'] = 3; 
        map['/'] = 3;
        map['^'] = 4;
        map['('] = 5;
        map[')'] = 5;
        for(vector<char*>::iterator i = v.begin(); i!= v.end(); advance(i, 1)){
            if(isdigit(v.at(*i))){
        
            }else{
             
            }
        }
        //output as postfix
        //go through the char[] and push things to their places
                //if is a digit
                //elseif is an operator
        //give the option to output as prefix, infix, or postfix
        while(1){
            char* input2 = new char[5];
            cout << "Convert to Prefix, Infix, Postfix, or Exit?" << endl << "(PRE, IN, POST, EXIT)" << endl;
            cin.getline(input2, 5);
            if(strcmp(input2, "PRE")==0){
                
            }else if(strcmp(input2, "IN")==0){
                
            }else if(strcmp(input2, "POST")==0){
                
            }else if(strcmp(input2, "EXIT")==0){
                break;
            }
        }   
    }
}

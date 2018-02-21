/*    Header file for the Node class
 *    Author: Jason Shi
 *    Class: CS162
 *    Date: 2/20/18
 */

#ifndef NODE_H
#define NODE_H
//import stuff
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

 class Node {
         private:
                   //intializes variables
                    Node* left; 
                    Node* right; 
                    char* content;
         public:
                    Node(); //constructor
                    ~Node(); //destructor         
                    //getters
                   Node* getRight();
                   Node* getLeft();
                   char* getContent();
                   //setters
                    void setLeft(Node* newLeft);
                    void setRight(Node* newRight);
                    void setContent(char* newContent);
};
#endif

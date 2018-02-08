/* header file for the Node class
 *    Author: Connor Shu
 *    Class: CS162
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>

#include <cstring>
using namespace std;

 class Node {
         private:
                     //member variables
                    Node* left; //previous Node in the linked list
                    Node* right; 
                    char* content;
         public:
                    Node(); //constructor
                    ~Node(); //destructor         
                    //getters
                   Node* getRight();
                   Node* getLeft();
                   Node* getContent();
                   //setters
                    void setLeft(Node* newLeft);
                    void setRight(Node* newRight);
                    void setContent(char* newContent);
};
#endif

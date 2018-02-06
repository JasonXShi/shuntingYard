/* header file for the Node class
 *
 *   Author: Connor Shu
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
                    Node(Student* content); //constructor
                    ~Node(); //destructor         
                    //getters
                   Node* getRight();
                   Student* getLeft();
                   Node* getContent();
                   //setters
                    void setLeft(Node* left);
                    void setRight(Node* right);
                    void setContent(char* content);
};
#endif

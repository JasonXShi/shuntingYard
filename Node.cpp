//Node header class for the binary tree

#include  "Node.h"
#include <cstdlib>

//Constructor for Node class
Node::Node(){
    //sets the left and right Nodes of the tree to NULL
    left = NULL;
    right = NULL;
    //sets initial content to NULL
    content = NULL;
}
//returns right Node
Node* Node::getRight(){
    return right;
}
//Returns left Node
Node* Node::getLeft(){
    return left;
}
//returns the content
char* Node::getContent(){
    return content;
}

//sets the content of the Node
void Node::setContent(char* newContent){
    content = newContent;
}
//sets the right Node
void Node::setRight(Node* newRight){
    right = newRight;
}

//sets the left Node
void Node::setLeft(Node* newLeft){
    left = newLeft; 
}

//destructor for Node (not used)
Node::~Node(){
    delete[] content;    
}

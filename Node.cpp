#include  "Node.h"
#include <cstdlib>

Node::Node(){
    left = NULL;
    right = NULL;
    content = NULL;
}

Node* Node::getRight(){
    return right;
}
Node* Node::getLeft(){
    return left;
}
char* Node::getContent(){
    return content;
}

void Node::setContent(char* newContent){
    content = newContent;
}

void Node::setRight(Node* newRight){
    right = newRight;
}

void Node::setLeft(Node* newLeft){
    left = newLeft; 
}

Node::~Node(){
    delete[] content;    
}

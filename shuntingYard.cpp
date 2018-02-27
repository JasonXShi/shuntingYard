/* implementation of shunting yard and binary expression tree
 * written by jason shi
 * 2/8/18
 * this program converts an infix expression to postfix using a shunting yard algorithm, then inputs a postfix expression into a binary expression tree
 */
//including stuff
#include <cstring>
#include "Node.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <map>
#include <stack>
using namespace std;
//method to print out the binary expression tree with postfix
void post(Node* head){
	//makes sure head isn't null
	if(head==NULL){
		return;
	}
	//recursively calls the left and right nodes
	post(head->getLeft());
	post(head->getRight());
	//prints out the content of the node
	cout << head->getContent() << " ";
}

//method to print out the binary expression tree with infix
void in(Node* head){
	//makes sure isn't null
	if(head==NULL){
		return;
	}
	//when operators are found, also print out parenthesis
	if(*head->getContent()=='+'||*head->getContent()=='-'||*head->getContent()=='*'||*head->getContent()=='/'||*head->getContent()=='^'){
		cout << "(" << " ";
	}
	//recursively go through and print
	in(head->getLeft());
	cout << head->getContent() << " ";
	in(head->getRight());
	//print out other parenthesis
	if(*head->getContent()=='+'||*head->getContent()=='-'||*head->getContent()=='*'||*head->getContent()=='/'||*head->getContent()=='^'){
		cout << ")" << " ";
	}
}
//method to print out the binary expression tree with prefix
void pre(Node* head){
	//makes sure isn't null
	if(head==NULL){
		return;
	}
	//prints and recusively goes through the tree
	cout << head->getContent() << " ";
	pre(head->getLeft());
	pre(head->getRight());
}
//method for popping out the top Node* in the stack
char* pop(Node*& stack){
	//makes temp char* for the content and then returns
	char* out = stack->getContent();
	if(stack->getRight()!=NULL){
		stack = stack->getRight();
	}else
	{
		stack->setContent(NULL);
	}
	return out;
}

//method for pushing in a Node* in the stack
void push(Node*& stack, char* input){
	//make new head and point to old head
	if(stack->getContent()!=NULL){
		Node* newNode = new Node();
		newNode->setContent(input);
		newNode->setRight(stack);
		stack = newNode;
	}else{
		//when there's nothing then just set the content 
		stack->setContent(input);
	}
}
//method to show the top Node* in the stack
char* peak(Node*& stack){
	//returns the top Node* if there is one
	if(stack->getContent()!=NULL){
		return stack->getContent();
	}else{
		return NULL;
	}
}
int main(){
    while(1){
	    //creates the stack and maps for associativity and precedence
	    Node* stack = new Node();
	map<char, int> oper;
        oper['-'] = 2;
        oper['+'] = 2;
        oper['*'] = 3; 
        oper['/'] = 3;
        oper['^'] = 4;
        //oper['('] = 5;
        //oper[')'] = 5;

	map<char, int> assoc;
	assoc['^'] = 1;
	assoc['*'] = 0;
	assoc['/']=0;
	assoc['+']=0;
	assoc['-']=0;
	//gets input and then uses strtok to divide it into a vector
        char* input = new char[100];
        cout << "Enter an expression to be outputted as postfix (Insert spaces between each token):" << endl;
        cin.getline(input, 100);
        vector<char*> v;
	vector<char*> output;
        char* token=strtok(input, " ");
        while(token != NULL){
            v.push_back(token);
            token = strtok(NULL, " ");
        }
       	//iterate through vector
        for(vector<char*>::iterator i = v.begin(); i!= v.end(); advance(i, 1)){
		//follow shunting yard algorithm - if it is a digit, just push into output queue, if an operator, then put into stack. pop out of stack according to precedence and associativity. push into stack.
		if(isdigit(*(*i))){
			output.push_back(*i);		
            	}else if(*(*i)=='+'||*(*i)=='-'||*(*i)=='*'||*(*i)=='/'||*(*i)=='^'){
            		while(true)
			{
				
				if(stack->getContent()==NULL){		
					break;
				}else if(*peak(stack)!='('){
						
					if(oper[*(*i)]<oper[*peak(stack)]){
						output.push_back(pop(stack));
						
					}else if(oper[*(*i)]==oper[*peak(stack)]&&assoc[*peak(stack)]==0){
					
						output.push_back(pop(stack));
						
					}else{
						break;
					}
				
				}else{
					break;
				}
			
			}
			push(stack, *i);
            	}else if(*(*i)=='(')
		{
			
			push(stack, *i);
			//if its a right parenthesis then pop into output queue until left is foudn
		}else if(*(*i)==')'){
			//cout << "right parenthesis" << endl;
			while(*peak(stack)!='('){
				output.push_back(pop(stack));
			}
			pop(stack);
		}
        }
	while(true){
		//pops out the extra operators
		if(stack->getContent()==NULL){
			break;
		}else{
			output.push_back(pop(stack));
		}
	}
	//iterate through the output queue vector and print out the expression in postfix
	cout << "Postfix Expression:";
	for(vector<char*>::iterator it = output.begin(); it!=output.end(); advance(it, 1)){
		cout << *it << " ";
	}
	cout << "  " << endl;
        //create the stack for the binary expression tree
       // stack<Node*> binStack;
	vector<Node*> binStack;
    Node *binHead, *c1, *c2;
	while(1)
	{
		//iterate through the old postfix expression and create the tree
		for(vector<char*>::iterator ite = output.begin(); ite != output.end(); advance(ite, 1)){
			if(isdigit(*(*ite))){
				//add Node* to stack
				Node* tempNode = new Node();
				tempNode->setContent(*ite);
				//binStack.push(tempNode); 	
                binStack.push_back(tempNode);	
            }else if(*(*ite)=='+'||*(*ite)=='-'||*(*ite)=='*'||*(*ite)=='/'||*(*ite)=='^'){
				//create a new Node* and connect left and right to the 2nd and most recent Node*'s that were in the stack
				binHead = new Node();
				binHead->setContent(*ite);

				c1 = binStack.back();
				binStack.pop_back();
				c2 = binStack.back();
				binStack.pop_back();

				binHead->setRight(c1);
				binHead->setLeft(c2);
				//add back into stack
				binStack.push_back(binHead);
			}	
		}
		//at the end, the only thing in the stack is the head to the expression tree
		binHead = binStack.back();
		binStack.pop_back();
		//get input to output as pre, in, or postfix
            	char* input2 = new char[5];
            	cout << "Convert to Prefix, Infix, Postfix, or Exit?" << endl << "(PRE, IN, POST, EXIT)" << endl;
           	 cin.getline(input2, 5);
          	  if(strcmp(input2, "PRE")==0){
			pre(binHead);			
            	}else if(strcmp(input2, "IN")==0){
                	in(binHead);
            	}else if(strcmp(input2, "POST")==0){
                	post(binHead);
            	}else if(strcmp(input2, "EXIT")==0){
            	   	 break;
           	 }
        }   
    }
}

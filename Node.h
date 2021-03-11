/*
Filename:Node.h
===============================
Course: SENG1120
Student number: c3309266
Coded by: Akshata Dhuraji 
===============================
Description: This program defines all the functions of Node class
Precondition:  Node.h needs to be present with all the function declaration
Postcondition: Nodes are created which can further be used within linkedlist

Private variables: as per the assignment specification, str_type is defined as string typedef, this str_type is further used to define 'data' variable
next and prev pointers are used to keep track of nodes in doubly linkedlist

Public members:
Node();
Description: Default constructor Node() is defined to initialise member variables.
Precondition: 	Members are declared
Postcondition:	Members are initialsed

Node(const str_type& sdata) 
Description: 	 Copy constructor 
Precondition:    none
Postcondition:   A new instance of Node is created and its instance data initialsed

~Node()
Description:	DESTRUCTOR
Precondition: 	Node is created and initialised
Postcondition:	Memory space occupied by node is freed upper_bound

void set_Node(const str_type& new_data);
Description:	Set the datavalue in the Node
Precondition:   data type is initialised
Postcondition:  sets the value of data variable with the new_data passed as argument in the function 

void set_next(Node* next_link);
void set_prev(Node* prev_link);
Description: 	 Set the next and prev pointers
Precondition:    next and prev pointers are initialised
Postcondition:   sets the value of next and prev pointer based on the value passed as argument  

str_type get_data();
Description:	returns the data stored in the node
Precondition :  constructor is defined to initialise the value
Postcondition:  returns value of str_type stored in the node

const Node* get_prev() const;//A CONSTANT VERSION THAT RETURNS A CONST NODE* 
Node* get_prev();//A CONSTANT VERSION THAT RETURNS AN ORDINARY NODE POINTER
const Node* get_next() const;//A CONSTANT VERSION THAT RETURNS A CONST NODE* 
Node* get_next();//A CONSTANT VERSION THAT RETURNS AN ORDINARY NODE POINTER
Description:	 returns the prev and next point position
Precondition:    next and prev pointers are declared and initialised
Postcondition:   returns the value of next and prev pointer  

*/

// macroguards
#ifndef NODE_H
#define NODE_H

#include <string>								//PROVIDE STRING

using namespace std;

class Node
{
	private: 									//MEMBERS ACCESSIBLE ONLY WITHIN FUNCTIONS OF NODE CLASS
		typedef string str_type;
		str_type data;
		Node* next;
		Node* prev;
	
	public: 									//MEMBERS THAT ARE EXTERNALLY VISIBLE 
		//CONSTRUCTOR
		Node();
		Node(const str_type& sdata);			//CONSTRUCTOR
		~Node();								//DESTRUCTOR
		
		
		void set_Node(const str_type& new_data);//MEMBER FUNCTION TO SET DATA
		str_type get_data();					//MEMBER FUNCTION TO RETURN DATA
		
		void set_next(Node* next_link); 		// MUTATOR METHOD (setter)
		void set_prev(Node* prev_link);			// MUTATOR METHOD (setter)
					
		// ACCESSOR(getters)
		const Node* get_prev() const;			//A CONSTANT VERSION THAT RETURNS A CONST NODE* 
		Node* get_prev();						//A CONSTANT VERSION THAT RETURNS AN ORDINARY NODE POINTER

		const Node* get_next() const;			//A CONSTANT VERSION THAT RETURNS A CONST NODE* 
		Node* get_next();						//A CONSTANT VERSION THAT RETURNS AN ORDINARY NODE POINTER
};
#endif //NODE.H
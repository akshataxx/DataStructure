/*
Filename:Node.cpp
===============================
Course: SENG1120
Student number: c3309266
Coded by: Akshata Dhuraji 
===============================
*/

#include <cstdlib>														//PROVIDE NULL
#include "Node.h"														//NODE CLASS HEADER FILE
using namespace std;


Node:: Node()															//DEFAULT CONSTRUCTOR
{
	next = NULL; 														// SET POINTER next to NULL
	prev = NULL;														// SET POINTER prev to NULL
}	
Node::Node(const str_type& sdata)										// CONSTRUCTOR TO SET 'data' TO THE MEMORY ADDRESS OF 'sdata'
{
	data= sdata;	
	next = NULL; 														// SET POINTER next to NULL
	prev = NULL; 														// SET POINTER prev to NULL
} 
Node::~Node()															//DESTRUCTOR FREES UP MEMORY SPACE USED BY VARIABLES
{next=NULL; prev=NULL; delete next; delete prev;}
// set_Node REQUIRES THE CONST VALUETYPE MEMORY ADDRESS OF THE ARGUMENT 
// SO THAT THE NEWLY SET 'data' WILL BE PRESISTENT BEYOND ITS CALL 
void Node::set_Node(const str_type& new_data)	{data=new_data;}

// MUTATORS
void Node::set_next(Node* next_link) 			{next=next_link;} 		//SET next POINTER
void Node::set_prev(Node* prev_link) 			{prev=prev_link;} 		//SET previous POINTER
Node::str_type Node::get_data() 				{return data;} 			//RETURNS data STORED IN THE NODE

// ACCESSORS
// 2 GETTERS METHODS ARE REQUIRED FOR A LINKED LIST (Const version and non const version)
// COMPILER WILL FIND OUT WHICH ONE IS BEST TO USE 
const Node* Node::get_prev() const 				{return prev;} 			// RETURNS previous POINTER
Node* Node::get_prev() 							{return prev;}
const Node* Node::get_next() const 				{return next;}			//RETURNS next POINTER
Node* Node::get_next() 							{return next;}
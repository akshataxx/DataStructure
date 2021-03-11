/*
Filename:BTNode.h
===============================
Course: SENG1120
Student number: c3309266
Coded by: Akshata Dhuraji 
===============================

Description:  BTNode class create nodes to facilitate passing of names into BTree. This class is used by BSTree to hold the data in nodes
Precondition: main class is defined and passes the values to be stored in BTNode
Postcondition: creation of node 

Private member 		: 
BTN data 			- A variable name data is created of template type BTN
left, right 		- Pointer of type BTN is created and used via mutator function by BSTree class. left is used to store values less than  parent and right is used to store values greater than parent

Public members 		:
BTNode() 			: default constructor to initialise the values
BTNode(BTN data_) 	: constructor uses fuction overloading to pass value of data passed by BSTree class into data
					Precondition - default constructor exist postcondition - value of data is initialised to a value passed  by user classes i.e.  BSTree
					
set_data 			: As data is private member, BSTree uses this function to access data value.Precondition - variable is declared as private member

set_left			: As left is private member, BSTree uses this function to access left pointer. Precondition - pointer is declared as private member
set_right 			: As right is private member, BSTree uses this function to access right pointer. Precondition - pointer is declared as private member

get_data			: As data is private member, BSTree uses this function to access data value.Precondition - variable is declared as private member. Postcondition returns value in data variable

get_left 			: As left is private member, BSTree uses this function to access left pointer. Precondition - pointer is declared as private member.Postcondition returns value in ptr variable
get_right			: As right is private member,BSTree uses this function to access right pointer. Precondition - pointer is declared as private member.Postcondition returns value in ptr variable

macroguards are used to ensure the code is not duplicated
*/
#ifndef BTNODE
#define BTNODE

#include <cstdlib>
using namespace std;

template <class BTN>
class BTNode
{
public:
// Constructors
    BTNode()																				{data = BTN(); left = NULL; right = NULL; }
	BTNode(BTN& data_)																		{data = data_;}
   
// Destructor
	~BTNode()																				{delete left; delete right;}
	
// Mutators
    void set_data(const BTN& data_)															{data = data_;}
    void set_left(BTNode<BTN>* left_)														{left = left_;}
    void set_right(BTNode<BTN>* right_)														{right = right_;}
	
// Query
    BTN get_data() const																	{return data;}
    BTNode<BTN>* get_right()const															{return right;}
    BTNode<BTN>* get_left()const															{return left;}  
	
private:
    BTN data;
    BTNode* left;
    BTNode* right;   
};

#endif //BTNODE.H
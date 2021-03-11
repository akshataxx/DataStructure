/*
Filename:BSTree.h
===============================
Course: SENG1120
Student number: c3309266
Coded by: Akshata Dhuraji 
===============================

Description		: BSTree is a template class , it allows creation of BTree data structure to store the Node data. The function definition are defined in the template class
Precondition	: BTNode class is defined so that the function call from this program can work and 
Postcondition	: creation of BTree so that operations listed in TreeHashTableDemo can be carried out

Private members :
root pointer is created to navigate within BTree, it refers to root node

Private functions : 
BTNode<valuetype>* create(valuetype ) 	- this is a helper function called from add node function to store data value (names passed from main program) in root node
								Precondition - add function and root nodes exist 	
								Postcondition - returns root node  

valuetype findSmallest() 				- This is a helper function for remove function. Finds the smallest node in the left branch
								Precondition - Parent function remove exist in the BTree
								Post condition- returns data of the smallest node value								

valuetype findSmallestPriv(BTNode<valuetype>*) - this is a helper function called from findsmallest function to find and return the value of smallest node 
								Precondition - findsmallest public function is defined and btree exist
								Postcondition - returns value in the smallest node
								
void removePriv(valuetype data, BTNode<valuetype>*)
void removeMatch(BTNode<valuetype>* parent, BTNode<valuetype>* match, bool left)		
void removeRootMatch() 			- these 3 are helper functions for remove function declared in the public section.Based on the position of matching node existance different actions are taken by each function.		
								Precondition - Remove function is defined 
								Post condition - helps remove function to traverse to the matching node in the BTree and removes it. 

ostream& printInOrder(BTNode<valuetype>*) - this is a helper function for overloaded operator function << gets called from print function and helps to traverse to the node to be printed
								Precondition - BTree exist with values
								Postcondition - returns values stored in BTree as object of Ostream class
						
Public functions :		
void add(valuetype thing) 				- this function is used to add data to respective node of the BTree
								Precondition - BTree exist
								Postcondition - Node is added to the tree based on its value
void insert(BTNode<valuetype>* node, valuetype ) - this is a helper function used to insert data , its called from add function	
								Precondition - BTree exist with atleast one node containing data
								Postcondition - Data is inserted into the BTree in the respective position

void remove(valuetype ) 				- This function is used to remove data, it uses child function to locate the matching data and delete the apprpirate node withoout loosing the address of the node
								Precondition - BTree exist and holds data
								Postcondition- removal of matching data from the Btree
ostream& print(ostream& out)	- This is a helper function for overloaded operator function <<
								Precondition - BTree exist with values
								Postcondition - returns values stored in BTree as object of Ostream class
macroguards
*/
#ifndef BSTREE
#define BSTREE

#include <cstdlib>
#include <iostream>
#include "BTNode.h"

using namespace std;

template <class valuetype>
class BSTree
{
public:
// Constructors
    BSTree();							
	BSTree(const valuetype&);
	
// Destructor
	~BSTree();
	
	void add(const valuetype&);
	void insert(BTNode<valuetype>* node, const valuetype&);
	void remove(const valuetype&);
	ostream& print(ostream& out);
	void destroy(BTNode<valuetype>* ptr);
		
	
private:
   	BTNode<valuetype>* root;
	BTNode<valuetype>* create(const valuetype&);
	valuetype findSmallest();
	valuetype findSmallestPriv(BTNode<valuetype>*);
	void removePriv(const valuetype& data, BTNode<valuetype>*);
	void removeMatch(BTNode<valuetype>* parent, BTNode<valuetype>* match, bool left);
	void removeRootMatch();
	ostream& printInOrder(BTNode<valuetype>*);
};

template <class valuetype>
ostream& operator << ( ostream& , BSTree<valuetype>&);

#include "BSTree.hpp"
#endif
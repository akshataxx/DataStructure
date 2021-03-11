/*
Filename:BSTree.template
===============================
Course: SENG1120
Student number: c3309266
Coded by: Akshata Dhuraji 
===============================
*/
template <class valuetype> 
BSTree<valuetype>::BSTree()	// Default Constructor
{
	root = NULL; 
}

template <class valuetype> 
BSTree<valuetype>::BSTree(const valuetype& name)	// Constructor to set the data value in root node
{root = new BTNode<valuetype>(name);}

template <class valuetype> 
BSTree<valuetype>::~BSTree()
{
	destroy(root);
	delete root;
}

template <class valuetype> 
void BSTree<valuetype>::destroy(BTNode<valuetype>* ptr)
{
	if (ptr != NULL)
	{
		if(ptr->get_left() != NULL)
			destroy(ptr->get_left());
		else if(ptr->get_right() != NULL)
			destroy(ptr->get_right());
		ptr = NULL;
		delete ptr;
	}
}

template <class valuetype> 
BTNode<valuetype>* BSTree<valuetype>::create(const valuetype& name)	// helper function called from add function
{
	BTNode<valuetype>* node = new BTNode<valuetype>;
	node->set_data(name);
	node->set_left(NULL);
	node->set_right(NULL);
	return node;
}

template <class valuetype> 	
void BSTree<valuetype>::add(const valuetype& name)	// function to add value in the node
{
	if (root == NULL) // If root is NULL i.e. Btree doesn't have any data value , then call create function
		root=create(name); 
	else				// else if root is not null i.e. Btree has data, then call insert function to check the value of data and insert at the right position
		{insert(root, name);}
}	

template <class valuetype> 	
void BSTree<valuetype>::insert(BTNode<valuetype>* node,const valuetype& name)		//helper function called from add function
{	
	if (name < node->get_data())	// If the data being inserted is less than the one in the node then check the left branch of the BTree to insert the data
	{
		if (node->get_left() != NULL )
			{ insert(node->get_left(), name);}
		else
			{ node->set_left(create(name)); }
	}
	else if (name > node->get_data())// If the data being inserted is greater than the one in the node then check the right branch of the BTree to insert the data
	{
		if(node->get_right() != NULL)
			insert(node->get_right(), name);
		else 
			node->set_right(create(name));
	}
	else 
	{
		node->set_data(name);
		return;
	}
	node=NULL;
}
	
template <class valuetype> 		
void  BSTree<valuetype>::remove(const valuetype& name)	// Function to remove data
{ removePriv(name,root); }

template <class valuetype> 
void BSTree<valuetype>::removePriv(const valuetype& data, BTNode<valuetype>* parent)
{
	if ( root != NULL)
	{
		if (root->get_data() == data)	//case= root data matches the data which we want to delete
		{
			removeRootMatch(); 
		}
		else
		{
			if(data < parent->get_data() && parent->get_left() != NULL)  // if the data value is less than parent data then check in the left branch of the tree
			{
				parent->get_left()->get_data() ==  data ?			//check in left node recursively for the data match, if match is found call removematch function	
				removeMatch( parent, parent->get_left(), true):
				removePriv(data, parent->get_left());
			}
			else if (data > parent->get_data() && parent->get_right() != NULL)// if the data value is greater than parent data then check in the right branch of the tree
			{
				parent->get_right()->get_data() ==  data ?
				removeMatch( parent, parent->get_right(), false):
				removePriv(data, parent->get_right());
			}
			//else
				//cout << " The data "  << data << " was not found in the tree"; 
		}
	}
	else
		cout<< " The tree is empty" ;
}

template <class valuetype> 
void BSTree<valuetype>::removeMatch(BTNode<valuetype>* parent, BTNode<valuetype>* match, bool left)
{
	if (root != NULL)
	{
		BTNode<valuetype>* delPtr;
		valuetype matchData= match->get_data();
		valuetype smallestInRight;
		
		if(match->get_left()== NULL && match->get_right() == NULL) // Case where parent has 0 children
		{
			delPtr = match;																
			left == true ? parent->set_left(NULL): parent->set_right(NULL);//if statement to check if left is true then set left and right node as null
			delete delPtr;
		}
		else if (match->get_left()== NULL && match->get_right() != NULL) // Case where parent has 1 child , right branch holds the child and left branch is null
		{
			left == true ? parent->set_left(match->get_right()): parent->set_right(match->get_right()); //if statement to check if left is true then check the right node 
			match->set_right(NULL);
			delPtr = match;
			delete delPtr;
		}
		else if (match->get_left()!= NULL && match->get_right() == NULL) // Case where parent has 1 child, left branch hold the child data and right branch in 
		{
			left == true ? parent->set_left(match->get_left()): parent->set_right(match->get_left());
			match->set_left(NULL);
			delPtr = match;
			delete delPtr;
		}
		else // Case where parent has 2 Children
		{
			smallestInRight = findSmallestPriv(match->get_right());
			removePriv(smallestInRight, match);
			match->set_data(smallestInRight);
			delPtr=NULL;
		}
	}
	else
		cout<< "\n Can not remove match. The tree is empty ";
}

template <class valuetype> 
void BSTree<valuetype>::removeRootMatch()
{
	if(root != NULL)
	{
		BTNode<valuetype>* delPtr = root;
		valuetype rootData= root->get_data();
		valuetype smallestInRight;
		if ( root->get_left()== NULL && root->get_right()== NULL) //0 child case where root doesn't have any children
		{
			root = NULL;
			//delete delPtr;
		}
		else if ( root->get_left()==NULL && root->get_right() != NULL) //1 child case where there's no left child but right child exist
		{
			root = root->get_right();
			delPtr->set_right(NULL);
			//delete delPtr;
		}
		else if ( root->get_left() !=NULL && root->get_right() == NULL) //case where there's no left child but right child exist
		{
			root = root->get_left();
			delPtr->set_left(NULL);
			//delete delPtr;
		}
		else // 2 child case
		{
			smallestInRight = findSmallestPriv(root->get_right());
			removePriv( smallestInRight, root);
			root->set_data(smallestInRight);
			delPtr=NULL;
		}
		delete delPtr;
	}
	else
	{
		cout << "\n The Tree is empty";
	}
}

template <class valuetype> 	
valuetype  BSTree<valuetype>:: findSmallest()
{
	return findSmallestPriv(root);
}

template <class valuetype> 	
valuetype  BSTree<valuetype>:: findSmallestPriv(BTNode<valuetype>* ptr)
{
	valuetype temp; 
	if (root == NULL)
	{
		cout << "\n The tree is empty " ;
		return temp;
	}
	else
	{
			if (ptr->get_left() != NULL)
			{ return findSmallestPriv(ptr->get_left());}
			else
			{ return ptr->get_data();}
	}
}


template <class valuetype>
ostream& BSTree<valuetype>::printInOrder(BTNode<valuetype>* ptr)
{
	ostream& out = cout;
	if (ptr != NULL)
	{
		if(ptr->get_left() != NULL)
			printInOrder(ptr->get_left());
		out<< " "<< ptr->get_data();
		if (ptr->get_right() !=NULL)
			printInOrder(ptr->get_right());
	}
	else 
		cout<< "\n no data";
	ptr=NULL;
	return out;
}

template <class valuetype> 	
ostream& BSTree<valuetype>::print(ostream& out)
{ 
	printInOrder(root);
	return out;
}

template <class valuetype>
ostream& operator << (ostream& out, BSTree<valuetype>& tree)
{ return tree.print(out);}


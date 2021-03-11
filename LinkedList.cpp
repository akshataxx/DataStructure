/*
Filename:LinkedList.cpp
===============================
Course: SENG1120
Student number: c3309266
Coded by: Akshata Dhuraji 
===============================
*/

#include <cstdlib>
#include <string.h>
#include <iostream>
#include<bits/stdc++.h> 
#include "LinkedList.h" 								//header file

using namespace std;

LinkedList::LinkedList()								//default constructor
{
	head=NULL;
	tail=NULL;
	current=NULL;
	list_length=0;
}

LinkedList::LinkedList(str_type& strdata)				//Copy constructor to store data
{
	head = new Node(strdata);
	tail= head;
	current=tail;
	list_length=1;
}

LinkedList::~LinkedList()								//destructor for linked list
{
	while(head !=NULL)
		removeFromHead();
	tail=NULL;
}

void LinkedList::add(const str_type& scdata) 			//add a node at the start of linkedlist
{
	str_type word;										//variable word declared to store the string type data passed from main function
	stringstream ss(scdata);							//Stringstream used to read the words in the string 
	while (ss>>word)									//Loop continues untill the end of the string
	{
		current=new Node(word);							//create a node with the data to be added to the linkedlist
		current->set_next(NULL);						
		if(list_length==0)								//insert node at head
		{
			head=current;					
			tail=current;
			list_length=1;
		}
		else 											//if the head node already exist then add data to tail of the linkedlist
		{
			tail->set_next(current);
			current->set_prev(tail);
			tail=current;
			list_length++;								//increment the  listlength
		}
		current=NULL;
	}
	
}	

void LinkedList::removeFromHead()
{
	if(list_length==0)									//incase of empty list,don't do anything
		return;	
	else if(list_length==1)								//remove first node if only 1 node is in list
	{
		head=NULL;
		tail=NULL;
		current=NULL;
		list_length--;									//decrement the listlength
		return;
	}
	else
	{
		current=head;									//make a temp head pointer and set it as current head pointer
		head=current->get_next();						//Reset the head for the list
		current=NULL;
		list_length--;									//decrement the list
	}
}

LinkedList& LinkedList::operator +=(LinkedList& l)		//concatenate list1 with list2 data
{
	l.current=l.head;									//l points to list2
	while(l.current!=NULL)								//traverse the list2 untill the last node
	{
		current= new Node(l.current->get_data());		//create new node in list1 to add the list2 data or node to list1
		tail->set_next(current);						//add the newly created node to tail of list1
		current->set_prev(tail);				
		tail=current;
		list_length++;									//increment the list length
		l.current=l.current->get_next();				//traverse the list2 to next node
	}
	current=NULL;delete current;						//assign NULL to current pointer and delete the pointer
    return *this; 										//return LinkedList1
	
}

ostream& LinkedList::print(ostream& out) const			//supporting function to print the values in the linkedlist
{
	Node* current= new Node();
	current = head;
	while (current!= NULL)								//traverse the linkedlist untill the last node
	{
		out << " "<< current->get_data();				//print the data in the current node
		current=current->get_next();
	}
	current=NULL;
	delete current;
	return out;
}
		
std::ostream& operator<<(std::ostream& stream, const LinkedList& l)
{
	return l.print(stream);								//calls the supporting print function
}

void LinkedList::remove(const str_type n)
{
	int count=0; 										// int variable to count the number of words in the string passed by the main function
	int i=count;
	str_type w[3]; 										//string type variable used to store the words of the string passed by the main function
	stringstream ss(n); 								//stringstream variable to store the string and extract the words in the string
	while(ss>>w[count]) 								// run this loop untill the words exist in the string passed by the main program
	{	 
		count++;
	}
	if(count==1)										//If there's a single word in the string run this code of the remove function
	{
		current=head;
		while (current != NULL) 						//traverse untill the last node of the linkedlist
		{
			if (w[i]==current->get_data())
			{
				if(current==head) 						//If the node to be removed is head node, then change the value of head
					head=current->get_next();
				if(current->get_next() != NULL) 		//If the node to be removed is not the last node
					current->get_next()->set_prev(current->get_prev());
				if(current->get_prev()!= NULL) 			//If the node to be removed is not the first node
					current->get_prev()->set_next(current->get_next()); 
			}
			current = current->get_next();				//traverse the linkedlist
		}
	}
	else if(count>1)									// If there's more than 1 word in the string then run this code of the remove function
	{
		current=head;
		while(current->get_next()->get_next() !=NULL)	//Traverse the linked list untill the 3rd last node of the linkedlist
		{
			i=0;
			//If statement to compare the words in the string with the data in the Node of linkedlist
			if(w[i]==current->get_data() && w[++i]==current->get_next()->get_data() && w[++i]==current->get_next()->get_next()->get_data())
			{ 
				current->get_prev()->set_next(current->get_next()->get_next()->get_next()); //removes the node with matching data
			}
			current = current->get_next();				//Traverse the linkedlist
		}		
	}
	current=NULL;delete current;
}

int LinkedList::count(const str_type s)
{
	int count=0;
	current=head;
	while (current != NULL)							//Traverse the linkedlist untill the last node
	{
		if (s==current->get_data())					//checks if the string s matches the data in the node
			count++;								//counts the number of times string s is found in the linked list
		current = current->get_next();				//Traverse the linkedlist
	}
	current=NULL;delete current;
	return count;									//returns value in count variable
}
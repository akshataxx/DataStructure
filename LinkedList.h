/*
Filename:LinkedList.h
===============================
Course: SENG1120
Student number: c3309266
Coded by: Akshata Dhuraji 
===============================
Description:Class representing a LinkedList to operate on data provided in Linkedlist demo, this file holds the function declarations
precondition: Node class is defined
postcondition: offers ability to add and manipulate data as per the assignment

Private variables
1) Node pointers created to navigate the linkedlist
2) Variable to track the linkedlist length
3) String typedef declared as the requirement in the assignment

Public members]
LinkedList();					
LinkedList(str_type& strdata);
Constructor description: Default constructor created to initialise the node pointers and linkedlist length variable. 
						 Copy constructor created to assign value to data variable
Precondition: Node class is defined
Postcondition: Members are initialised

~LinkedList()
Description: Destructor written to free up memory space taken up by the variables
Precondition: Node class exist and LinkedList member variables are defined and initialised
Postcondition: Memory space occupied by variables is freed up

void removeFromHead();
Description: Supporting function called from destructor
Precondition: Destructor is defined and called
Postcondition: frees up memory space occupied by variables, thus supporting desctuctor in its purpose

void add(const str_type&  scdata);
Description: Add new node to tail of linked list, function checks if the linked list already exist, if it doesn't exist creates head node. If it exist function adds node to tail.
Precondition: LinkedList is defined and initialised
Postcondition: Node is added to the tail of the linked list

ostream& print(ostream&) const;
Description: Supporting function to print the linkedlist,gets called from operator overloading function << 
Precondition: LinkedList exist and dataset has been added to it
Postcondition: value stored in linked list is printed

LinkedList& operator += (LinkedList& l);
Description: Function to concatenate 2 linkedlist using operator overloading +=
Precondition: 2 linkedlist are defined, initialised and hold valid data
Postcondition: data in list2 is added to list1

void remove(const str_type); 
Description: Function to search the string data passed by main program and remove it from the LinkedList. The function counts the number of string
passed by main program, if 1 string needs to be removed then first part of code written under if condition works, else second part of code written 
under else condition works to remove a set of strings in a contegious block from linkedlist
Precondition: linkedlist exist and holds data
Postcondition: removes node from linkedlist which matches the char array

int count(const str_type);
Description: Counts the number of occurance of string variable passed by main program
Precondition: LinkedList exist and hold data
Postcondition: returns the count of the time string is found in the linkedlist

std::ostream& operator<<(std::ostream& stream,const LinkedList& l);
Description: Operator overloading function to print the linkedlist, uses supporting function print, to print the values in the private variables
Precondition: Linked list exist and holds data. Print function exist with ability to print the linkedlist
Postcondition: Data stored in LinkedList is printed
*/

//macroguards
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstdlib> 
#include <string.h>
#include<bits/stdc++.h> 
#include "Node.h"   
class LinkedList
{
	private: 									//private variables
		Node* head;
		Node* tail;
		Node* current;
		std::size_t list_length;
		typedef string str_type;
				
	public:										//public variables
		LinkedList();							//Default Constructor
		LinkedList(str_type& strdata);			//Copy Constructor
		~LinkedList();							//Destructor
		
		
		void add(const str_type&  scdata); 		//add value passed by main program to tail of the linkedlist
		void removeFromHead();					//supporting function called from destructor
		ostream& print(ostream&) const;			//supporting function called from operator<< function to print data stored in linkedlist
		LinkedList& operator += (LinkedList& l);// Overloads the operator '+='
		void remove(const str_type); 			//removes the node where data = the const char array passed in the function
		int count(const str_type);				// search the string passed by main program and returns the count of it
};
std::ostream& operator<<(std::ostream& stream,const LinkedList& l);//function to print linkedlist, uses supporting function print
#endif // LINKEDLIST.H
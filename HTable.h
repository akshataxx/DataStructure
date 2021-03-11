/*
Filename:HTable.h
===============================
Course: SENG1120
Student number: c3309266
Coded by: Akshata Dhuraji 
===============================

Description							: HTable class create Hash Tables, inserts , removes  , prints data  based on the callout from TreeHashTableDemo.cpp
Precondition						: TreeHashTableDemo class exist
Postcondition						: creation of HashTable so that operations listed in TreeHashTableDemo can be carried out

Private variables:
TABLE_SIZE 							: As mentioned in the excercise a hashtable is created with size 150

hashTable[TABLE_SIZE]				: HashTable is created with standard table size of 150

Public functions:
HTable()							: default constructor user to initialise the variables
int hashfun(const value_type& value):Hash function as provided in the exercise
void add(value_type)				:Add function is used to add data to hashtable
									Precondition - BTNode and HashTable exist with underlying mechanical part class definition
									Postcondition - data is added based on the index value provided by hasfunc function
							
ostream& print(ostream& out)		: Helper function to return  data for those indexs which holds value as object of Ostream
									Precondition - Hashtable exist with data
									Postcondition - Hashtable data is returned only for those indexs which holds value
void remove(value_type)				: Function to search and remove matching data
									Precondition - Hashtable exist with data
									Postcondition - matching data is removed

macroguards */
#ifndef HTABLE
#define HTABLE

#include <iostream>
#include <cstdlib>
using namespace std;

template <class value_type>
class HTable
{
public:
// Constructors
	HTable();

// Destructors
	~HTable();
	
// Functions
	
	void add(const value_type&);
	ostream& print(ostream& out);
	void remove(const value_type&);
	
private:
	static const int TABLE_SIZE=150;
	value_type hashTable[TABLE_SIZE];
	int hashfun(const value_type&);
};

template <class value_type>
ostream& operator << (ostream& , const HTable<value_type>&);

#include "HTable.hpp"
#endif //HTABLE
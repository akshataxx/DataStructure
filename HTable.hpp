template <class value_type> 
HTable<value_type>::HTable()	//Constructor
{ 
	for (int i=0;i<TABLE_SIZE;i++)
		hashTable[i]="";
}

template <class value_type> 
HTable<value_type>::~HTable()
{	
	for (int i=0;i<TABLE_SIZE;i++)
		hashTable[i]="";
}

template <class value_type>
int HTable<value_type>::hashfun(const value_type& value)	// hash function
{
	int addresult = 0;
	int index = value.length();
	for (int i=0; i<index; i++)
	{
		addresult = addresult+(int)value[i];
	}
	return addresult % TABLE_SIZE;
}

template <class value_type> 
void HTable<value_type>::add(const value_type& value)		//addition of data to Hashtable
{
	// get the hash index of value
	int index = hashfun(value);
	while(hashTable[index] != "")
            index = (index + 1) % TABLE_SIZE;
    hashTable[index] = value;
}

template <class value_type> 
void HTable<value_type>::remove(const value_type& value)
{ 
	// get the hash index of value 
	int index = hashfun(value); 
  
	while(hashTable[index] != value and hashTable[index] != "")
            index = (index + 1) % TABLE_SIZE;
        //Check if the element is present in the hash table
        if(hashTable[index] == value)
			hashTable[index]="";
}
	
template <class value_type> 
ostream& HTable<value_type>::print(ostream& out)	//helper function to print hash table index's where value is present
{

	for(int index=0;index < TABLE_SIZE;index++)
	{
		if (hashTable[index]!="")
			out << " "<< hashTable[index];
	}
	return out;
}

template <class value_type>
ostream& operator << (ostream& out, HTable<value_type>& htable)	//operator << overloading to print the hashtable contents 
{
	return htable.print(out);
}
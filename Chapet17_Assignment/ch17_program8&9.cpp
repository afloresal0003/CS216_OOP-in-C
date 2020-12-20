#include <iostream>
using namespace std;

struct node
{
	double data;
	node* next;
};


class LinkList
{
private:
	node* list;
	int listSize;

public:
	LinkList();
	LinkList(LinkList&);
	~LinkList();
	void add(double);
	bool isMember(double);
	void print();
	void remove(double);
	void reverse();
	int search(double);
	int getSize();
	void insert(double, int);
	void remove(int);
	void sort();
};

// default constructor
LinkList::LinkList()
{
	list = NULL;
}
// copy constructor
LinkList::LinkList(LinkList& temp)
{
	// To properly have the the objs have their own instance of the list
	// We have to create a new memory in the head for each node we copy
	list = NULL;
	node* current = temp.list;
	
	node* tail = NULL;
	while (current)
	{
		node* newTemp = new node;
		newTemp->data = current->data;
		newTemp->next = NULL;

		if (list == NULL)
		{
			list = tail = newTemp;
		}
		else
		{
			tail->next = newTemp;
			tail = newTemp;
		}

		current = current->next;
	}
}
// destructor
LinkList::~LinkList()
{
	while (list)
	{
		node* temp = list;
		list = list->next;
		delete(temp);
	}
	list = NULL;
}
// add method insert a new node to the front
void LinkList::add(double value)
{
	node* temp = new node;
	temp->data = value;
	temp->next = NULL;

	if (list == NULL)
	{
		list = temp;
	}
	else
	{
		temp->next = list;
		list = temp;
	}
}
// isMemeber method that works similar to a linear search
bool LinkList::isMember(double target)
{
	node*  current = list;

	// traversing the list to check all nodes if needed
	while (current)
	{
		if (current->data == target)
		{
			return true;
		}

		current = current->next;
	}

	return false;
}
// print method
void LinkList::print()
{
	node* current = list;
	cout << endl << "Printing the list" << endl;
	while (current)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
// delete method
void LinkList::remove(double target)
{
	if (list == NULL)
	{
		cout << "List is empty" << endl;
	}
	else if (list->next == NULL)
	{
		// condition when the list has only one node
		if (list->data == target)
		{
			node* temp = list;
			list = list->next;

			delete (temp);
		}
	}
	else
	{
		// in the case there are more than 1 node
		// check the next element from the current
		// if that node has the target value remove it and rearrange the links
		node* current = list;

		while (current->next)
		{
			// If the node ahead has the target value perform the remove operation
			if (current->next->data == target)
			{
				node* temp = current->next;

				// Fixing the links
				current->next = temp->next;

				// Deleting the memory address
				delete(temp);
				return;
			}

			current = current->next;
		}
	}

	cout << "Target value was not found in the list" << endl;
}
// reverse method which will change the links and where the head/start pointer will point to
void LinkList::reverse()
{
	node* current = list;
	node* prev = NULL;
	node* next = NULL;

	if (list == NULL)
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		// Loop that will implement the reversal
		/*
		we need to step through each node and rearrange the links
		we utilize a prev and next pointer to keep track of the node prior and node ahead
		for example when we reach a node
		the current->next will now need to point to the node prior to current
		current will need to be updated to the next node
		and prev will become the last current node in our list
		*/
		while (current->next != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		// once we get to the last node update its next pointer and update where the list will start
		current->next = prev;
		list = current;
	}
}
// search method
int LinkList::search(double target)
{
	if (list == NULL)
	{
		return -1;
	}

	int index = 0;

	node* current = list;

	while (current)
	{
		if (current->data == target)
		{
			return index;
		}

		current = current->next;
		index++;
	}

	return -1;
}
// getSize method will return the total number of nodes in the list
int LinkList::getSize()
{
	node* current = list;
	int index = 0;
	while (current)
	{
		current = current->next;
		index++;
	}

	return index;
}

// insert at position method based on range of 0 through n-1
void LinkList::insert(double value, int index)
{
	if (index < 0)
	{
		cout << "invalid position" << endl;
		return;
	}

	node* temp = new node;
	temp->data = value;
	temp->next = NULL;

	if (list == NULL)
	{
		list = temp;
	}
	else if (index == 0) // Inserting at the beginning
	{
		temp->next = list;
		list = temp;
	}
	else
	{
		node* current = list;

		// Inserting at the end
		if (index >= getSize())
		{
			while (current->next != NULL)
			{
				current = current->next;
			}

			current->next = temp;
		}
		else
		{
			// condition to insert at the specified location
			// We locate the node that is prior to the index
			// once found we insert the node and rearrange the links
			for (int x = 0; x < index - 1; x++)
			{
				current = current->next;
			}

			temp->next = current->next;
			current->next = temp;
		}
	}
}

// removal at a specific location based on the range of 0 through n-1
void LinkList::remove(int index)
{
	if (list == NULL)
	{
		cout << "list is already empty" << endl;
	}
	else if (index == 0) // Removing the first node
	{
		node* temp = list;
		list = list->next;

		delete(temp);
	}
	else
	{
		node* current = list;

		if (index < 0 || index >= getSize())
		{
			cout << "Invalid index value" << endl;
			return;
		}

		for (int x = 0; x < index - 1; x++)
		{
			current = current->next;
		}

		node* temp = current->next;

		current->next = temp->next;

		delete(temp);
	}
}

// sort method
// the approach will be similar to a bubble sort implementation
void LinkList::sort()
{

	if (list == NULL)
	{
		cout << "list is empty, nothing to sort" << endl;
		return;
	}

	bool swap;

	// Loop that will traverse list and if any neighboring nodes fall under our condition
	// The pointer/links will be rearrange
	// Every time a swap is done the loop will repeat itself until the sort is complete
	do
	{
		swap = false;
		node* current = list;
		node* prev = NULL;

		while (current->next != NULL)
		{
			// Compare the nodes next to each other 
			// If condition is true rearrange the links
			if (current->data > current->next->data)
			{
				node* temp = current->next;
				
				current->next = temp->next;
				temp->next = current;

				if (prev == NULL)
				{
					list = temp; // update our head pointer
				}
				else
				{
					prev->next = temp;
				}
				
				swap = true;
			}

			prev = current;
			current = current->next;
		}

	} while (swap);
}


int main()
{
	// Our object
	LinkList test;

	// Adding values to the linked list corresponding to this object instance
	test.add(7);
	test.add(4);
	test.add(6);
	test.add(2);
	test.add(8);
	test.add(14);
	test.print();

	// Checking the isMember method
	cout << (test.isMember(3) ? "value found":"value not found") << endl;
	cout << (test.isMember(8) ? "value found" : "value not found") << endl;
	cout << (test.isMember(4) ? "value found" : "value not found") << endl;
	cout << (test.isMember(12) ? "value found" : "value not found") << endl;
	
	test.remove(4.0); // removing a value to check the isMember method again
	test.print();
	cout << (test.isMember(4) ? "value found" : "value not found") << endl;
	test.remove(23.0);

	// Adding more values to our list
	test.add(35);
	test.add(29);
	test.add(43);
	test.add(3);
	test.print();
	test.remove(8.0);
	test.print();

	// Now having another object that should have its own instance of the link list
	LinkList test2(test);
	cout << endl << "Checking the copy construct";
	test2.print(); // print to make sure the copy construct was implemented correctly
	
	// Adding values but only to the second object we created
	// Meaning this should not impact the linked list from our original object
	test2.add(85);
	test2.add(102);
	test2.add(28);

	// Printing the linked list from our first object and checking that no new nodes were added
	test.print();
	cout << (test.isMember(85) ? "value found" : "value not found") << endl;
	cout << (test.isMember(43) ? "value found" : "value not found") << endl;
	cout << (test.isMember(102) ? "value found" : "value not found") << endl;

	test2.print();
	cout << (test2.isMember(102) ? "value found" : "value not found") << endl;
	cout << (test2.isMember(85) ? "value found" : "value not found") << endl;


	// Only reversing our original link list
	// Meaning the link list from our second object should remain the same
	cout << endl << endl << "Reversing the list";
	test.reverse(); 
	test.remove(43.0);
	test.print();
	test2.print();

	// Checking the search method on our second list
	cout << endl << endl << "Searching for index of values" << endl;
	cout << "List 2 Index of 3 is " << test2.search(3) << endl;
	cout << "List 2 Index of 102 is " << test2.search(102) << endl;
	cout << "List 2 Index of 85 is " << test2.search(85) << endl;
	cout << "List 2 Index of 14 is " << test2.search(14) << endl;
	cout << "List 2 Index of 345 is " << test2.search(345) << endl;
	cout << "List 2 Index of 7 is " << test2.search(7) << endl;
	
	// Checking the search method on our first list from the original object
	cout << "List 1 Index of 85 is " << test.search(85) << endl;
	cout << "List 1 Index of 43 is " << test.search(43) << endl;
	cout << "List 1 Index of 7 is " << test.search(7) << endl;


	// Inserting at a specific position
	cout << endl << endl << "Inserting and Deleting at a specific location" << endl;
	test.insert(34, 100);
	test.insert(100, 0);
	test.insert(68, -45); // Should not insert any value due to invalid index
	test.insert(19, 3);
	test.print();


	test2.insert(412, 11);
	test2.insert(157, 1);
	test2.insert(68, -1);
	test2.insert(69, 12);
	test2.print();

	// Deleting at a specific position
	test.remove(0); 
	test.remove(400); // Should not delete any value due to invalid index
	test.remove(5);
	test.remove(8); // Should not delete any value due to invalid index, since the index is equal to the total number of nodes and range is 0-(n-1)
	test.remove(-1); // Should not delete any value due to invalid index
	test.print();


	// Sorting method
	cout << endl << endl << "Sorting our linked list";
	test.sort();
	test.print();
	test2.print();
	test2.sort();
	test2.print();
	return 0;
}
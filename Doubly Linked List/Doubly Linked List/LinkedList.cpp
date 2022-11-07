
#include "LinkedList.h"

LinkedListNode::LinkedListNode(int VALUE,
	LinkedListNode* PREVIOUS,
	LinkedListNode* NEXT)
	:data(VALUE),
	previous(PREVIOUS),
	next(NEXT)
{
	//Nothing here
}

LinkedList::LinkedList() //Constructor that Initializes head pointer to null

	: head(nullptr)
{
	//Nothing Here
}

LinkedList::~LinkedList() //Destructor Function for removing elements.
{
	while (Empty() == false) //Makes sure there is an element to delete.
	{
		PopFront(); //removing the first element.
	}

}

bool LinkedList::Empty()//Checks to see if list is empty
{
	return head == nullptr;//If head has nothing in it return empty
}

void LinkedList::PushFront(int VALUE) //Pushfront Function
{
	if (Empty() == true) //No elements
	{
		head = new LinkedListNode(VALUE);
	}
	else //If list is not Empty
	{
		LinkedListNode* NewNode = new LinkedListNode(VALUE, nullptr, head);
		head->previous = NewNode;
		head = NewNode;
	}
}

void LinkedList::PopFront() //PopFront Function
{
	if (Empty() == false) //One or more elements
	{
		if (Size() == 1) // if there is only one element
		{
			delete head;
			head = nullptr;
		}
		else //2 or more elements
		{
			LinkedListNode* ToDelete = head;
			head->next->previous = nullptr; //remove 2nd element
			head = head->next;
			delete ToDelete;
		}
	}
}

int LinkedList::Size() const //Function that Counts how many elements are in the list
{
	int count = 0;
	LinkedListNode* current = head;
	while (current != nullptr)
	{
		++count;
		current = current->next;
	}
	return count;
}

int LinkedList::operator[](int INDEX)
{
	if ((INDEX < 0) || (INDEX >= Size()))
	{
		return std::numeric_limits<int>::min(); //returns lowest number limit if no value
	}
	LinkedListNode* current = head;
	for (int i = 0; i < INDEX; ++i) //For elements in the index do
	{
		current = current->next;//grabs the next element
	}
	return current->data; //Returns element if there was one.
}

int LinkedList::Find(int value) //Function to find a index value
{
	int index = 0;
	LinkedListNode* current = head;
	while (current != nullptr)
	{
		if (value == current->data)
		{
			return index;
		}
		++index;
		current = current->next;
	}
	return -1; //If cant find index value return -1
}

void LinkedList::Insert(int INDEX, int VALUE) //Function for inserting values
{
	if ((Empty() == true) || (INDEX <= 0)) //First element
	{
		PushFront(VALUE);
	}
	else if (INDEX >= Size()) //Last element  
	//You messed up here in the video and it was inserting an element into a index that has that many elements it just put it last, not at that index.
	//Needed to get rid of the -1  <-- Extra points ;)
	{
		LinkedListNode* prev = nullptr;
		LinkedListNode* current = head;
		while (current != nullptr)
		{
			prev = current;
			current = current->next;
		}
		//Current is pointing to the last node
		LinkedListNode* newNode = new LinkedListNode(VALUE, prev);
		//std::cout << "Current: " << current->data << std::endl;
		prev->next = newNode;
	}
	else if (INDEX > 0) //Anything in between
	{
		LinkedListNode* current = head;
		for (int i = 0; i < INDEX; ++i)
		{
			current = current->next;
		}
		//Current is pointing to the node
		LinkedListNode* newNode = new LinkedListNode(VALUE, current->previous, current);
		current->previous->next = newNode; //pointing to new node
		current->previous = newNode;
	}
}

void LinkedList::Erase(int INDEX)
{
	if ((INDEX <= 0) || (Size() <= 1)) //first element
	{
		PopFront();
	}
	else if (INDEX >= Size() -1)
	{
		//Has to be Previous element
		LinkedListNode* prev = nullptr;
		LinkedListNode* current = head;
		while (current != nullptr)
		{
			prev = current;
			current = current->next;
		}
		//prev is pointing to the last node
		prev->previous->next = nullptr;
		delete prev;
	}
	else
	{
		LinkedListNode* current = head;
		for (int i = 0; i < INDEX; ++i)
		{
			current = current->next;
		}
		//Current is pointing to the node
		current->previous->next = current->next; //pointing to new node
		current->next->previous = current->previous;
		delete current;
	}
}

std::ostream& operator<<(std::ostream& ostr, const LinkedList& rhs)
{
	ostr << "LIST: ";
	LinkedListNode* current = rhs.head;

	while (current != nullptr)
	{
		ostr << current->data << " ";
		current = current->next;
	}

	ostr << " SIZE: " << rhs.Size() << std::endl;
	return ostr;
}

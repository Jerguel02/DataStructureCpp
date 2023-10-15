#include <iostream>
#include <stdint.h>



using namespace std;

struct Node
{
	int64_t data;
	Node* next;
	Node(int64_t init_dat)
	{
		cout<<"Node <"<<&data<<"> has been created!"<<endl;
		data = init_dat;
		next = NULL;	
	}
	~Node()
	{
		cout<<"Node <"<<&data<<"> has been deleted!"<<endl;
	}
};


struct LinkedList
{
	Node* head;
	Node* tail;
	uint32_t size;
	LinkedList()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}	
	~LinkedList()
	{
		cout<<"List has been deleted!"<<endl;
		delete head;
		delete tail;
	}
};

int64_t IncSize(LinkedList& list)
{
	return list.size++;
}

int64_t DecSize(LinkedList& list)
{
	return list.size--;
}

bool isEmpty(LinkedList& list)
{
	return list.size == 0;
							
}

void AddFirst(LinkedList& list, int64_t value)
{
	cout<<"Add a head node has value <"<<value<<">: "<<endl;	
	Node* node = new Node(value);
	if (isEmpty(list))
	{
		list.head = node;
		list.tail = node;
	}
	else
	{
		node->next = list.head;
		list.head = node;
	}
	IncSize(list);
	cout<<endl;
}

void AddLast(LinkedList& list, int64_t value)
{	
	cout<<"Add a tail node has value <"<<value<<">: "<<endl;	
	Node* node = new Node(value);
	if (isEmpty(list))
	{
		list.head = node;
		list.tail = node;
	}
	else
	{
	list.tail->next = node;
	list.tail = node;
	}
	IncSize(list);
	cout<<endl;	
}

void AddPosition(LinkedList& list, int64_t pos, int64_t value)
{
	cout<<"Add a node has value <"<<value<<"> at position <"<<pos<<"> :"<<endl;
	Node* node = new Node(value);
	Node* ptr = list.head;
	if (isEmpty(list))
	{
		list.head = node;
		list.tail = node;
	}
	else
	{
		int i = 0;
		while (i<pos-1)
		{
			ptr = ptr->next;
			i++;
		}
	
	
		node->next = ptr->next;
		ptr->next = node;
	}
	IncSize(list);
	cout<<endl;	
}

void RemoveHead(LinkedList& list)
{
	cout<<"Remove a head node:"<<endl;
	if (isEmpty(list))
	{
		cout<<"List is Empty!"<<endl;
	}
	else
	{
	Node* node;
	node = list.head;
	list.head = list.head->next;	
	DecSize(list);
	delete node;
	}
	if (isEmpty(list))
		list.tail = NULL;
	
	cout<<endl;	
}

void RemoveTail(LinkedList& list)
{	
	cout<<"Remove a tail node: "<<endl;
	if (isEmpty(list))
	{
		cout<<"List is Empty!"<<endl;
		return;
	}
	Node* node;
	Node* ptr;
	ptr = list.head;
	int i = 1;
	while (i<list.size-1)
	{
		ptr = ptr->next;
		i++;	
	}
	node = ptr->next;
	list.tail = ptr;
	delete node;
	if (list.tail->next = NULL)
	{
		list.tail = NULL;
	}
	else
	{
	list.tail->next = NULL;
	}
	DecSize(list);
	cout<<endl;	
		
}

void RemoveAny(LinkedList& list, uint64_t pos)
{
	cout<<"Remove position <"<<pos<<">: "<<endl;
	if (isEmpty(list))
	{
		cout<<"List is Empty"<<endl;
		return;
	}
	if (pos <= 0 || pos >= list.size-1)
	{
		cout<<"Out of the range of the linked list!"<<endl;
		return;
	}
	Node* node;
	Node* ptr;
	ptr = list.head;
	int i = 1;
	while (i<pos-1)
	{
		ptr = ptr->next;
		i++;
	}
	node = ptr->next;
	ptr->next = ptr->next->next;
	delete node;
	DecSize(list);
	cout<<endl;	
	 
}


uint64_t SearchPosition(LinkedList& list, int64_t value)
{
	uint64_t check = -1;
	Node* node;
	if (isEmpty(list))
	{
		cout<<"List is Empty"<<endl;
		return -1;
	}	
	node = list.head;
	int i = 0;
	while (i<list.size)
	{
		if (node->data == value) 
		{
			check = i;
			break;
		}
		else
		{
			node = node->next;
			i++;
		}
	}
	if (check == -1)
	{
		cout<<"The value <"<<value<<"> isn't exist in this LinkedList"<<endl;	
	}
	else
	{
		cout<<"Position of value <"<<value<<">: "<<check<<endl;
	}
	return check;	
}

int64_t CheckValueAt(LinkedList& list, uint64_t pos)
{
	Node* ptr;
	int64_t dat;
	if (isEmpty(list))
	{
		cout<<"List is Empty"<<endl;
		return -1;
	}
	if (pos<0 || pos>= list.size)
	{
		cout<<"Out of the range of the linked list"<<endl;
		return -1;	
	}
	ptr = list.head;
	int i=0;
	while (i<pos)
	{
		ptr = ptr->next;
		i++;
	}
	cout<<"The value of the position <"<<pos<<"> is: "<<ptr->data<<endl;
	dat = ptr->data;
	return dat;	
}

void RemoveList(LinkedList& list)
{
	cout<<"Removed list!"<<endl;
	Node* ptr;
	ptr = list.head;
	int count = list.size;
	while (count!=0)
	{
		Node* node;
		node = ptr;
		ptr = ptr->next;
		list.head = ptr;
		delete node;
		count--;	
	}	
	list.size = count;
	delete ptr;
	list.head = NULL;
	list.tail = NULL;
	cout<<endl;	
}


void Display(LinkedList& list)
{
	if (isEmpty(list))
	{
		cout<<"List is Empty!"<<endl;
		cout<<"Size of List: "<<list.size<<endl;		
		return;
	}
	
	Node* node;
	node = list.head;
	while (node != NULL)
	{
		cout<<node->data<<"->";
		node = node->next;
	}
	cout<<endl;
	cout<<"Size of List: "<<list.size<<endl;		
	
	cout<<endl;	
}



int main(){
	LinkedList list;
	AddFirst(list, 7);	
	Display(list);
	AddFirst(list, 8);
	Display(list);
	AddFirst(list, 12);
	Display(list);
	RemoveAny(list, 1);
	Display(list);
	AddLast(list, 34);
	Display(list);
	RemoveTail(list);
	Display(list);
	AddFirst(list, 9);
	Display(list);
	AddLast(list, 1);
	Display(list);
	AddPosition(list, 2, 100);
	Display(list);
	SearchPosition(list, 1);
	SearchPosition(list, 999);
        
	CheckValueAt(list, 0);
	CheckValueAt(list, 1);
	CheckValueAt(list, 2);
	CheckValueAt(list, 3);
	CheckValueAt(list, 4);
	CheckValueAt(list, 5);
	CheckValueAt(list, 6);
	AddPosition(list,3, 992);
	Display(list);
	RemoveList(list);
        return 0;
}

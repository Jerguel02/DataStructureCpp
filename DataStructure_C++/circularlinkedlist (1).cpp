#include <iostream>
#include <stdint.h>



using namespace std;

struct Node
{
	int64_t data;
	Node* prev;
	Node* next;
	Node(int64_t init_data)
	{
		data = init_data;
		next = NULL;	
		prev = NULL;
	}
	~Node()
	{
		cout<<"Node has been deleted!"<<endl;
	}
};



struct LinkedList
{
	Node* head;
	Node* tail;
	uint32_t size;
	LinkedList()
	{
		head =	NULL;
		tail = NULL;
		size = 0;
	}
	~LinkedList()
	{
		cout<<"LL has been deleted!"<<endl;
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
		node->prev = list.tail;
		list.head->prev = node;
		list.head = node;
		list.tail->next = node;
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
		node->prev = list.tail;
		list.tail = node;
		list.tail->next = list.head;
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
		int i = 1;
		while (i<list.size-1)
		{
			ptr = ptr->next;
			i++;
		
		}	
	
		node->next = ptr->next;
		node->prev = ptr;
		ptr->next = node;
		ptr = ptr->next->next;
		ptr->prev = node;
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
	else if (list.head == list.tail)
	{
		Node* node;
		node = list.head;
		list.head = NULL;
		list.tail = NULL;
		DecSize(list);
		delete node;
	}
	else
	{
		Node* node;
		node = list.head;
		list.head = list.head->next;
		list.head->prev=list.tail;	
		DecSize(list);
		delete node;
	}
}

void RemoveTail(LinkedList& list)
{	
	cout<<"Remove a tail node: "<<endl;
	if (isEmpty(list))
	{
		cout<<"List is Empty!"<<endl;
		return;
	}
	if (list.head == list.tail)
	{
		Node* node;
		node = list.head;
		list.head = NULL;
		list.tail = NULL;
		DecSize(list);
		delete node;
		return;
	} 
	Node* ptr;
	Node* node;
	ptr = list.head;
	
	int i = 1;
	while (i<list.size-1)
	{
		ptr = ptr->next;
		i++;	
	}
	list.tail = ptr;
	node = ptr->next;
	list.tail->next = list.head;
	list.head->prev = list.tail;
	delete node;
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
	if (pos < 0 || pos > list.size-1)
	{
		cout<<"Out of the range of the linked list!"<<endl;
		return;
	}
	if (list.head == list.tail)
	{
		Node* node;
		node = list.head;
	 	list.head = NULL;
		list.tail = NULL;
		delete node;
		return;
	}
	Node* node;
	Node* ptr;
	Node* tempNode;
	ptr = list.head;
	int i = 1;
	while (i<pos-1)
	{
		ptr = ptr->next;
		i++;
	}
	node = ptr->next;
	ptr->next = ptr->next->next;
	tempNode = ptr->next;
	tempNode->prev = ptr;
	delete node;	
	DecSize(list);	
	 
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
	cout<<endl;	
}

int64_t CheckValueAt(LinkedList& list, uint64_t pos)
{
	Node* ptr;
	int64_t half_size = (list.size-1)/2;
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
	if (pos<=half_size)
	{
		ptr = list.head;
		uint64_t i=0;
		while (i<pos)
		{
			ptr = ptr->next;
			i++;
		}
	}
	else 
	{
		ptr = list.tail;
		uint64_t i=list.size-1;
		while (i>pos)
		{
			ptr = ptr->prev;
			i--;
		} 	
	}
	cout<<"The value of the position <"<<pos<<"> is: "<<ptr->data<<endl;
	return ptr->data; 
	cout<<endl;	
}

void RemoveList(LinkedList& list)
{
	cout<<"Removed list!"<<endl;
	Node* ptr;
	ptr = list.head;
	int i=0;
	while (i<list.size)
	{
		Node* node;
		node = ptr;
		ptr = ptr->next;
		list.head = ptr;
		delete node;
		DecSize(list);	
	}
	ptr = NULL;
	delete ptr;
	list.head = NULL;
	list.tail = NULL;
	cout<<endl;	
}


void Display(LinkedList& list, bool reverse = 0)
{
	if (isEmpty(list))
	{
		cout<<"List is Empty!"<<endl;
		cout<<"Size of List: "<<list.size<<endl;		
		return;
	}
	
	Node* node;
	if (reverse == 0)
	{
		cout<<"List from head to tail: "<<endl;
		node = list.head;
		while (node != list.tail)
		{
			cout<<node->data<<"<->";
			node = node->next;
		}
		cout<<node->data;
	}
	else
	{
		cout<<"List from tail to head: "<<endl;
		node = list.tail;
		while (node != list.head)
		{
			cout<<node->data<<"<->";
			node = node->prev;
		}
		cout<<node->data;
	}
	cout<<endl;
	cout<<"Size of List: "<<list.size<<endl;		
	
	cout<<endl;	
}



int main(){
	LinkedList list;
	AddFirst(list, 0);
	RemoveHead(list);
	RemoveHead(list);
	AddFirst(list, 1);
	RemoveTail(list);
	RemoveTail(list);
	AddFirst(list, 2);
	AddFirst(list, 3);
	AddFirst(list, 4);
	Display(list);
	Display(list, 1);
	AddLast(list, 3);
	RemoveTail(list);
	RemoveTail(list);
	AddLast(list, 4);
	cout<<"Head value: "<<list.head->data<<endl;
	cout<<"Prev value of head: "<<list.head->prev->data<<endl;
	cout<<"Next value of tail: "<<list.head->next->data<<endl;
	cout<<"Tail value: "<<list.tail->data<<endl;
	cout<<"Prev value of tail: "<<list.tail->prev->data<<endl;
	cout<<"Next value of tail: "<<list.tail->next->data<<endl;
	RemoveList(list);
	AddFirst(list, 4);
	Display(list);
	RemoveAny(list, 0);	
        return 0;
}

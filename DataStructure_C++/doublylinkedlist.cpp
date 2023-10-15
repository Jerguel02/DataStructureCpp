#include <iostream>
#include <stdint.h>



using namespace std;

struct Node
{
	int64_t data;
	Node* prev;
	Node* next;
	Node(uint64_t init_dat)
	{
		data = init_dat;
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
		head = NULL;
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
	node->prev = NULL;
	list.head->prev = node;
	list.head = node;
	}
	IncSize(list);	
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
	}
	IncSize(list);	
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
		return;
	}
	Node* node;
	if (list.head == list.tail)
	{
		node = list.head;
		list.head = NULL;
		list.tail = NULL;
		delete node;	
	}
	else
	{
		Node* node;
		node = list.head;
		list.head = list.head->next;
		list.head->prev=NULL;	
		node = NULL;
		delete node;
	}
	
	DecSize(list);
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
	else if (list.head == list.tail)
	{
		Node* node;
		node = list.head;
		list.head = NULL;
		list.tail = NULL;
		delete node;
		DecSize(list);
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
	list.tail = ptr;
	node = ptr->next;
	ptr->next = NULL;
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
	if (pos <= 0 || pos >= list.size-1)
	{
		cout<<"Out of the range of the linked list!"<<endl;
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
	list.head = NULL;
	list.tail = NULL;	
	cout<<endl;	
}


void Display(LinkedList& list, int reverse = 0)
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
		while (node != NULL)
		{
			cout<<node->data<<"<->";
			node = node->next;
		}
	}
	else
	{
		cout<<"List from tail to head: "<<endl;
		node = list.tail;
		while (node != NULL)
		{
			cout<<node->data<<"<->";
			node = node->prev;
		}
	}
	cout<<endl;
	cout<<"Size of List: "<<list.size<<endl;		
	
	cout<<endl;	
}



int main(){
	LinkedList list;
	AddFirst(list, 7);
	RemoveHead(list);
	RemoveHead(list);
	RemoveTail(list);	
	//AddFirst(list, 8);
	//AddFirst(list, 12);
	RemoveAny(list, 1);
	AddLast(list, 34);
	RemoveTail(list);
	AddFirst(list, 9);
	SearchPosition(list, 34);
	CheckValueAt(list, 2);
	AddLast(list, 1);
	AddPosition(list, 2, 100);
	Display(list);
	RemoveList(list);
	Display(list);

        return 0;
}

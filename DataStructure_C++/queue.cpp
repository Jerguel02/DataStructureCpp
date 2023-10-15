#include <iostream>
#include <stdint.h>

using namespace std;

struct Node
{
	int64_t data;
	Node* next;
	Node (int64_t val)
	{
		data = val;
		next = NULL;
	}
	~Node()
	{
		cout<<"Node has been deleted!"<<endl;
	}
};

struct Queue 
{
	uint64_t size;
	Node* front;
	Node* rear;
	uint64_t MAX_SIZE;
	Queue(uint64_t max_size)
	{
		MAX_SIZE = max_size;
		cout<<"Queue has been created with size = <"<<MAX_SIZE<<">"<<endl;
		front = NULL;
		rear = NULL;
		size = 0;
	}
	~Queue()
	{
		cout<<"Queue has been deleted!"<<endl;
	}

};

void IncSize(Queue& queue)
{
	queue.size++;
}

void DecSize(Queue& queue)
{
	queue.size--;
}

bool isFull(Queue& queue)
{
	return queue.size == queue.MAX_SIZE;
}

bool isEmpty(Queue& queue)
{
	return queue.size == 0;
}

int64_t enqueue(Queue& queue, int64_t value)
{
	cout<<"Enqueue: "<<endl;
	if (isFull(queue))
	{
		cout<<"Queue is full"<<endl;
		return -1;
	}
	Node* node = new Node(value);
	if (isEmpty(queue))
	{
		queue.front = node;
		queue.rear = node;
	}
	else
	{
		queue.rear->next = node;
		queue.rear = node;
	}
	IncSize(queue);
	cout<<"Enqueue a node has value <"<<queue.rear->data<<"> into the queue"<<endl;
	return queue.rear->data;


}

int64_t dequeue(Queue& queue)
{
	cout<<"Dequeue: "<<endl;
	int64_t element;
	if (isEmpty(queue))
	{
		cout<<"Queue is Empty!"<<endl;
		return -1;
	}
	Node* node;
	node = queue.front;
	if (queue.front == queue.rear)
	{
		queue.front = NULL;
		queue.rear = NULL;
	}
	else
	{
		queue.front = queue.front->next;
	}
	element = node->data;
	cout<<"Dequeue front-node has value <"<<node->data<<"> out the queue"<<endl;
	DecSize(queue);
	delete node;
	return element;
}

int64_t peek(Queue& queue)
{
	cout<<"Peek: "<<endl;
	if (isEmpty(queue))
	{
		cout<<"Queue is empty!"<<endl;
		return -1;
	}
	cout<<"Front-node value: <"<<queue.front->data<<">"<<endl;
	return queue.front->data;
}

void RemoveQueue(Queue& queue)
{
	while (queue.size !=0)
	{
		dequeue(queue);
	}
	
}

void Display(Queue& queue)
{
	if (isEmpty(queue))
	{
		cout<<"Queue is Empty!"<<endl;
		return;
	}
	Node* ptr;
	ptr = queue.front;
	while (ptr != queue.rear)
	{
		cout<<ptr->data<<"-->";
		ptr = ptr->next;
	}
	cout<<ptr->data<<endl<<"Size: "<<queue.size<<endl;
	peek(queue);

}
int main()
{
	Queue queue(4);
	enqueue(queue, 0);
	Display(queue);
	enqueue(queue, 1);
	Display(queue);
	enqueue(queue, 2);
	Display(queue);
	enqueue(queue, 3);
	Display(queue);
	enqueue(queue, 4);
	Display(queue);
//	cout<<queue.front->data<<endl;
//	cout<<queue.rear->data<<endl;
//	cout<<queue.front->next->data<<endl;
	dequeue(queue);
	Display(queue);
	RemoveQueue(queue);
	Display(queue);
	
}





















#include <iostream>
#include <stdint.h>

using namespace std;

struct Node
{
	int64_t node_data;
	Node* next;
	Node(int64_t data)
	{
		node_data = data;
		next = NULL;
	}

};

struct Stack
{
	uint64_t size;
	Node* top;
	uint64_t MAX_SIZE;
	Stack(uint64_t max_val)
	{
		cout<<"Stack has been created!"<<endl;
		MAX_SIZE = max_val;
		top = NULL;
		size = 0;
	}
	~Stack()
	{
		cout<<"Stack has been deleted!"<<endl;
	}

};

void IncSize(Stack& stack)
{
	stack.size++;
}

void DecSize(Stack& stack)
{
	stack.size--;
}

bool isFull(Stack& stack)
{
	return stack.size == stack.MAX_SIZE;
}

bool isEmpty(Stack& stack)
{
	return stack.size == 0;
}

void push(Stack& stack, int64_t val)
{
	cout<<"Push node has value <"<<val<<"> into the stack"<<endl;
	if (isFull(stack))
	{
		cout<<"Stack overflow!"<<endl;
		return;
	}
	Node* node = new Node(val);
	if (isEmpty(stack))
	{
		stack.top = node;
	}
	else
	{
		node->next = stack.top;
		stack.top = node;
	}
	IncSize(stack);
		
}

int64_t pop(Stack& stack)
{
	if (isEmpty(stack))
	{
		cout<<"Stack underflow!"<<endl;
		return -1;
	}
	cout<<"Pop top-node value <"<<stack.top->node_data<<"> out the stack"<<endl;
	int64_t pop_val;
	Node* ptr;
	ptr = stack.top;
	pop_val = ptr->node_data;
	stack.top = stack.top->next;
	delete ptr;
	DecSize(stack);
	return pop_val;
}

int64_t peek(Stack& stack)
{
	if (isEmpty(stack))
	{
		cout<<"Stack underflow!"<<endl;
		return -1;
	}
	cout<<"The top value of the stack is <"<<stack.top->node_data<<">" <<endl;
	return stack.top->node_data;
}

void RemoveStack(Stack& stack)
{
	cout<<"Remove Stack!"<<endl;
	while (stack.size != 0)
	{
		pop(stack);
	}
}


void Display(Stack& stack)
{
	if (isEmpty(stack))
	{
		cout<<"Stack underflow!"<<endl;
		return;
	}

	Node* ptr;
	ptr = stack.top;
	while (ptr != NULL)
	{
		cout<<ptr->node_data<<"-->";
		ptr = ptr->next;
	}
	cout<<endl;
	peek(stack);
	cout<<"Size: "<<stack.size<<endl;
	cout<<"-/-"<<endl;
}
int main()
{
	Stack stack(5);
	push(stack, 0);
	Display(stack);
	push(stack, 1);
	Display(stack);
	push(stack, 2);
	Display(stack);
	push(stack, 3);
	Display(stack);
	pop(stack);
	Display(stack);
	pop(stack);
	Display(stack);
	pop(stack);
	Display(stack);
	pop(stack);
	Display(stack);
	pop(stack);
	push(stack, 0);
	Display(stack);
	push(stack, 1);
	Display(stack);
	push(stack, 2);
	Display(stack);
	push(stack, 3);
	Display(stack);
	RemoveStack(stack);
	Display(stack);
}








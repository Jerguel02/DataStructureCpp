#include <iostream>
#include <stdint.h>

using namespace std;

struct Stack
{
	int64_t size;
	int64_t *data;
	int64_t top;
	uint64_t MAX_SIZE;
	Stack (uint64_t max_size)
	{
		cout<<"Stack has been created!!!"<<endl;
		MAX_SIZE = max_size;
		data = new int64_t[MAX_SIZE];
		top = -1;
		size = 0;
	}
	~Stack()
	{
		delete[] data;
		cout<<"Stack has been deleted!!!"<<endl;
	}


};

uint64_t IncSize(Stack& stack)
{
	return stack.size++;
}

uint64_t DecSize(Stack& stack)
{
	return stack.size--;
}

bool isFull(Stack& stack)
{
	return stack.size == stack.MAX_SIZE;
}

bool isEmpty(Stack& stack)
{
	return stack.size == 0;
}

int64_t push(Stack& stack, int64_t value)
{
	cout<<"Push value <"<<value<<"> into the stack!!!"<<endl;
	if (isFull(stack))
	{
		cout<<"Stack overflow!"<<endl;
		return -1;
	}
	stack.top++;
	stack.data[stack.top] = value;
	IncSize(stack);
	return stack.data[stack.top];

}

int64_t pop(Stack& stack)
{
	if (isEmpty(stack))
	{
		cout<<"Stack underflow!"<<endl;
		return -1;
	}
	int64_t pop_val;
	cout<<"Pop value <"<<stack.data[stack.top]<<"> out the stack!!!"<<endl;
	pop_val = stack.data[stack.top];
	stack.top--;
	DecSize(stack);
	return pop_val;

}

int64_t peek(Stack& stack)
{
	if (isEmpty(stack))
	{
		cout<<"Stack underflow!!!"<<endl;
		return -1;
	}
	cout<<"The top value of the stack is <"<<stack.data[stack.top]<<">"<<endl;
	return stack.data[stack.top];
}

void Display(Stack& stack)
{
	if (isEmpty(stack))
	{
		cout<<"Stack underflow!!!"<<endl;
		return;
	}
	for (int64_t i = stack.top; i>=0; i--)
	{
		cout<<stack.data[i]<<endl<<"----"<<endl;
	}
	cout<<"Stack size: "<<stack.size<<endl;
}


int main()
{
	Stack stack(6);
	push(stack, 0);
	Display(stack);
	push(stack, 1);
	Display(stack);
	push(stack, 2);
	Display(stack);
	peek(stack);
	push(stack, 3);
	Display(stack);
	push(stack, 4);
	Display(stack);
	push(stack, 5);
	Display(stack);
	push(stack, 6);
	peek(stack);
	Display(stack);
	pop(stack);
	Display(stack);
	pop(stack);
	pop(stack);
	peek(stack);
	pop(stack);
}



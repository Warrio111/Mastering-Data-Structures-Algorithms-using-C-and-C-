#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
}*top = NULL;
void push(int x)
{
	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));
	if (NULL == t)
	{
		printf("Stack is full \n");
	}
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}
int pop()
{
	struct Node* t;
	int x = -1;
	if (NULL == top)
	{
		printf("Stack is Empty \n");
	}
	else
	{
		t = top;
		top = top->next;
		x = t->data;
		free(t);
	}
	return x;
}
void Display()
{
	struct Node* p;
	p = top;
	while (NULL != p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("%\n ");
}
int main()
{

	push(10);
	push(20);
	push(30);
	push(40);
	push(50);

	Display();
	printf("%d \n", pop());
	return 0;
}
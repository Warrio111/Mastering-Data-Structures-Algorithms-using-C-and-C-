#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
}*first = NULL;

void create(int A[], int n)
{
	struct Node* t, * last;
	int i;
	first = (struct Node*)malloc(sizeof(struct Node));
	first->data = A[0];
	first->prev = first->next = NULL;
	last = first;
	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = last->next;
		t->prev = last;
		last->next = t;
		last = t;
	}
}
void Display(struct Node* p)
{
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n\n");
}
int Length(struct Node* p)
{
	int length = 0;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}
void Insert(struct Node* p, int index, int x)
{
	struct Node* t;
	int i;
	if (index<0 || index>Length(p)) { return; }
	if (index == 0)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = x;
		t->next = first;
		t->prev = NULL;
		first->prev = t;
		first = t;
	}
	else
	{
		for (i = 0; i < index - 1; i++) { p = p->next; }
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = x;
		t->prev = p;
		t->next = p->next;
		if (p->next) { p->next->prev = t; }
		p->next = t;
	}
}
int Delete(struct Node* p, int index)
{
	struct Node* q;
	int x;
	int i;
	x = -1;
	if (index<1 || index>Length(p))
	{
		return -1;
	}
	if (index == 1)
	{
		first = first->next;
		if (first) { first->prev = NULL; }
		x = p->data;
		free(p);

	}
	else
	{
		for (i = 0; i < index - 1; i++) { p = p->next; }
		p->prev->next = p->next;
		if (p->next) { p->next->prev = p->prev; }
		x = p->data;
		free(p);
	}

	return x;
}
void Reverse(struct Node* p)
{
	struct Node* t;
	int i;
	while (NULL != p)
	{
		t = p->next;
		p->next = p->prev;
		p->prev = t;
		p = p->prev;
		if (NULL != p && NULL == p->next) { first = p; }
	}
}
int main()
{
	int A[] = { 2,3,4,5,6 };
	create(A, 5);
	Insert(first, 0, 20);
	Delete(first, 3);
	Reverse(first);
	Display(first);
	return 0;
}
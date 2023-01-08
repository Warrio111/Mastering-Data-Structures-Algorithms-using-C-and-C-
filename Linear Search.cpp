#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
}*first = NULL;
void create(int A[], int n)
{
	int i;
	struct Node* t, * last;
	first = (struct Node*)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
void Display(struct Node* p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
void RDisplay(struct Node* p)
{
	if (p != NULL)
	{
		RDisplay(p->next);
		printf("%d ", p->data);

	}
}
int count(struct Node* p)
{
	int l;
	l = 0;
	while (p)
	{
		l++;
		p = p->next;
	}
	return l;
}
int Rcount(struct Node* p)
{
	if (NULL != p)
	{
		return Rcount(p->next) + 1;
	}
	else
	{
		return 0;
	}
}
int Sum(struct Node* p)
{
	int sum;
	sum = 0;
	while (NULL != p)
	{
		sum = sum + p->data;
		p = p->next;
	}
	return (sum);
}
int RSum(struct Node* p)
{
	if (NULL == p)
	{
		return 0;
	}
	else
	{
		return RSum(p->next) + p->data;
	}
}
int main()
{
	struct Node* temp;
	int A[] = { 3,5,7,10,25,8,32,2 };
	create(A, 8);

	Display(first);

	return 0;
}
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
int Max(struct Node* p)
{
	int max = INT_MIN;
	while (p)
	{
		if (p->data > max)
		{
			max = p->data;

		}
		p = p->next;

	}
	return max;
}
int RMax(struct Node* p)
{
	int x;
	x = 0;
	if (p == NULL)
	{
		return INT_MIN;

	}
	x = RMax(p->next);
	return x > p->data ? x : p->data;

}
struct Node* LSearch(struct Node* p, int key)
{
	struct Node* q = NULL;

	while (NULL != p)
	{
		if (key == p->data)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}
struct Node* RSearch(struct Node* p, int key)
{
	if (NULL == p) { return NULL; }
	if (key == p->data) { return p; }
	return RSearch(p->next, key);
}
void Insert(struct Node* p, int index, int x)
{
	struct Node* t;
	int i;
	if (index < 0 || index>count(p))
	{
		return;
	}

	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;

	if (index == 0)
	{
		t->next = first;
		first = t;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		t->next = p->next;
		p->next = t;

	}

}
int main()
{
	Insert(first, 0, 12);
	Insert(first, 1, 20);
	Insert(first, 2, 30);
	Insert(first, 2, 40);

	Display(first);

	return 0;
}
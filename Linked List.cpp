#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
}*first, * last = NULL, * second = NULL, * third = NULL;
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
void create2(int A[], int n)
{
	int i;
	struct Node* t, * last;
	second = (struct Node*)malloc(sizeof(struct Node));
	second->data = A[0];
	second->next = NULL;
	last = second;

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
void InsertLast(int x)
{
	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;
	if (NULL == first)
	{
		first = last = t;
	}
	else {
		last->next = t;
		last = t;
	}
}
void InsertSorted(struct Node* p, int x)
{
	struct Node* q = NULL;
	struct Node* t = NULL;
	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;
	t->next = NULL;
	if (NULL == first)
	{
		first = t;
	}
	else
	{
		while ((p) && (p->data < x))
		{
			q = p;
			p = p->next;
		}
		if (p == first)
		{
			t->next = first;
			first = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}



}
int DeletingNode(int index)
{
	struct Node* p;
	struct Node* q = NULL;
	int i;
	int x;
	x = -1;
	if (index == 1)
	{
		x = first->data;
		p = first;
		first = first->next;
		free(p);
	}
	else
	{
		p = first;
		q = NULL;
		for (i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}
		if (p)
		{
			q->next = p->next;
			x = p->data;
			free(p);
		}
	}
	return x;
}
int isSorted(struct Node* p)
{
	int x = INT_MIN;
	while (NULL != p)
	{
		if (p->data < x)
		{
			return 0;
		}
		x = p->data;
		p = p->next;
	}
	return 1;
}
void RemoveDuplicate(struct Node* p)
{
	struct Node* q = p->next;
	while (NULL != q)
	{
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}
}
void ReverseWithArray(struct Node* p)
{
	int* A;
	int i;
	i = 0;
	struct Node* q = p;
	A = (int*)malloc(sizeof(int) * count(p));
	while (NULL != q)
	{
		A[i] = q->data;
		q = q->next;
		i++;
	}
	q = p;
	i--;
	while (NULL != q)
	{
		q->data = A[i];
		q = q->next;
		i--;
	}

}
void ReverseWithSlidiningPointer(struct Node* p)
{
	struct Node* q = NULL, * r = NULL;
	while (NULL != p)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;
}
void ReverseWithRecursivity(struct Node* q, struct Node* p)
{
	if (p)
	{
		ReverseWithRecursivity(p, p->next);
		p->next = q;
	}
	else
	{
		first = q;
	}
}
void Concat(struct Node* p, struct Node* q)
{
	third = p;
	while (NULL != p->next)
	{
		p = p->next;
	}
	p->next = q;
}
void Merge(struct Node* p, struct Node* q)
{
	struct Node* last;
	if (p->data < q->data)
	{
		third = last = p;
		p = p->next;
		third->next = NULL;
	}
	else
	{
		third = last = q;
		q = q->next;
		third->next = NULL;
	}
	while (p && q)
	{
		if (p->data < q->data)
		{
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;
		}
		else
		{
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;
		}
	}
	if (p) { last->next = p; }
	if (q) { last->next = q; }
}
int isLoop(struct Node* f)
{
	struct Node* p, * q;
	p = q = f;
	do
	{
		p = p->next;
		q = q->next;
		q = q ? q->next : q;
	} while (p && q && p != q);
	if (p == q)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	struct Node* t1, * t2;
	int A[] = { 10,20,30,40,50 };
	create(A, 5);
	t1 = first->next->next;
	t2 = first->next->next->next->next;
	t2->next = t1;
	printf("\n%d\n", isLoop(first));
	return 0;
}
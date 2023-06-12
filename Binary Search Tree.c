#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* lchild;
	struct Node* rchild;
	int data;
}*root = NULL;

void Insert(int key)
{
	struct Node* t = root;
	struct Node* r = NULL, * p;

	if (NULL == root)
	{
		p = (struct Node*)malloc(sizeof(struct Node));
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
		return;
	}

	while (NULL != t)
	{
		r = t;
		if (key < t->data)
		{
			t = t->lchild;
		}
		else if (key > t->data)
		{
			t = t->rchild;
		}
		else
		{
			return;
		}
	}
	p = (struct Node*)malloc(sizeof(struct Node));
	p->data = key;
	p->lchild = p->rchild = NULL;

	if (key < r->data)
	{
		r->lchild = p;
	}
	else
	{
		r->rchild = p;
	}

}

void Inorder(struct Node* p)
{
	if (p)
	{
		Inorder(p->lchild);
		printf("%d ", p->data);
		Inorder(p->rchild);
	}
}

struct Node* Search(int key)
{
	struct Node* t = root;

	while (NULL != t)
	{
		if (key == t->data)
		{
			return t;
		}
		else if (key < t->data)
		{
			t = t->lchild;
		}
		else
		{
			t = t->rchild;
		}

	}
	return NULL;
}

struct Node* RInsert(struct  Node* p, int key)
{
	struct Node* t = NULL;

	if (NULL == p)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = key;
		t->lchild = t->rchild = NULL;
		return t;
	}
	if (key < p->data)
	{
		p->lchild = RInsert(p->lchild, key);
	}
	else if (key > p->data)
	{
		p->rchild = RInsert(p->rchild, key);
	}
	return p;
}

int Height(struct Node* p)
{
	int x, y;
	if (NULL == p)
	{
		return 0;
	}
	x = Height(p->lchild);
	y = Height(p->rchild);
	return x > y ? x + 1 : y + 1;
}

struct Node* InPre(struct Node* p)
{
	while (p && p->rchild != NULL)
	{
		p = p->rchild;
	}
	return p;
}

struct Node* InSucc(struct Node* p)
{
	while (p && p->lchild != NULL)
	{
		p = p->lchild;
	}
	return p;
}
struct Node* Delete(struct Node* p, int key)
{
	struct Node* q;
	if (NULL == p)
	{
		return NULL;
	}
	if (NULL == p->lchild && NULL == p->rchild)
	{
		if (p == root)
		{
			root = NULL;
		}
		free(p);
		return NULL;
	}

	if (key < p->data)
	{
		p->lchild = Delete(p->lchild, key);
	}
	else if (key > p->data)
	{
		p->rchild = Delete(p->rchild, key);
	}
	else
	{
		if (Height(p->lchild) > Height(p->rchild))
		{
			q = InPre(p->lchild);
			p->data = q->data;
			p->lchild = Delete(p->lchild, q->data);
		}
		else
		{
			q = InSucc(p->rchild);
			p->data = q->data;
			p->rchild = Delete(p->rchild, q->data);
		}
	}
	return p;
}

int main(int argc, char* argv[])
{
	struct Node* temp;
	root = RInsert(root, 10);
	RInsert(root, 5);
	RInsert(root, 20);
	RInsert(root, 8);
	RInsert(root, 30);

	Delete(root, 20);

	Inorder(root);
	printf("\n");

	temp = Search(5);
	if (NULL != temp)
	{
		printf("\nElement %d found ", temp->data);
	}
	else
	{
		printf("ELEMENT NOT FOUND");
	}
	return 0;
}


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

int main(int argc, char* argv[])
{
	struct Node* temp;
	Insert(10);
	Insert(5);
	Insert(20);
	Insert(8);
	Insert(30);

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


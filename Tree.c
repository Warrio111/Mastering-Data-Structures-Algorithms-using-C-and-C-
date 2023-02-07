#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* lchild;
	int data;
	struct Node* rchild;
};
struct Queue
{
	int size;
	int front;
	int rear;
	Node** Q;
};
struct Stack
{
	int size;
	int top;
	struct Node** S;
};
void stackcreate(struct Stack* st, int size)
{
	st->size = size;
	st->top = -1;
	st->S = (struct Node**)malloc(st->size * sizeof(struct Node*));
}
void push(struct Stack* st, struct Node* n)
{
	if (st->top == st->size - 1)
	{
		printf("Stack overflow\n");
	}
	else
	{
		st->top++;
		st->S[st->top] = n;
	}
}
struct Node* pop(struct Stack* st)
{
	struct Node* n = NULL;
	if (st->top == -1)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		n = st->S[st->top--];
	}
	return n;
}
int isEmptyStack(struct Stack st)
{
	if (st.top == -1)
	{
		return 1;
	}
	return 0;
}
int isFullStack(struct Stack st)
{
	return st.top == st.size - 1;
}
void create(struct Queue* q, int size)
{
	q->size = size;
	q->front = q->rear = 0;
	q->Q = (Node**)malloc(q->size * sizeof(Node*));
}
void enqueue(struct Queue* q, struct Node* x)
{
	if ((q->rear + 1) % q->size == q->front)
		printf("Queue is Full");
	else
	{
		q->rear = (q->rear + 1) % q->size;
		q->Q[q->rear] = x;
	}
}
struct Node* dequeue(struct Queue* q)
{
	struct Node* x = NULL;

	if (q->front == q->rear)
		printf("Queue is Empty\n");
	else
	{
		q->front = (q->front + 1) % q->size;
		x = q->Q[q->front];
	}
	return x;
}
int isEmpty(struct Queue q)
{
	return q.front == q.rear;
}
struct Node* root = NULL;
void Treecreate()
{
	struct Node* p, * t;
	int x;
	struct Queue q;
	create(&q, 100);
	printf("Enter root value");
	scanf("%d", &x);
	root = (struct Node*)malloc(sizeof(struct Node));
	root->data = x;
	root->lchild = root->rchild = NULL;
	enqueue(&q, root);
	while (!isEmpty(q))
	{
		p = dequeue(&q);
		printf("Enter left child of %d", p->data);
		scanf("%d", &x);
		if (x != -1)
		{
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			enqueue(&q, t);
		}
		printf("Enter right child %d", p->data);
		scanf("%d", &x);
		if (x != -1)
		{
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			enqueue(&q, t);
		}
	}
}
void Preorder(struct Node* p)
{
	if (p)
	{
		printf("%d ", p->data);
		Preorder(p->lchild);
		Preorder(p->rchild);
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
void Postorder(struct Node* p)
{
	if (p)
	{
		Postorder(p->lchild);
		Postorder(p->rchild);
		printf("%d ", p->data);
	}
}
void IterativePreorder(struct Node* p)
{
	struct Stack stk;
	stackcreate(&stk, 100);
	while (p || !isEmptyStack(stk))
	{
		if (p)
		{
			printf("%d ", p->data);
			push(&stk, p);
			p = p->lchild;
		}
		else
		{
			p = pop(&stk);
			p = p->rchild;
		}
	}
}
void IterativeInorder(struct Node* p)
{
	struct Stack stk;
	stackcreate(&stk, 100);
	while (p || !isEmptyStack(stk))
	{
		if (p)
		{

			push(&stk, p);
			p = p->lchild;
		}
		else
		{
			p = pop(&stk);
			printf("%d ", p->data);
			p = p->rchild;
		}
	}
}
void LevelOrder(struct Node* p)
{
	struct Queue q;
	create(&q, 100);

	printf("%d ", p->data);
	enqueue(&q, root);

	while (!isEmpty(q))
	{
		root = dequeue(&q);
		if (root->lchild)
		{
			printf("%d ", root->lchild->data);
			enqueue(&q, root->lchild);
		}
		if (root->rchild)
		{
			printf("%d ", root->rchild->data);
			enqueue(&q, root->rchild);
		}
	}
}
int count(struct Node* root)
{
	if (root)
	{
		return count(root->lchild) + count(root->rchild) + 1;
	}
	return 0;
}
int height(struct Node* root)
{
	int x;
	int y;
	x = 0;
	y = 0;
	if (root == 0)
	{
		return 0;
	}
	x = height(root->lchild);
	y = height(root->rchild);
	if (x > y)
		return x + 1;
	else
		return y + 1;
}
int main(int argc, char* argv[]) {

	Treecreate();


	printf("\ncount  %d", count(root));
	printf("\nheight  %d", height(root));

	return 0;
}


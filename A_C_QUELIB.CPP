#include<stdio.h>
#include<conio.h>

#define MaxLength 10

typedef int ElementType;

typedef struct
{
	ElementType Elements[MaxLength];
	int Front, Rear;
} Queue;

void MakeNull_Queue(Queue *Q)
{
	Q->Front=-1;
	Q->Rear=-1;
}

int Empty_Queue(Queue Q)
{
	return Q.Front==-1;
}

int Full_Queue(Queue Q)
{
	return (Q.Rear-Q.Front+1) % MaxLength==0;
}

void EnQueue(ElementType X,Queue *Q)
{
	if (!Full_Queue(*Q))
	{
		if (Empty_Queue(*Q)) Q->Front=0;
		Q->Rear=(Q->Rear+1) % MaxLength;
		Q->Elements[Q->Rear]=X;
	}
	else printf("Loi: Hang day!");
}

void DeQueue(Queue *Q)
{
	if (!Empty_Queue(*Q))
	{
		if (Q->Front==Q->Rear) MakeNull_Queue(Q);
		else Q->Front=(Q->Front+1) % MaxLength;
	}
	else printf("Loi: Hang rong!");
}

ElementType Front(Queue Q)
{
	return Q.Elements[Q.Front];
}


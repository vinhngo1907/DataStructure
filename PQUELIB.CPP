#include<stdio.h>
#include<conio.h>
#include<malloc.h>

typedef int ElementType;
typedef struct Node
{
	ElementType Data;
	Node* Next;
};

typedef Node* Position;
typedef struct
{
	Position Front, Rear;
} Queue;

void MakeNullQueue(Queue *Q)
{
	Q->Front=(Node*)malloc(sizeof(Node));
	Q->Front->Next=NULL;
	Q->Rear=Q->Front;
}

int EmptyQueue(Queue Q)
{
	return (Q.Front==Q.Rear);
}

void EnQueue(ElementType X, Queue *Q)
{
	Q->Rear->Next=(Node*)malloc(sizeof(Node));
	Q->Rear=Q->Rear->Next;
	//Dat gia tri vao cho Rear
	Q->Rear->Data=X;
	Q->Rear->Next=NULL;
}

void DeQueue(Queue *Q)
{
	Position T;
	T=Q->Front;
	Q->Front=Q->Front->Next;
	free(T);
}


ElementType Front(Queue Q)
{
	return Q.Front->Next->Data;
}


void ReadQueue(Queue *Q)
{
	MakeNullQueue(Q);
	int i,N,X;
	printf("So phan tu N = "); scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		printf("Phan tu thu %d: ",i); scanf("%d",&X);
		EnQueue(X,Q);
	}
}

void PrintQueue(Queue *Q)
{
	while (!EmptyQueue(*Q))
	{
		printf("%d ",Front(*Q));
		DeQueue(Q);
	}
	printf("\n");
}


void main()
{
	clrscr();
	Queue Q;
	ReadQueue(&Q);
	printf("\n\n Hang vua nhap la \n\n");
	PrintQueue(&Q);
	getch();
}
#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10
#define Null -1
typedef int Tree;
typedef int ElementType;

struct Node 
{
	ElementType Position;
	Tree Left;
	Tree Right;
} T[MaxTree];

struct QNode
{
	ElementType* Data;
	int Front, Rear;
	int MaxSize;
};

typedef struct QNode *Queue;

Tree BuildTree();
void CheckLeaves(Tree R);
Queue CreatQueue(int MaxSize);
int IsFull(Queue Q);
int AddQ(Queue Q, ElementType E);
int IsEmpty(Queue Q);
ElementType DeleteQ(Queue Q);

int main()
{
	Tree R;
	R = BuildTree();
	CheckLeaves(R);
	return 0;
}

Tree BuildTree()
{
	int N;
	int i;
	char cl, cr;
	int check[MaxTree];
	Tree Root = Null;
	scanf("%d\n", &N);
	if(N)
	{
		for(i=0; i<N; i++)
			check[i] = 0;
		for(i=0; i<N; i++)
		{
			scanf("%c %c\n", &cl, &cr);
			T[i].Position = i;
			if(cl != '-')
			{
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else
			{
				T[i].Left = Null;
			}
			if(cr != '-')
			{
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else
			{
				T[i].Right = Null;
			}
		}
		for(i=0; i<N; i++)
		{
			if(!check[i])
				break;
		}
		Root = i;
	}
	return Root;
}



void CheckLeaves(Tree Root)
{
	Queue Q = CreatQueue(MaxTree);
	AddQ(Q, T[Root].Position);
	ElementType X = 0;
	int flag = 0;
	while(!IsEmpty(Q))
	{
		X = DeleteQ(Q);
		if(T[X].Left != Null)
		{
			AddQ(Q, T[T[X].Left].Position);
		}
		if(T[X].Right != Null)
		{
			AddQ(Q, T[T[X].Right].Position);
		}
		if((T[X].Left == Null) && (T[X].Right == Null))
		{
			if(flag)
				printf(" ");
			else
			{
				flag = 1;
			}
			printf("%d", X);
		}
	}
	printf("\n");

}

Queue CreatQueue(int MaxSize)
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (ElementType*)malloc(sizeof(ElementType)*MaxSize);
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}

int IsFull(Queue Q)
{
	return ((Q->Rear+1)%Q->MaxSize == Q->Front);
}

int AddQ(Queue Q, ElementType E)
{
	if(IsFull(Q))
	{
		printf("队列满");
		return 0;
	}
	else
	{
		Q->Rear = (Q->Rear+1)%Q->MaxSize;
		Q->Data[Q->Rear] = E;
		return 1;
	}
}

int IsEmpty(Queue Q)
{
	return (Q->Front == Q->Rear);
}

ElementType DeleteQ(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("队列空");
		return Null;
	}
	else 
	{
		Q->Front = (Q->Front+1)%Q->MaxSize;
		return Q->Data[Q->Front];
	}
}
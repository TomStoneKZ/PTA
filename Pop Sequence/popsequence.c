#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1001

typedef struct Node
{
	int Data[MAXSIZE];
	int top;
	int capacity;
}Stack;

Stack* CreateStack();
void Push(Stack* s, int element);
int Pop(Stack* s);
int StackCheck(int M, int N, int data[]);

int main()
{
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);
	int* data = (int*)malloc(sizeof(int)*N);
	int* results = (int*)malloc(sizeof(int)*K);
	int i;
	int k = K; 
	while(k--)
	{
		for(i = 0; i< N; ++i)
		{
			scanf("%d", data+i);
		}
		*(results+k) = StackCheck(M, N, data);

	}
	k = K;
	while(k--)
	{
		if(results[k])
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

Stack* CreateStack()
{
	Stack* Ptrl = (Stack*)malloc(sizeof(struct Node));
	Ptrl->top = -1;
	Ptrl->capacity = MAXSIZE;
	return Ptrl;
}

void Push(Stack* s, int element)
{
	if(s->top == s->capacity - 1);
//		printf("Stack is full\n");
	++s->top;
	s->Data[s->top] = element;
}

int Pop(Stack* s)
{
	if(s->top == -1)
	{
//		printf("Stack is empty\n");
		return -1;
	}
	return s->Data[s->top--];
}

int StackCheck(int M, int N, int data[])
{
	Stack* s = CreateStack();
	s->capacity = M;
	Push(s, 0);

	int data_index = 0;
	int num = 1;

	while(data_index != N)
	{
		while(s->Data[s->top] != data[data_index] && s->top < s->capacity)
		{
			Push(s, num++);
		}
		if(s->Data[s->top] == data[data_index])
		{
			Pop(s);
			data_index++;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

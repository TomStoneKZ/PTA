#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read() 
{
	int Num, i;
	scanf("%d", &Num);
	List Ptrl = (List)malloc(sizeof(struct Node));
	List p = Ptrl;
	for(i=0; i<Num;++i)
	{
		List s = (List)malloc(sizeof(struct Node));
		p->Next = s;
		scanf("%d", &s->Data);
		p = p->Next;
	}
	return Ptrl;
}

List Merge(List L1, List L2)
{
	List L = (List)malloc(sizeof(struct Node));
	List l = L;
	while(L1->Next!=NULL && L2->Next!=NULL)
	{
		if(L1->Next->Data < L2->Next->Data)
		{
			l->Next = L1->Next;
			L1->Next = L1->Next->Next;
		}
		else
		{
			l->Next = L2->Next;
			L2->Next = L2->Next->Next;
		}
		l = l->Next;

	}

	if(L1->Next!=NULL)
	{
		while(L1->Next!=NULL)
		{
			l->Next=L1->Next;
			L1->Next = L1->Next->Next;
			l = l->Next;
		}
	}

	if(L2->Next != NULL)
	{
		while(L2->Next!=NULL)
		{
			l->Next=L2->Next;
			L2->Next = L2->Next->Next;
			l = l->Next;
		}
	}

	free(L1);
	free(L2);

	return L;
}

void Print( List L )
{
	if(L->Next==NULL)
		printf("NULL\n");
	else
	{
		List l = L->Next;
		while(l)
		{
			printf("%d ", l->Data);
			l=l->Next;
		}
		printf("\n");
	}
}

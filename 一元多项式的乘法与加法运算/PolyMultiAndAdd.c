#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode
{
	int coef;
	int expo;
	Polynomial link;
};

Polynomial ReadPoly();
void Attach(int coef, int expo, Polynomial *pRear);
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Multi(Polynomial P1, Polynomial P2);
void PrintPoly(Polynomial P);

int main()
{
	Polynomial P1 = ReadPoly();
	Polynomial P2 = ReadPoly();
	PrintPoly(Multi(P1, P2));
	PrintPoly(Add(P1, P2));

	return 0;
}

Polynomial ReadPoly()
{
	Polynomial P, Rear, t;
	int Num, coef, expo;
	scanf("%d", &Num);
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link=NULL;
	Rear = P;
	while(Num--)
	{
		scanf("%d %d", &coef, &expo);
		Attach(coef, expo, &Rear);
	}
	t = P; P=P->link; free(t);
	return P;
}

void Attach(int coef, int expo, Polynomial *pRear)
{
	Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = coef;
	P->expo = expo;
	P->link = NULL;

	(*pRear)->link=P;
	(*pRear)=P;
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
	Polynomial p1 = P1;
	Polynomial p2 = P2;
	Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Polynomial rear = P;
	Polynomial t;

	int sum = 0;

	while(p1 && p2)
	{
		if(p1->expo > p2->expo)
		{
			Attach(p1->coef, p1->expo, &rear);
			p1 = p1->link;
		} 
		else if(p1->expo < p2->expo)
		{
			Attach(p2->coef, p2->expo, &rear);
			p2 = p2->link;
		}
		else
		{
			sum = p1->coef + p2->coef;
			if(sum)
			{
				Attach(sum, p1->expo, &rear);
			}
			p1 = p1->link;
			p2 = p2->link;
		}
	}
	if(p1)
	{
		while(p1)
		{
			Attach(p1->coef, p1->expo, &rear);
			p1 = p1->link;
		}
	}else if(p2)
	{
		while(p2)
		{
			Attach(p2->coef, p2->expo, &rear);
			p2 = p2->link;
		}
	}

	t = P;
	P = P->link;
	free(t);

	return P;
}

Polynomial Multi(Polynomial P1, Polynomial P2)
{
	if(!P1 || !P2)
		return NULL;

	Polynomial p1 = P1;
	Polynomial p2 = P2;
	Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Polynomial rear = P;
	Polynomial t;

	int coef, expo;

	while(p2)
	{
		Attach(p1->coef*p2->coef, p1->expo+p2->expo, &rear);
		p2 = p2->link;
	}
	p1 = p1->link;
	while(p1)
	{
		p2 = P2;
		rear = P;
		while(p2)
		{
			expo = p1->expo + p2->expo;
			coef = p1->coef * p2->coef;
			while(rear->link && rear->link->expo > expo)
				rear = rear->link;
			if(rear->link && rear->link->expo == expo)
			{
				if(rear->link->coef + coef)
					rear->link->coef += coef;
				else
				{
					t = rear->link;
					rear->link = t->link;
					free(t);
				}
			}
			else
			{
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = coef;
				t->expo = expo;
				t->link = rear->link;
				rear->link = t;
				rear = rear->link;
			}
			p2 = p2->link;
		}
		p1 = p1->link;
	}
	t = P;
	P = P->link;
	free(t);

	return P;
}

void PrintPoly(Polynomial P)
{
	int flag = 0;
	if(!P)
		printf("0 0\n");
	else
	{
		while(P)
		{
			if(!flag)
				flag = 1;
			else
				printf(" ");
			printf("%d %d",P->coef, P->expo);
			P = P->link;
		}
		printf("\n");
	}
}
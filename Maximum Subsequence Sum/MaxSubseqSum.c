#include <stdio.h>
#include <stdlib.h>

int MaxSubseqSum(int A[], int N, int *first, int *last);

int main()
{
	int Num, MaxSum, i, first, last;
	scanf("%d", &Num);
	int* Numbers = (int*)malloc(sizeof(int)*Num);
	for(i=0; i<Num; ++i)
		scanf("%d", Numbers+i);
	MaxSum = MaxSubseqSum(Numbers, Num, &first, &last);
	printf("%d %d %d", MaxSum, first, last);
	free(Numbers);
	return 0;
}

int MaxSubseqSum(int A[], int N, int *first, int *last)
{
	int SumFlag, PreviousSum, ThisSum, MaxSum, i, FirstIndex, LastIndex;
	PreviousSum = -1;
	SumFlag = ThisSum = MaxSum = 0;
	for(i=0; i<N; ++i)
	{
		if(PreviousSum<0 && A[i]>=0)
			FirstIndex = i;
		ThisSum += A[i];
		PreviousSum = ThisSum;
		if(ThisSum < 0)
		{
			ThisSum = 0;
		}else if(ThisSum > MaxSum)
		{
			SumFlag = 1;
			MaxSum = ThisSum;
			*first = A[FirstIndex];
			*last = A[i];
		}else
		{
			SumFlag = 1;
			LastIndex = i;
		}
			
	}
	if(MaxSum == 0) 
	{
		if(SumFlag == 0)
		{
			*first = A[0];
			*last = A[N-1];	
		}else
		{
			*first = A[FirstIndex];
			*last = A[LastIndex];	
		}
	}
	return MaxSum;
}

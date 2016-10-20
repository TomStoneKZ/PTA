#include <stdio.h>
#include <stdlib.h>

int MaxSubseqSum(int A[], int N);

int main()
{
	int Num, MaxSum, i;
	scanf("%d", &Num);
	int* Numbers = (int*)malloc(sizeof(int)*Num);
	for(i=0; i<Num; ++i)
		scanf("%d", Numbers+i);
	MaxSum = MaxSubseqSum(Numbers, Num);
	printf("%d", MaxSum);
        free(Numbers);
	return 0;
}

int MaxSubseqSum(int A[], int N)
{
	int ThisSum, MaxSum, i;
        ThisSum = MaxSum = 0;
	for(i=0; i<N; ++i)
	{
		ThisSum += A[i];
		if(ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if(ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}

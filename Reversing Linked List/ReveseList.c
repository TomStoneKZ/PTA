#include <stdio.h>
#include <stdlib.h>

int list[100000];
int node[100000][2];

int main()
{

	int StartAddress, Address, NextAddress, TempAddress;
	int num, revertLength, data, round, n;
	scanf("%d %d %d", &StartAddress, &num, &revertLength);
 	n = num;
	while(n--)
	{
		scanf("%d %d %d", &Address, &data, &NextAddress);
		node[Address][0] = data;
		node[Address][1] = NextAddress;
	}

	int listIndex = 0;
	int nodeIndex = StartAddress;
	while(nodeIndex != -1)
	{
		list[listIndex] = nodeIndex;
		nodeIndex = node[nodeIndex][1];
		++listIndex;
	}

	round = listIndex/revertLength;

	int i, j, m;
	while(round--)
	{
		i = round*revertLength;
		j = (round+1)*revertLength-1;
		for(m=0; m<revertLength/2; ++m)
		{
			TempAddress = list[i+m];
			list[i+m] = list[j-m];
			list[j-m] = TempAddress;
		}
	}

	for(i=0; i<listIndex-1;++i)
	{
		printf("%05d %d %05d\n", list[i], node[list[i]][0], list[i+1]);
	}
	printf("%05d %d %d\n", list[i], node[list[i]][0], -1);


	return 0;
}

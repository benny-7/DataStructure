#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"


int *CreateArray(void)
{
	int i = 0;
	int *p = NULL;

	p = (int *)malloc(N*sizeof(int));
	if (!p) {
		printf("no memory \n");
		return NULL;
	}

	srand(time(NULL));
	for(i=0; i<N; i++) 
		*(p+i) = rand()%100;

	return p;
}

void FreeArray(int *pr)
{
	free(pr);
}

void ShowArray(int *pr, int lenth)
{
	int i = 0;

	for (i=0; i<lenth; i++)
		printf("%d, ", *(pr+i));
	printf("\n");
}

int OverturnArray(int *pr, int lenth)
{
	int i = 0, tmp = 0;
	int left = 0;
	int right = lenth - 1;

	if (!pr) {
		printf("pr is NULL \n");
		return -1;
	}

	while (left < right) {
		tmp = pr[left];
		pr[left] = pr[right];
		pr[right] = tmp;
		left ++;
		right --;
	}

	return 0;
}


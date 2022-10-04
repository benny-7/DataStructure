#include <stdio.h>
#include <stdlib.h>
#include "array.h"


int main(void)
{
	int *p = NULL;

	printf("test start: \n");
	p = CreateArray();
	if (!p) {
		printf("CreateArray faild \n");
		return -1;
	}

	ShowArray(p, N);
	OverturnArray(p, N);
	ShowArray(p, N);

	printf("test end \n");

	return 0;
}

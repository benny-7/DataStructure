#include <stdio.h>
#include "linklist.h"

int main(void)
{
	Linklist_t *phead = NULL;
	printf("test start: \n");
	LinkListCreate(&phead);
#if 0
	LinkListHeadInsert(phead, 40);
	LinkListHeadInsert(phead, 30);
	LinkListHeadInsert(phead, 20);
	LinkListHeadInsert(phead, 10);
	LinkListShow(phead);
#endif

#if 0
	LinkListTailInsert(phead, 10);
	LinkListShow(phead);
	LinkListTailInsert(phead, 20);
	LinkListShow(phead);
	LinkListTailInsert(phead, 30);
	LinkListShow(phead);
#endif

#if 1
	LinkListHeadInsert(phead, 40);
	LinkListHeadInsert(phead, 30);
	LinkListHeadInsert(phead, 20);
	LinkListIndexInsert(phead, 0, 15);
	LinkListShow(phead);
#endif

	LinkListFree(&phead);

	printf("test end \n");
	return 0;
}

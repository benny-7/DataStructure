#include <stdio.h>
#include "linklist.h"

int main(void)
{
	Linklist_t *phead = NULL;
	printf("test start: \n\n");
	LinkListInit(&phead);
	LinkListShow(phead);

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
	LinkListShow(phead);
	LinkListPosInsert(phead, 0, 5);
	LinkListShow(phead);
	LinkListPosInsert(phead, 2, 25);
	LinkListShow(phead);
	LinkListHeadDelete(phead);
	LinkListShow(phead);
#endif

#if 0
	LinkListTailInsert(phead, 10);
	LinkListTailInsert(phead, 20);
	LinkListTailInsert(phead, 30);
	LinkListTailInsert(phead, 40);
	LinkListShow(phead);
	LinkListTailDelete(phead);
	LinkListShow(phead);
	LinkListTailDelete(phead);
	LinkListShow(phead);
#endif

#if 0
	LinkListTailInsert(phead, 10);
	LinkListTailInsert(phead, 20);
	LinkListTailInsert(phead, 30);
	LinkListTailInsert(phead, 40);
	LinkListShow(phead);
	LinkListPosDelete(phead, 3);
	LinkListShow(phead);
	LinkListPosDelete(phead, 0);
	LinkListShow(phead);
#endif

#if 0
	LinkListTailInsert(phead, 10);
	LinkListTailInsert(phead, 20);
	LinkListTailInsert(phead, 30);
	LinkListTailInsert(phead, 40);
	LinkListTailInsert(phead, 20);
	LinkListTailInsert(phead, 20);
	LinkListShow(phead);
	LinkListDataDelete(phead, 20);
	LinkListShow(phead);
	LinkListDataDelete(phead, 40);
	LinkListShow(phead);
	LinkListDataDelete(phead, 50);
	LinkListShow(phead);
#endif

#if 0
	LinkListTailInsert(phead, 10);
	LinkListTailInsert(phead, 20);
	LinkListTailInsert(phead, 30);
	LinkListTailInsert(phead, 40);
	LinkListShow(phead);
	LinkListPosChange(phead, 0, 5);
	LinkListShow(phead);
	LinkListPosChange(phead, 3, 35);
	LinkListShow(phead);
	LinkListPosChange(phead, 5, 55);
	LinkListShow(phead);
#endif

#if 0
int data = 0;
	LinkListTailInsert(phead, 10);
	LinkListTailInsert(phead, 20);
	LinkListTailInsert(phead, 30);
	LinkListTailInsert(phead, 40);
	LinkListShow(phead);
	LinkListIndexSearch(phead, 0, &data);
	printf("search index:0, data:%d \n", data);
	LinkListIndexSearch(phead, 3, &data);
	printf("search index:3, data:%d \n", data);
	LinkListIndexSearch(phead, 6, &data);
	printf("search index:6, data:%d \n", data);
#endif

#if 0
	int index = 0;
	LinkListTailInsert(phead, 10);
	LinkListTailInsert(phead, 20);
	LinkListTailInsert(phead, 30);
	LinkListTailInsert(phead, 40);
	LinkListShow(phead);
	LinkListDataSearch(phead, &index, 10);
	printf("search index:%d, data:10 \n", index);
	LinkListDataSearch(phead, &index, 40);
	printf("search index:%d, data:40 \n", index);
	LinkListDataSearch(phead, &index, 60);
	printf("search index:%d, data:60 \n", index);
#endif

	LinkListReverse(&phead);
	LinkListShow(phead);


	LinkListDestory(&phead);
	printf("test end \n");
	return 0;
}

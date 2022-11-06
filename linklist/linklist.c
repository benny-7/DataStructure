#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linklist.h"

/******************** basic start *************************/
void LinkListInit(Linklist_t **pl)
{
	int data = 0;

	if (!(*pl = (Linklist_t *)malloc(sizeof(Linklist_t)))) {
		printf("no memory !!! \n");
		return ;
	}

	(*pl)->next = NULL;

	printf("input data:\n");
	while (1) {
		scanf("%d", &data);
		if (data == -1)
			break;
		LinkListHeadInsert(*pl, data);
	}

	printf("Create Linklist success!!!\n");

	return;
}

void LinkListDestory(Linklist_t **pl)
{
	Linklist_t *pcur = NULL;
	if (!(*pl)) {
		printf("pl is NULL\n");
		return;
	}

/*
销毁链表需要需要连头节点一起删掉
*/
	while (*pl) {
		pcur = *pl;
		*pl = (*pl)->next;
		pcur->next = NULL;
		free(pcur);
		pcur = NULL;
	}

	printf("Destroy LinkList success!!! \n");
	return;
}

void LinkListClean(Linklist_t *pl)
{
	Linklist_t *pNode = pl;

	if (pl) {
		printf("head is NULL\n");
		return ;
	}
/*
清除链表，除了头节点其他节点都free
*/
	while (pNode) {
		pNode = pl->next;
		pl->next = pNode->next;
		pNode->next = NULL;
		free(pNode);
	}
	
	return ;
}


//   have head 
//add
// head insert
int LinkListHeadInsert(Linklist_t *pl, int data)
{
	Linklist_t *pnode;

	if (!pl) {
		printf("pl is NULL \n");
		return -1;
	}

	if (!(pnode = (Linklist_t *)malloc(sizeof(Linklist_t)))) {
		printf("no memory !!! \n");
		return -2;
	}
	pnode->data = data;
	pnode->next = pl->next;
	pl->next = pnode;

	return 0;
}

// tail insert
int LinkListTailInsert(Linklist_t *pl, int data)
{
	Linklist_t *pnode = NULL;

	if (!pl) {
		printf("pl is NULL \n");
		return -1;
	}

	while (pl->next) {
		pl = pl->next;
	}

	pnode = (Linklist_t *)malloc(sizeof(Linklist_t));
	if (!pnode) {
		printf("no memory !!! \n");
		return -2;
	}

	pnode->data = data;
	pnode->next = NULL;

	pl->next = pnode;
	return 0;
}

// index insert
int LinkListPosInsert(Linklist_t *pl, int index, int data)
{
	int count = 0;
	Linklist_t *pNew = NULL;
	Linklist_t *pPer = NULL;
	Linklist_t *pCur = NULL;

	if ((!pl) || index < 0) {
		printf("pl is NULL, index:%d \n", index);
		return -3;
	}

	pPer = pl;
	pCur = pl->next;
	while (pCur && count < index) {
		pCur= pCur->next;
		pPer = pPer->next;
		count++;
	}

	if (count < index) {
		printf("index invalid, Max index is %d\n", count);
		return -1;
	}

	pNew = (Linklist_t *)malloc(sizeof(Linklist_t));
	if (!pNew) {
		printf("no memory !!! \n");
		return -2;
	}
	pNew->data = data;
	pNew->next = pPer->next;
	pPer->next = pNew;

	return 0;
}

//delete
// head delete
int LinkListHeadDelete(Linklist_t *pl)
{
	Linklist_t *pCur = NULL;

	if (!pl) {
		printf("pl is NULL \n");
		return -1;
	}

	if (pl->next) {
		pCur = pl->next;
		pl->next = pl->next->next;
		pCur->next = NULL;
		free(pCur);
		pCur = NULL;
	} else {
		printf("pl have no node \n");
	}

	return 0;
}

// tail delete
int LinkListTailDelete(Linklist_t *pl)
{
	Linklist_t *pre = pl;
	Linklist_t *pCur = NULL;

	if (!pre) {
		printf("pl is NULL \n");
		return -1;
	}

	pCur = pre->next;
	while (pCur->next) {
		pre = pCur;
		pCur = pCur->next;
	}

	pre->next = NULL;
	free(pCur);
	pCur = NULL;	

	return 0;
}

// index delete
int LinkListPosDelete(Linklist_t *pl, int index)
{
	Linklist_t *pPre = pl;
	Linklist_t *pCur = NULL;
	int count = 0;

	if (!pPre) {
		printf("pl is NULL \n");
		return -1;
	}

	pCur = pPre->next;
	while (pCur && (count < index)) {
		pPre = pPre->next;
		pCur = pCur->next;
		count++;
	}

	if (count < index) {
		printf("index invalid, Max index is %d\n", count);
		return -1;
	}
	
	pPre->next = pCur->next;
	pCur->next = NULL;
	free(pCur);
	pCur = NULL;

	return 0;
}

// ***** delete
int LinkListDataDelete(Linklist_t *pl, int data)
{
	Linklist_t *pre = pl;
	Linklist_t *pcur = NULL;

	if (!pre) {
		printf("pl is NULL \n");
		return -1;
	}

	pcur = pl->next;
	while(pcur) {
 		if (data == pcur->data) {
			pre->next = pcur->next;
			pcur->next = NULL;
			free(pcur);
			pcur = pre->next;
			continue;
		}
		pre = pcur;
		pcur = pcur->next;
	}
 
	return 0;
}


//change
// index change
int LinkListPosChange(Linklist_t *pl, int index, int data)
{
	Linklist_t *pcur = NULL;
	int count = 0;

	if (!pl) {
		printf("pl is NULL \n");
		return -1;
	}

	pcur = pl->next;
	while (pcur && (count < index)) {
		pcur = pcur->next;
		count ++;
	}

	if (index == count) {
		pcur->data = data;
	} else {
		printf("index invalid, Max index is %d\n", count);
		return -1;
	}
	
	return 0;
}

//search
int LinkListIndexSearch(Linklist_t *pl, int index, int* pdata)
{
	Linklist_t *pcur = NULL;
	int count = 0;

	if (!pl) {
		printf("pl is NULL \n");
		return -1;
	}

	*pdata = -1;
	pcur = pl->next;
	while (pcur) {
		if (index == count) {
			*pdata = pcur->data;
			break;
		}
		pcur = pcur->next;
		count++;
	}

	return 0;
}

int LinkListDataSearch(Linklist_t *pl, int *ppos, int data)
{
	Linklist_t *pcur = NULL;
	int count = 0;

	if (!pl) {
		printf("pl is NULL \n");
		return -1;
	}

	*ppos = -1;//default
	pcur = pl->next;
	while (pcur) {
		if (data == pcur->data) {
			*ppos = count;
			break;
		}
		pcur = pcur->next;
		count ++;
	}

	return 0;
}
/******************** basic end *************************/

//order

/******************** general *************************/
void LinkListShow(Linklist_t *pl)
{
	if (!pl) {
		printf("pl is NULL \n");
		return;
	}

	printf("head->");
	while (pl->next) {
		pl = pl->next;
		printf("%02d->", pl->data);
	}
	printf("N \n");
}

int LinkListGetLength(Linklist_t *pl)
{
	int length = -1;

	if (pl) {
		printf("pl is NULL \n");
		return -1;
	}

	while (pl) {
		pl = pl->next;
		length++;
	}

	return length;
}

/******************* general end ************************/

/******************* app start ************************/
/*判断是否有环，如果有环返回环入口，否则返回NULL*/
int LinkListIsRing(Linklist_t *pl, Linklist_t *pEntrance)
{
	Linklist_t *pFast = pl;
	Linklist_t *pSlow = pl;

	if (pl) {
		printf("pl is NULL \n");
		return -1;
	}
	/*如果有环，快指针一定会追上慢指针*/
	while (pFast->next && pFast->next->next) {
		if (pFast == pSlow) {
			break;
		}
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	/*推出上一个while的条件是fast指向NULL,说明无环*/
	if (pFast->next || pFast->next->next) {
		pEntrance = NULL;
		return 0;
	}
	/*
	参考链接：https://www.nowcoder.com//questionTerminal/253d2c59ec3e4bc68da16833f79a38e4
	通过推导结论是：起点到入口的距离等于环内相遇的点到环入口的距离
	*/
	pFast = pl->next;
	while (pFast != pSlow) {
		pFast = pFast->next;
		pSlow = pSlow->next;
	}
	pEntrance = pSlow;

	return 1;
}

int LinkListRingLength(Linklist_t *pl)
{
	Linklist_t Entrance;
	Linklist_t *pCur = pl->next;
	int length = 0;

	if (LinkListIsRing(pl, &Entrance)) {
		while (pCur != &Entrance) {
			pCur = pCur->next;
		}
	}

	pCur = pCur->next;
	length ++;
	while (pCur != &Entrance) {
		pCur = pCur->next;
		length ++;
	}

	return length;
}

int LinkListReverse(Linklist_t **pl)
{

	if (!pl || !(*pl)) {
		printf("pl is NULL \n");
		return -1;
	}
	/*从旧链表上取节点头插到新链表上*/
	Linklist_t *pCur = (*pl)->next;
	Linklist_t *pNode;

	(*pl)->next = NULL;
	while (pCur) {
		pNode = pCur;
		pCur = pCur->next;

		pNode->next = (*pl)->next;
		(*pl)->next = pNode;
	}

	return 0;
}

/******************* app end *************************/


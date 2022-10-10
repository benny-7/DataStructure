#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linklist.h"

void LinkListCreate(Linklist_t **pl)
{
	if (!(*pl = (Linklist_t *)malloc(sizeof(Linklist_t)))) {
		printf("no memory !!! \n");
		return ;
	}

	(*pl)->next = NULL;
	(*pl)->data = -1;

	return;
}

void LinkListFree(Linklist_t **pl)
{
	if (!(*pl)) {
		printf("pl is NULL\n");
		return;
	}

	free(*pl);
	*pl = NULL;
	return;
}

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
int LinkListIndexInsert(Linklist_t *pl, int index, int data)
{
	int count = 0;
	Linklist_t *pnode = NULL;
	Linklist_t *pcur = NULL;

	if ((!pl) || index < 0) {
		printf("pl is NULL, index:%d \n", index);
		return -3;
	}

	pcur = pl;
	while ((count < index) && pcur->next) {
		pcur= pcur->next;
		count++;
	}

	if (count < index) {
		printf("index invalid, Max index is %d\n", count);
		return -1;
	}

	pnode = (Linklist_t *)malloc(sizeof(Linklist_t));
	if (!pnode) {
		printf("no memory !!! \n");
		return -2;
	}
	pnode->data = data;
	pnode->next = pcur->next;
	pcur->next = pnode;
	
	return 0;
}

//delete
// head delete
int LinkListHeadDelete(Linklist_t *pl)
{
	Linklist_t *pcur = NULL;

	if (!pl) {
		printf("pl is NULL \n");
		return -1;
	}

	if (pl->next) {
		pcur = pl->next;
		pl->next = pl->next->next;

		free(pcur);
		pcur = NULL;
	} else {
		printf("pl have no node \n");
	}
	return 0;
}

// tail delete
int LinkListTailDelete(Linklist_t *pl)
{
	Linklist_t *pre = pl;
	Linklist_t *pnode = NULL;

	if (!pre) {
		printf("pl is NULL \n");
		return -1;
	}

	pnode = pre->next;
	while (pnode->next) {
		pre = pre->next;
		pnode = pnode->next;
	}

	pre->next = NULL;
	free(pnode);
	pnode = NULL;	

	return 0;
}

// index delete
int LinkListIndexDelete(Linklist_t *pl, int index)
{
	Linklist_t *pre = pl;
	Linklist_t *pnode = NULL;
	int count = 0;

	if (!pre) {
		printf("pl is NULL \n");
		return -1;
	}

	pnode = pre->next;
	while ((pnode->next) && (count < index)) {
		pre = pre->next;
		pnode = pnode->next;
		count ++;
	}

	if (count < index) {
		printf("index invalid, Max index is %d\n", count);
		return -3;
	}

	pre->next = pnode->next;
	pnode->next = NULL;
	free(pnode);
	pnode = NULL;
	return 0;
}

// data delete
int LinkListDataDelete(Linklist_t *pl, int data)
{
	Linklist_t *pre = pl;
	Linklist_t *pnode = NULL;

	if (!pre) {
		printf("pl is NULL \n");
		return -1;
	}

	pnode = pre->next;
	while(pnode->next) {
		if (data == pnode->data) 
			break;
		pre = pre->next;
		pnode = pnode->next;
	}

	if (data != pnode->data) {
		printf("%d not in the linklist\n", data);
		return -2;
	}

	pre->next = pnode->next;
	pnode->next = NULL;
	free(pnode);
	pnode = NULL;
	
	return 0;
}


//change
// index change
int LinkListIndexChange(Linklist_t *pl, int index, int data)
{
	Linklist_t *pnode = NULL;
	int count = 0;

	if (!pl) {
		printf("pl is NULL \n");
		return -1;
	}

	pnode = pl->next;
	while ((pnode->next) && (count < index)) {
		pnode = pnode->next;
		count ++;
	}

	if (count < index) {
		printf("index invalid, Max index is %d\n", count);
		return -3;
	}

	pnode->data = data;

	return 0;
}

//search
int LinkListIndexSearch(Linklist_t *pl, int index, int* pdata)
{
	Linklist_t *pnode = NULL;
	int count = 0;

	if (!pl) {
		printf("pl is NULL \n");
		return -1;
	}

	pnode = pl->next;
	while ((pnode->next) && (count < index)) {
		pnode = pnode->next;
		count ++;
	}

	if (count < index) {
		printf("index invalid, Max index is %d\n", count);
		*pdata = -1;
		return -3;
	}
	*pdata = pnode->data;

	return 0;
}

int LinkListDataSearch(Linklist_t *pl, int *ppos, int data)
{
	Linklist_t *pnode = NULL;
	int count = 0;

	if (!pl) {
		printf("pl is NULL \n");
		return -1;
	}

	pnode = pl->next;
	while (pnode->next) {
		if (data == pnode->data) 
			break;
		pnode = pnode->next;
		count ++;
	}

	if (data != pnode->data) {
		printf("%d not in the linklist\n", data);
		*ppos = -1;
		return -3;
	}
	*ppos = count;

	return 0;
}

//order




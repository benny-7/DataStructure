#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linklist.h"

void LinkListInit(Linklist_t **pl)
{
	if (!(*pl = (Linklist_t *)malloc(sizeof(Linklist_t)))) {
		printf("no memory !!! \n");
		return ;
	}

	(*pl)->next = NULL;
	(*pl)->data = -1;

	return;
}

void LinkListDestory(Linklist_t **pl)
{
	Linklist_t *pcur = NULL;
	if (!(*pl)) {
		printf("pl is NULL\n");
		return;
	}

	while ((*pl)->next) {
		pcur = (*pl)->next;
		(*pl)->next = (*pl)->next->next;
		pcur->next = NULL;
		free(pcur);
		pcur = NULL;
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
	Linklist_t *pper = NULL;
	Linklist_t *pcur = NULL;

	if ((!pl) || index < 0) {
		printf("pl is NULL, index:%d \n", index);
		return -3;
	}

	pper = pl;
	pcur = pl->next;
	while (pcur) {
		if (count == index) {
			pnode = (Linklist_t *)malloc(sizeof(Linklist_t));
			if (!pnode) {
				printf("no memory !!! \n");
				return -2;
			}
			pnode->data = data;
			pnode->next = pper->next;
			pper->next = pnode;
			break;
		}
		pcur= pcur->next;
		pper = pper->next;
		count++;
	}

	if (count < index) {
		printf("index invalid, Max index is %d\n", count);
		return -1;
	}

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
		pcur->next = NULL;

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
	Linklist_t *pcur = NULL;

	if (!pre) {
		printf("pl is NULL \n");
		return -1;
	}

	pcur = pre->next;
	while (pcur->next) {
		pre = pcur;
		pcur = pcur->next;
	}

	pre->next = NULL;
	free(pcur);
	pcur = NULL;	

	return 0;
}

// index delete
int LinkListIndexDelete(Linklist_t *pl, int index)
{
	Linklist_t *pre = pl;
	Linklist_t *pcur = NULL;
	int count = 0;

	if (!pre) {
		printf("pl is NULL \n");
		return -1;
	}

	pcur = pre->next;
	while (pcur) {
		if (count == index) {
			pre->next = pcur->next;
			pcur->next = NULL;
			free(pcur);
			pcur = pre->next;
			break;
		}
		pre = pcur;
		pcur = pcur->next;
		count++;
	}

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

	pcur = pre->next;
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
int LinkListIndexChange(Linklist_t *pl, int index, int data)
{
	Linklist_t *pcur = NULL;
	int count = 0;

	if (!pl) {
		printf("pl is NULL \n");
		return -1;
	}

	pcur = pl->next;
	while (pcur) {
		if (index == count) {
			pcur->data = data;
			break;
		}
		pcur = pcur->next;
		count ++;
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

//order




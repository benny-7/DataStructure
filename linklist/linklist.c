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
		printf("%d->", pl->data);
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

	while (pl->next) {
		pl = pl->next;
	}

	pnode = (Linklist_t *)malloc(sizeof(Linklist_t));
	if (!pnode) {
		printf("no memory !!! \n");
		return -1;
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
	}

	pcur = pl;
	while ((count < index) && pcur->next) {
		pcur= pcur->next;
		count++;
	}

	if (count < index) {
		printf("index invalid, Max index is %d\n", count);
		return -2;
	}

	pnode = (Linklist_t *)malloc(sizeof(Linklist_t));
	if (!pnode) {
		printf("no memory !!! \n");
		return -1;
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
	return 0;
}

// tail delete
int LinkListTailDelete(Linklist_t *pl)
{
	return 0;
}

// index delete
int LinkListIndexDelete(Linklist_t *pl, int index)
{
	return 0;
}

// data delete
int LinkListDataDelete(Linklist_t *pl, int data)
{
	return 0;
}


//change
// index change
int LinkListIndexChange(Linklist_t *pl, int index, int data)
{
	return 0;
}

// data change
int LinkListDataChange(Linklist_t *pl, int data)
{
	return 0;
}


//search
int LinkListIndexSearch(Linklist_t *pl, int index)
{
	return 0;
}

int LinkListDataSearch(Linklist_t *pl, int data)
{
	return 0;
}






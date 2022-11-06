#ifndef __LINKLIST_H_
#define __LINKLIST_H_

typedef struct LinkList {
	int data;
	struct LinkList *next;
}Linklist_t;

void LinkListInit(Linklist_t **pl);
void LinkListDestory(Linklist_t **pl);
void LinkListClean(Linklist_t *pl);

void LinkListShow(Linklist_t *pl);
int LinkListGetLength(Linklist_t *pl);

//   have head
//add
// head insert
int LinkListHeadInsert(Linklist_t *pl, int data);
// tail insert
int LinkListTailInsert(Linklist_t *pl, int data);
// position insert
int LinkListPosInsert(Linklist_t *pl, int index, int data);

//delete
// head delete
int LinkListHeadDelete(Linklist_t *pl);
// tail delete
int LinkListTailDelete(Linklist_t *pl);
// position delete
int LinkListPosDelete(Linklist_t *pl, int index);
// data delete
int LinkListDataDelete(Linklist_t *pl, int data);

//change
// index change
int LinkListPosChange(Linklist_t *pl, int index, int data);

//search
int LinkListIndexSearch(Linklist_t *pl, int index, int* pdata);
int LinkListDataSearch(Linklist_t *pl, int *ppos, int data);


//app
int LinkListIsRing(Linklist_t *pl, Linklist_t *pEntrance);
int LinkListRingLength(Linklist_t *pl);
int LinkListReverse(Linklist_t **pl);

//   no head
//add
//delete
//amend
//search

//   classic subject

#endif

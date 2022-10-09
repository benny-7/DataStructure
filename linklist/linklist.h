#ifndef __LINKLIST_H_
#define __LINKLIST_H_

typedef struct LinkList {
	int data;
	struct LinkList *next;
}Linklist_t;

void LinkListCreate(Linklist_t **pl);
void LinkListFree(Linklist_t **pl);

void LinkListShow(Linklist_t *pl);
//   have head
//add
// head insert
int LinkListHeadInsert(Linklist_t *pl, int data);
// tail insert
int LinkListTailInsert(Linklist_t *pl, int data);
// index insert
int LinkListIndexInsert(Linklist_t *pl, int index, int data);

//delete
// head delete
int LinkListHeadDelete(Linklist_t *pl);
// tail delete
int LinkListTailDelete(Linklist_t *pl);
// index delete
int LinkListIndexDelete(Linklist_t *pl, int index);
// data delete
int LinkListDataDelete(Linklist_t *pl, int data);

//change
// index change
int LinkListIndexChange(Linklist_t *pl, int index, int data);
// data change
int LinkListDataChange(Linklist_t *pl, int data);

//search
int LinkListIndexSearch(Linklist_t *pl, int index);
int LinkListDataSearch(Linklist_t *pl, int data);


//   no head
//add
//delete
//amend
//search

//   classic subject

#endif

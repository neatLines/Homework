#include <stdio.h>
typedef struct LNode {
	int Data;
	LNode next;
} LNode,*LinkList;

LNode twoToOne(LinkList A, LinkList B) {
	LinkList ret = (LinkList)malloc(sizeof(LNode));
	LNode re = ret;
	while(A->next!=NULL&&B->next!=NULL) {
		if(A->Data<B->Data) {
			ret->Data = A->Data;
		} else {
			ret->Data = B->Data;	
		}
		ret->next = (LinkList)malloc(sizeof(LNode));
		ret = ret->next;
		ret->next = NULL;
	}

	while(A->next!=NULL) {
		ret->Data = A->Data;
		ret->next = (LinkList)malloc(sizeof(LNode));
		ret = ret->next;
		ret->next = NULL;
	}

	while(B->next!=NULL) {
		ret->Data = A->Data;
		ret->next = (LinkList)malloc(sizeof(LNode));
		ret = ret->next;
		ret->next = NULL;
	}
}

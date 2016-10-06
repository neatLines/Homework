#include <stdio.h>
typedef struct LNode {
	int Data;
	LNode next;
} LNode,*LinkList;

LNode linkNode(*LinkList ha, *LinkList hb, int m, int n) {
	*LinkList temp = ha;
	if(m < n) {
		ha = hb;
		hb = temp;
	}
	temp = hb;
	while (hb->next!=NULL) {
		hb = hb->next;
	}
	hb->next = ha->next;
	free(ha);
	return temp;
}

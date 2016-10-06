#include <stdio.h>
typedef struct LNode {
	int Data;
	LNode next;
}

LNode changeList(*LinkList head) {
	LNode p = head;  
    LNode q = p.next;
	LNode r;
    while(q != null){  
		r = q.next;
		q.next = p;  
		p = q;  
		q = r;  
	}  
	head.next = null;  
	head = p;  
	return head;
}

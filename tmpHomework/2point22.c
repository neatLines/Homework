#include <stdio.h>
typedef struct LNode {	//定义节点
	int Data;
	LNode next;
}

LNode changeList(*LinkList head) {//逆序
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

int main()
{
	LinkList ll = (LinkList)malloc(sizeof(LNode));
	LNode temp;
	temp = (LNode)malloc(sizeof(LNode));
	ll->next=temp;
	temp->Data=1;
	temp->next=(LNode)malloc(sizeof(LNode));
	temp=temp->next;
	temp->data=10;
	temp->next=(LNode)malloc(sizeof(LNode));
	temp=temp->next;
	temp->data=100;
	temp->next=NULL;
	LinkList ge = changeList(ll);
}

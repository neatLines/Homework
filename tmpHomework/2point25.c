#include <stdio.h>
typedef struct LNode {//定义节点
	int Data;
	LNode next;
} LNode,*LinkList;
/*连接字符串
 *输入两字符串
 *输出连接后的链表头*/
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
int main()
{
	LinkList A = (LinkList)malloc(sizeof(LNode));
	LinkList B = (LinkList)malloc(sizeof(LNode));
	LinkList C = (LinkList)malloc(sizeof(LNode));
	A->Data=1;
	A->next = (LNode)malloc(sizeof(LNode));
	A->next->Data=2;
	B->Data=2;
	B->next = (LNode)malloc(sizeof(LNode));
	B->Data=3;
	C=TwoToOne;
}

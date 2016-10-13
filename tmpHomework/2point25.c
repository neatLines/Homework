#include <stdio.h>
typedef struct LNode {//定义节点
	int Data;
	LNode next;
} LNode,*LinkList;
/*连接字符串
 *输入两字符串
 *输出连接后的链表头*/
LNode twoToOne(LinkList A, LinkList B) {
	LinkList ret = (LinkList)malloc(sizeof(LNode));//申请空间
	LNode re = ret;
	while(A->next!=NULL&&B->next!=NULL) {//AB都没完时
		if(A->Data<B->Data) {		//A的数据较小
			ret->Data = A->Data;
			A=A->next;		//A加入ret A后移一位
		} else {
			ret->Data = B->Data;	
			B=B->next;		//B加入ret B后移一位
		}
		ret->next = (LinkList)malloc(sizeof(LNode));
		ret = ret->next;
		ret->next = NULL;
	}

	while(A->next!=NULL) {			//A不为空
		ret->Data = A->Data;		//取A的数据
		ret->next = (LinkList)malloc(sizeof(LNode));
		ret = ret->next;		//ret分配空间并后移一位
		ret->next = NULL;		
		A = A->next;			//A后移一位
	}

	while(B->next!=NULL) {
		ret->Data = A->Data;		//逻辑同上一个while
		ret->next = (LinkList)malloc(sizeof(LNode));
		ret = ret->next;
		ret->next = NULL;
		B = B->next;
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

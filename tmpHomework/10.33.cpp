#include <malloc.h>
#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    struct Node * next;
}node,*pNode;
//建立单链表
pNode create_list(int n){
    int i=0;
    pNode head,p,temp;
    head = (pNode)malloc(sizeof(node));
    head->next = NULL;
    temp = head;
    for(;i<n;i++){
        p = (pNode)malloc(sizeof(node));
        p->next = NULL;
        printf("please input the data:");
        scanf("%d",&p->data);
        temp->next = p;
        temp = p;
    }
    return head;
}
//打印单链表
void print_list(pNode head){
    pNode p = head->next;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}
//取得从指针p开始的链表中记录的最小值
pNode getminkey(pNode p){
    pNode minp;
    minp = p;
    while(p->next){
        if((minp->data)>(p->next->data)){
            minp = p->next;//minp是较小值的指针
        }
        p = p->next;
    }
    return minp;//返回较小值的指针
}
//选择排序
void selectsort(pNode head){
    pNode j,i=head->next;
    int temp;
    for(;i->next!=NULL;i = i->next){
        j=getminkey(i);
        if(i->data != j->data){
            temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }
}
int main(){
    pNode temp,head;
    int number = 0;
    cout << "please input the count of number" << endl;
    cin >> number;

    head = create_list(number);//建立链表
    selectsort(head);//简单选择排序
    print_list(head);
    return 0;
}
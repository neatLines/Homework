//
//  main.cpp
//  test
//
//  Created by panis on 2016/9/26.
//  Copyright © 2016年 panis. All rights reserved.
//

#include <iostream>
#include<string.h>
#include <stack>
using namespace std;
typedef struct ListNode {
    int val;
    ListNode *next;
} Node, *LinkList;

Node* creatList(const int a[], int n) {
    Node *head,*nextPtr;
    head=nullptr;
    nextPtr=nullptr;
    for (int i =0; i < n; i++) {
        Node *tmp = new Node;
        tmp->val=a[i];
        tmp->next=nullptr;
        if (i==0) {
            head=nextPtr=tmp;
        } else {
            nextPtr->next = tmp;
            nextPtr = tmp;
        }
    }
    return head;
}

void printNodeList(LinkList list) {
    stack<int>nodes;
    Node* pNode = list;
    
    if (pNode==nullptr) {
        return;
    }
    
    while (pNode!=nullptr) {
        nodes.push(pNode->val);
        pNode = pNode->next;
    }
    while (!nodes.empty()) {
        cout << nodes.top();
        nodes.pop();
    }
}

Node *ListAdd(Node* L1, Node* L2)
{
    if(L1==NULL)
        return L2;
    if(L2==NULL)
        return L1;
    
    Node *ptr1 = L1, *ptr2 = L2, *ResultPtr=NULL, *TmpPtr=NULL;
    int carry = 0;
    
    Node *p_node = new Node();
    p_node->val = (L1->val+L2->val)%10;
    p_node->next = NULL;
    carry = (L1->val+L2->val)/10;
    ResultPtr = TmpPtr = p_node;
    TmpPtr->next = NULL;
    L1 = L1->next;
    L2 = L2->next;
    
    while(L1 && L2)
    {
        Node *pNode = new Node();
        TmpPtr->next = pNode;
        
        int tmp = L1->val+L2->val+carry;
        carry = tmp/10;
        pNode->val = tmp%10;
        pNode->next = NULL;
        
        TmpPtr = TmpPtr->next;
        L1 = L1->next;
        L2 = L2->next;
    }
    
    while(L1)
    {
        Node *pNode = new Node();
        TmpPtr->next = pNode;
        
        int tmp = L1->val+carry;
        carry = tmp/10;
        pNode->val = tmp%10;
        pNode->next = NULL;
        
        TmpPtr = TmpPtr->next;
        L1 = L1->next;
    }
    while(L2)
    {
        Node *pNode = new Node();
        TmpPtr->next = pNode;
        
        int tmp = L2->val+carry;
        carry = tmp/10;
        pNode->val = tmp%10;
        pNode->next = NULL;
        
        TmpPtr = TmpPtr->next;
        L2 = L2->next;
    }
    
    if(carry)
    {
        Node *pNode = new Node();
        TmpPtr->next = pNode;
        
        pNode->val = carry;
        pNode->next = NULL;
    }  
    
    return ResultPtr;  
}

int main()
{
    int a[4]={1,2,3,4};
    int b[3]={1,2,3};
    printNodeList(ListAdd(creatList(a, 4), creatList(b, 3)));
}

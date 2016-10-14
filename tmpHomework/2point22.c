//
//  main.cpp
//  homeworkcpp
//
//  Copyright © 2016年 panis. All rights reserved.
//
#include <iostream>

using namespace std;
//定义节点
template<typename T>
class Node
{
public:
    T Data;
    Node<T>* Next;
};


//链接两链表，
//链表1，链表2，链表1长度，链表2长度
Node<int>* linkNode(Node<int>* ha, Node<int>* hb, int m, int n) {
    Node<int>* temp = ha;
    if(m < n) {
        ha = hb;
        hb = temp;
    }
    temp = hb;
    while (hb->Next!=NULL) {
        hb = hb->Next;
    }
    hb->Next = ha->Next;
    free(ha);
    return temp;
}
//打印链表
void printList(Node<int> * hc)
{
    while (hc != nullptr)
    {
        cout << hc->Data << "  ";
        hc = hc->Next;
    }
}


int main()
{
    Node<int>* ha = new Node<int>();
    ha->Data = 1;
    ha->Next = new Node<int>();
    ha->Next->Data = 0;
    ha->Next->Next = NULL;
    Node<int>* hb = new Node<int>();
    hb->Data = 3;
    hb->Next = new Node<int>();
    hb->Next->Data = 4;
    hb->Next->Next = new Node<int>();
    hb->Next->Next->Data=2;
    hb->Next->Next->Next=NULL;
    Node<int>* hc = linkNode(ha,hb,2,3);
    printList(hc);
    
    
}

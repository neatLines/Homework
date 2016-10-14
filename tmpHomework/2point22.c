#include <iostream>

using namespace std;

template<typename T>
class Node
{
public:
    T Data;
    Node<T>* Next;
    Node<T>()
    {
        Next = nullptr;
    }
};
Node<int>* changeList(Node<int>* head) {//逆序
    Node<int>* p = head;
    Node<int>* q = p->Next;
    Node<int>* r;
    while(q != nullptr){
        r = q->Next;
        q->Next = p;
        p = q;
        q = r;
    }
    head->Next = nullptr;
    head = p;
    return head;
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
    Node<int>* hc = changeList(ha);
    printList(hc);
    
    
}

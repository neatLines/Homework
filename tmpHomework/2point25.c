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
/*连接字符串
 *输入两字符串
 *输出连接后的链表头*/
Node<int>* twoToOne(Node<int>* A, Node<int>* B) {
    Node<int>* ret = new Node<int>();//申请空间
    Node<int>* re = ret;
    while(A->Next!=nullptr&&B->Next!=nullptr) {//AB都没完时
        if(A->Data<B->Data) {		//A的数据较小
            ret->Data = A->Data;
            A=A->Next;		//A加入ret A后移一位
        } else {
            ret->Data = B->Data;
            B=B->Next;		//B加入ret B后移一位
        }
        ret->Next = new Node<int>();
        ret = ret->Next;
        ret->Next = NULL;
    }
    
    while(A!=NULL) {			//A不为空
        ret->Data = A->Data;		//取A的数据
        ret->Next = new Node<int>();
        ret = ret->Next;		//ret分配空间并后移一位
        ret->Next = NULL;
        A = A->Next;			//A后移一位
    }
    
    while(B!=NULL) {
        ret->Data = B->Data;		//逻辑同上一个while
        ret->Next = new Node<int>();
        ret = ret->Next;
        ret->Next = NULL;
        B = B->Next;
    }
    return re;
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
    Node<int>* hc = twoToOne(ha,hb);
    printList(hc);
    
    
}

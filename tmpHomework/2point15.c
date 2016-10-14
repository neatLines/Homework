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



Node<int>* linkNode(Node<int>* ha, Node<int>* hb, int m, int n) {
	Node<int>* temp = ha;
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
	hb->Date = 3;
	hb->Next = new Node<int>();
	hb->Next->Data = 4;
	hb->Next->Next = new Node<int>();
	hb->Next->Next->Data=2;
	hb->Next->Next->Next=NULL;
	Node<int>* hc = LinkNode(ha,hb,2,3);
	printList(hc);
	
	
}

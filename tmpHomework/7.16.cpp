#include <iostream>
#define MAX_VERTEX_NUM 10
using namespace std;
typedef struct ArcNode {    //·��
    int adjvex;		//·��ָ��
    ArcNode *nextArc;	//��һ��·��
    ArcNode *lastArc;	//��һ��·��
    int info;			//·����Ϣ
}ArcNode;

typedef struct Vnode {		//�ڵ�
    int data;			    //�ڵ���Ϣ
    ArcNode *firstArc;	    //�ڵ��һ��·��
    Vnode *nextVex;		    //��һ���ڵ�
    Vnode *lastVex;		    //��һ���ڵ�
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct {
    AdjList root;		//����ͼ
    int length;		//�ڵ����
}ALGraph;

class BaseGraph {		//������
private:

public:

    ALGraph alGraph;

    BaseGraph(){
        alGraph.root->nextVex=NULL;
    }
    void InsertVex(VNode *vNode,ALGraph *alGraph1) {	//����ڵ�
        cout << vNode->data << "���ڲ���" << endl;
        VNode *temp = alGraph.root;
        while (temp->nextVex!=NULL) {
            temp = temp->nextVex;
        }
        alGraph1->length++;
        temp[alGraph1->length] = *vNode;
    }
    void InsertArc(VNode *vNode, ArcNode *arcNode) {	//����·��
        cout <<"��" << vNode->data <<"ָ���" << arcNode->adjvex << "���ڵ��·�����ڼ���" << endl;
        ArcNode *temp;
        if (vNode->firstArc!=NULL) {
            temp = vNode->firstArc;
            while (temp->nextArc!=NULL) {
                temp=temp->nextArc;
            }
            temp->nextArc=arcNode;
            temp->nextArc->lastArc=temp;
        } else {
            vNode->firstArc=arcNode;
            vNode->firstArc->lastArc=NULL;
        }
    }
    void DeleteVex(VNode *vNode) {				//ɾ���ڵ�
        cout << "����ɾ��" + vNode->data << endl;
        vNode->lastVex->nextVex=vNode->nextVex;
    }
    void DeleteArc(ArcNode *w,ALGraph alGraph1) {	//ɾ��·��
        cout << "����ɾ��ָ��" << w->adjvex << "��·��" << endl;
        if (w->nextArc!=NULL) {
            w->lastArc->nextArc = w->nextArc;
        } else {
            for (int i = 0; i < alGraph1.length; ++i) {
                if (alGraph1.root[i].firstArc!=NULL) {
                    ArcNode *temp = NULL;
                    temp = alGraph1.root[i].firstArc;
                    while (temp!=w) {
                        temp=temp->nextArc;
                    }
                    if (temp->nextArc==w) {
                        if (temp->lastArc!=NULL) {
                            temp->lastArc->nextArc = NULL;
                        } else {
                            alGraph1.root[i].firstArc = NULL;
                        }
                    }
                }
            }
        }
    }
};

int main()
{
    VNode *vNode = new VNode;
    ArcNode *arcNode = new ArcNode;
    vNode->data=0;
    BaseGraph *graph = new BaseGraph();
    graph->InsertVex(vNode,&graph->alGraph);
    graph->InsertArc(vNode,arcNode);
    graph->DeleteArc(arcNode,graph->alGraph);
    graph->DeleteVex(vNode);
    return 0;
}

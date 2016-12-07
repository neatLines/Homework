#include <iostream>
#define MAX_VERTEX_NUM 10
using namespace std;
typedef struct ArcNode {    //路径
    int adjvex;		//路径指向
    ArcNode *nextArc;	//下一条路径
    ArcNode *lastArc;	//上一条路径
    int info;			//路径信息
}ArcNode;

typedef struct Vnode {		//节点
    int data;			    //节点信息
    ArcNode *firstArc;	    //节点第一条路径
    Vnode *nextVex;		    //下一个节点
    Vnode *lastVex;		    //上一个节点
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct {
    AdjList root;		//储存图
    int length;		//节点个数
}ALGraph;

class BaseGraph {		//方法类
private:

public:

    ALGraph alGraph;

    BaseGraph(){
        alGraph.root->nextVex=NULL;
    }
    void InsertVex(VNode *vNode,ALGraph *alGraph1) {	//插入节点
        cout << vNode->data << "正在插入" << endl;
        VNode *temp = alGraph.root;
        while (temp->nextVex!=NULL) {
            temp = temp->nextVex;
        }
        alGraph1->length++;
        temp[alGraph1->length] = *vNode;
    }
    void InsertArc(VNode *vNode, ArcNode *arcNode) {	//插入路径
        cout <<"从" << vNode->data <<"指向第" << arcNode->adjvex << "个节点的路径正在加入" << endl;
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
    void DeleteVex(VNode *vNode) {				//删除节点
        cout << "正在删除" + vNode->data << endl;
        vNode->lastVex->nextVex=vNode->nextVex;
    }
    void DeleteArc(ArcNode *w,ALGraph alGraph1) {	//删除路径
        cout << "正在删除指向" << w->adjvex << "的路径" << endl;
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

#include <malloc.h>
#include <iostream>
using namespace std;
#define MAX_VERTEX_NUM 100
bool visit[MAX_VERTEX_NUM];
int nibolan[MAX_VERTEX_NUM+1];
char c[MAX_VERTEX_NUM];
typedef struct ArcNode{
    int adjvex;                      //�û���ָ��Ķ����λ��
    struct ArcNode *nextarc;         //ָ����һ������ָ��
    int *info;                         //�û������Ϣ��ָ��
}ArcNode;
typedef struct VNode{
    string data;                         //������Ϣ
    ArcNode *firstarc;                  //ָ���һ�������ö���Ļ���ָ��
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;                    //ͼ�ĵ�ǰ�������ͻ���
}ALGraph;



int LocateVex(ALGraph G,string u) {
    int i = 0;
    for(i=1;i<=G.vexnum;i++) {
        if(G.vertices[i].data.compare(u))
            return i;
    }
    return 0;
}

void CreateALGraph(ALGraph *G)
{
    int i=0, j=0;
    string v1,v2;
    ArcNode *p;
    cout<<"�����붥�����ͱ�����";
    cin>>(*G).vexnum>>(*G).arcnum;
    cout<<"����������㣺"<<endl;
    for(int i=1;i<=(*G).vexnum;i++) {
        cin>>(*G).vertices[i].data;
        (*G).vertices[i].firstarc=NULL;
    }
    for(int k=1;k<=(*G).arcnum;k++)                   //��ȡ���������ڽӱ�
    {
        cout<<"�����뻡���������㣺"<<endl;
        cin>>v2>>v1;
        i=LocateVex(*G,v1);
        j=LocateVex(*G,v2);
        if(!i||!j)                                //��֤����������
            return;
        p=(ArcNode *)malloc(sizeof(ArcNode));
        if(!p)
            exit(-1);
        p->adjvex=j;
        p->nextarc=NULL;
        if((*G).vertices[i].firstarc == NULL)                             //�ڽӱ��е�һ���ڵ�
            (*G).vertices[i].firstarc=p;              //���뵽�ڽӱ�
        else
            (*G).vertices[i].firstarc->nextarc=p;
    }

}
void printALGraph(ALGraph G)                           //�������ͼ
{
    ArcNode *p;
    for(int i=1;i<=G.vexnum;i++)
    {
        cout<<G.vertices[i].data<<"->";
        p=G.vertices[i].firstarc;
        while(p)
        {
            cout<<G.vertices[p->adjvex].data;
            p=p->nextarc;
        }
        cout<<endl;
    }
}

string getNiBoLan(ALGraph graph,VNode vNode) {
    if (vNode.firstarc==NULL) {
        return vNode.data;
    }
    return getNiBoLan(graph,graph.vertices[vNode.firstarc->adjvex])+getNiBoLan(graph,graph.vertices[vNode.firstarc->nextarc->adjvex])+vNode.data;
}

int main()
{
    ALGraph G;
    int i;
    CreateALGraph(&G);
    printALGraph(G);

    cout<<"�˱��ʽ�ĵ��沨��ʽΪ��";
    cout << getNiBoLan(G,G.vertices[0]);
    return 0;
}

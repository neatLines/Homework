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
    char data;                         //������Ϣ
    ArcNode *firstarc;                  //ָ���һ�������ö���Ļ���ָ��
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;                    //ͼ�ĵ�ǰ�������ͻ���
}ALGraph;
int LocateVex(ALGraph G,char u)            //��λ
{
    int i;
    for(i=1;i<=G.vexnum;i++)
    {
        if(G.vertices[i].data==u)
            return i;
    }
    return 0;
}
void CreateALGraph(ALGraph *G)
{
    int i,j,k;
    char v1,v2;
    ArcNode *p;
    ArcNode *r[MAX_VERTEX_NUM+1];               //��Ϊ���ʱ��������λ
    cout<<"�����붥�����ͱ�����";
    cin>>(*G).vexnum>>(*G).arcnum;
    cout<<"����������㣺"<<endl;
    for(i=1;i<=(*G).vexnum;i++)
    {
        cin>>(*G).vertices[i].data;
        (*G).vertices[i].firstarc=NULL;
        r[i]=NULL;
    }
    for(k=1;k<=(*G).arcnum;k++)                   //��ȡ���������ڽӱ�
    {
        cout<<"�����뻡���������㣺"<<endl;
        cin>>v1>>v2;
        i=LocateVex(*G,v1);
        j=LocateVex(*G,v2);
        if(!i||!j)                                //��֤����������
            return;
        p=(ArcNode *)malloc(sizeof(ArcNode));
        if(!p)
            exit(-1);
        p->adjvex=j;
        p->nextarc=NULL;
        if(r[i]==NULL)                             //�ڽӱ��е�һ���ڵ�
            (*G).vertices[i].firstarc=p;              //���뵽�ڽӱ�
        else
            r[i]->nextarc=p;
        r[i]=p;
    }

}
void printALGraph(ALGraph G)                           //�������ͼ
{
    int i,j;
    ArcNode *p;
    for(i=1;i<=G.vexnum;i++)
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
void creat(ALGraph G,int w)
{
    ArcNode *r;
    for(r=G.vertices[w].firstarc;r;r=r->nextarc)
        creat(G,r->adjvex);
    if(!r)
    {
        nibolan[0]++;
        nibolan[nibolan[0]]=w;
    }
}
void creatSign(ALGraph G)
{
    int k;
    for(k=1;k<=G.vexnum;k++)
        cin>>c[k];
}
int main()
{
    ALGraph G;
    int i;
    CreateALGraph(&G);
    printALGraph(G);
    creatSign(G);
    cout<<endl;
    creat(G,2);
    cout<<"�˱��ʽ�ĵ��沨��ʽΪ��";
    for(i=1;i<=nibolan[0];i++)
        cout<<c[nibolan[i]];
    cout<<endl;
    return 0;
}

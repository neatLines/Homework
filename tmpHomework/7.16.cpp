#include <malloc.h>
#include <iostream>
using namespace std;
#define MAX_VERTEX_NUM 100
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
void CreateALGraph(ALGraph *G)
{
    int i,j,k;
    ArcNode *e;
    cout<<"�����붥�����ͱ�����"<<endl;
    cin>>G->vexnum>>G->arcnum;
    cout<<"�����붥���ַ���"<<endl;
    for(i=0;i<G->vexnum;i++)
    {
        cin>>G->vertices[i].data;
        G->vertices[i].firstarc=NULL;
    }
    for(k=0;k<G->arcnum;k++)
    {
        cout<<"�����(vi,vj)�ϵĶ�����ţ�"<<endl;
        cin>>i>>j;
        e=(ArcNode *)malloc(sizeof(ArcNode));
        e->adjvex=j;
        e->nextarc=G->vertices[i].firstarc;
        G->vertices[i].firstarc=e;
        e=(ArcNode *)malloc(sizeof(ArcNode));
        e->adjvex=i;
        e->nextarc=G->vertices[i].firstarc;
        G->vertices[i].firstarc=e;
    }
}
void InsertVex(ALGraph *G,char v)
{
    int i;
    i=G->vexnum;
    G->vertices[i].data=v;
    G->vertices[i].firstarc=NULL;
    G->vexnum++;
}
void InsertArc(ALGraph *G,char v,char w)
{
    ArcNode *e;
    int i;
    int v1,v2;
    v1=v2=-1;
    for(i=0;i<G->vexnum;i++)
    {
        if(G->vertices[i].data==v)
            v1=i;
        if(G->vertices[i].data==w)
            v2=i;
    }
    if(v1==-1||v2==-1)
        cout<<"�ڵ㲻����"<<endl;
    else
    {
        e=G->vertices[v1].firstarc;
        while((e)&&(e->adjvex!=v2))
            e=e->nextarc;
        if(!e)
        {
            e=(ArcNode *)malloc(sizeof(ArcNode));
            e->adjvex=v2;
            e->nextarc=G->vertices[v1].firstarc;
            G->vertices[v1].firstarc=e;
            e=(ArcNode *)malloc(sizeof(ArcNode));
            e->adjvex=v1;
            e->nextarc=G->vertices[v2].firstarc;
            G->vertices[v2].firstarc=e;
            G->arcnum++;
        }
    }
}
void DeleteVex(ALGraph *G,char v)
{
    ArcNode *p,*q;
    int i;
    int j;
    j=-1;
    for(i=0;i<G->vexnum;i++)
    {
        if(G->vertices[i].data==v)
            j=i;
    }
    if(j==-1)
            cout<<"�ڵ㲻����"<<endl;
    else
        {
            p=(*G).vertices[j].firstarc; /* ɾ����vΪ���ȵĻ���� */
            while(p)
            {
                q=p;
                p=p->nextarc;
                free(q);
                (*G).arcnum--; /* ������1 */
            }
            (*G).vexnum--; /* ��������1 */
            for(i=j;i<(*G).vexnum;i++) /* ����v����Ķ���ǰ�� */
                (*G).vertices[i]=(*G).vertices[i+1];
            for(i=0;i<(*G).vexnum;i++) /* ɾ����vΪ��ȵĻ��ұ�Ҫʱ�޸ı���Ķ���λ��ֵ */
            {
                p=(*G).vertices[i].firstarc; /* ָ���1������� */
                while(p) /* �л� */
                {
                if(p->adjvex==j)
                {
                    if(p==(*G).vertices[i].firstarc) /* ��ɾ����ǵ�1����� */
                    {
                    (*G).vertices[i].firstarc=p->nextarc;
                    free(p);
                    p=(*G).vertices[i].firstarc;
                    }
                    else
                    {
                    q->nextarc=p->nextarc;
                    free(p);
                    p=q->nextarc;
                    }
                }
                else
                {
                    if(p->adjvex>j)
                    p->adjvex--; /* �޸ı���Ķ���λ��ֵ(���) */
                    q=p;
                    p=p->nextarc;
                }
                }
            }
        }
}
void DeleteArc(ALGraph *G,char v,char w)
{
    int i,j,k;
    ArcNode *p,*q;
    i=-1;
    j=-1;
    for(k=0;k<G->vexnum;k++)
    {
        if(G->vertices[k].data==v)
            i=k;
        if(G->vertices[k].data==w)
            j=k;
    }
    if(i==-1||j==-1)
        cout<<"�ڵ㲻����"<<endl;
    else{
        p=(*G).vertices[i].firstarc; /* pָ�򶥵�v�ĵ�һ������ */
        while(p&&p->adjvex!=j) /* p��������ָ֮�����Ǵ�ɾ����<v,w> */
        { /* pָ����һ���� */
            q=p;
            p=p->nextarc;
        }
        if(p&&p->adjvex==j) /* �ҵ���<v,w> */
        {
            if(p==(*G).vertices[i].firstarc) /* p��ָ�ǵ�1���� */
                (*G).vertices[i].firstarc=p->nextarc; /* ָ����һ���� */
            else
                q->nextarc=p->nextarc; /* ָ����һ���� */
            free(p); /* �ͷŴ˽�� */
            (*G).arcnum--; /* ������1 */
        }
        p=(*G).vertices[j].firstarc; /* pָw�ĵ�һ������ */
        while(p&&p->adjvex!=i) /* p��������ָ֮�����Ǵ�ɾ����<w,v> */
        { /* pָ����һ���� */
            q=p;
            p=p->nextarc;
        }
        if(p&&p->adjvex==i) /* �ҵ���<w,v> */
        {
            if(p==(*G).vertices[j].firstarc) /* p��ָ�ǵ�1���� */
                (*G).vertices[j].firstarc=p->nextarc; /* ָ����һ���� */
            else
                q->nextarc=p->nextarc; /* ָ����һ���� */
            free(p); /* �ͷŴ˽�� */
        }
    }
}
void printALGraph(ALGraph G)
{
    int i=0;
    ArcNode *p;
    for(i=0;i<G.vexnum;++i)
        cout<<G.vertices[i].data<<" ";
    cout<<endl;
    for(i=0;i<G.vexnum;i++)
    {
        p=G.vertices[i].firstarc;
        while(p)
        {
            if(i<p->adjvex)
            {
                cout<<G.vertices[i].data<<"->"<<G.vertices[p->adjvex].data<<" ";
            }
            p=p->nextarc;
        }
        cout<<endl;
    }
}
int main()
{
    char v,w;
    ALGraph G;
    CreateALGraph(&G);
    printALGraph(G);
    cout<<"1.�����"<<endl;
    cout<<"2.���뻡"<<endl;
    cout<<"3.ɾ����"<<endl;
    cout<<"4.ɾ����"<<endl;
    int num;
    cout<<"��������Ҫ���в����ı�ţ�";
    cin>>num;
    switch(num)
    {
    case 1:
        cout<<"������Ҫ����ĵ㣺";
        cin>>v;
        InsertVex(&G,v);
        printALGraph(G);
        break;
    case 2:
        cout<<"������Ҫ����ıߵ��������㣺";
        cin>>v>>w;
        InsertArc(&G,v,w);
        printALGraph(G);
        break;
    case 3:
        cout<<"������Ҫɾ���ĵ㣺";
        cin>>v;
        DeleteVex(&G,v);
        printALGraph(G);
        break;
    case 4:
        cout<<"������Ҫɾ���Ļ����������㣺";
        cin>>v>>w;
        DeleteArc(&G,v,w);
        printALGraph(G);
        break;
    }
}

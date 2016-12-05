#include <malloc.h>
#include <iostream>
using namespace std;
#define MAX_VERTEX_NUM 100
typedef struct ArcNode{
    int adjvex;                      //该弧所指向的顶点的位置
    struct ArcNode *nextarc;         //指向下一条弧的指针
    int *info;                         //该弧相关信息的指针
}ArcNode;
typedef struct VNode{
    char data;                         //顶点信息
    ArcNode *firstarc;                  //指向第一条依附该顶点的弧的指针
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;                    //图的当前顶点数和弧数
}ALGraph;
void CreateALGraph(ALGraph *G)
{
    int i,j,k;
    ArcNode *e;
    cout<<"请输入顶点数和边数："<<endl;
    cin>>G->vexnum>>G->arcnum;
    cout<<"请输入顶点字符："<<endl;
    for(i=0;i<G->vexnum;i++)
    {
        cin>>G->vertices[i].data;
        G->vertices[i].firstarc=NULL;
    }
    for(k=0;k<G->arcnum;k++)
    {
        cout<<"输入边(vi,vj)上的顶点序号："<<endl;
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
        cout<<"节点不存在"<<endl;
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
            cout<<"节点不存在"<<endl;
    else
        {
            p=(*G).vertices[j].firstarc; /* 删除以v为出度的弧或边 */
            while(p)
            {
                q=p;
                p=p->nextarc;
                free(q);
                (*G).arcnum--; /* 弧数减1 */
            }
            (*G).vexnum--; /* 顶点数减1 */
            for(i=j;i<(*G).vexnum;i++) /* 顶点v后面的顶点前移 */
                (*G).vertices[i]=(*G).vertices[i+1];
            for(i=0;i<(*G).vexnum;i++) /* 删除以v为入度的弧且必要时修改表结点的顶点位置值 */
            {
                p=(*G).vertices[i].firstarc; /* 指向第1条弧或边 */
                while(p) /* 有弧 */
                {
                if(p->adjvex==j)
                {
                    if(p==(*G).vertices[i].firstarc) /* 待删结点是第1个结点 */
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
                    p->adjvex--; /* 修改表结点的顶点位置值(序号) */
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
        cout<<"节点不存在"<<endl;
    else{
        p=(*G).vertices[i].firstarc; /* p指向顶点v的第一条出弧 */
        while(p&&p->adjvex!=j) /* p不空且所指之弧不是待删除弧<v,w> */
        { /* p指向下一条弧 */
            q=p;
            p=p->nextarc;
        }
        if(p&&p->adjvex==j) /* 找到弧<v,w> */
        {
            if(p==(*G).vertices[i].firstarc) /* p所指是第1条弧 */
                (*G).vertices[i].firstarc=p->nextarc; /* 指向下一条弧 */
            else
                q->nextarc=p->nextarc; /* 指向下一条弧 */
            free(p); /* 释放此结点 */
            (*G).arcnum--; /* 弧数减1 */
        }
        p=(*G).vertices[j].firstarc; /* p指w的第一条出弧 */
        while(p&&p->adjvex!=i) /* p不空且所指之弧不是待删除弧<w,v> */
        { /* p指向下一条弧 */
            q=p;
            p=p->nextarc;
        }
        if(p&&p->adjvex==i) /* 找到弧<w,v> */
        {
            if(p==(*G).vertices[j].firstarc) /* p所指是第1条弧 */
                (*G).vertices[j].firstarc=p->nextarc; /* 指向下一条弧 */
            else
                q->nextarc=p->nextarc; /* 指向下一条弧 */
            free(p); /* 释放此结点 */
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
    cout<<"1.插入点"<<endl;
    cout<<"2.插入弧"<<endl;
    cout<<"3.删除点"<<endl;
    cout<<"4.删除弧"<<endl;
    int num;
    cout<<"请输入你要进行操作的编号：";
    cin>>num;
    switch(num)
    {
    case 1:
        cout<<"请输入要插入的点：";
        cin>>v;
        InsertVex(&G,v);
        printALGraph(G);
        break;
    case 2:
        cout<<"请输入要插入的边的两个顶点：";
        cin>>v>>w;
        InsertArc(&G,v,w);
        printALGraph(G);
        break;
    case 3:
        cout<<"请输入要删除的点：";
        cin>>v;
        DeleteVex(&G,v);
        printALGraph(G);
        break;
    case 4:
        cout<<"请输入要删除的弧的两个顶点：";
        cin>>v>>w;
        DeleteArc(&G,v,w);
        printALGraph(G);
        break;
    }
}

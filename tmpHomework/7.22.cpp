#include <malloc.h>
#include <iostream>
using namespace std;
#define MAX_VERTEX_NUM 100
bool visit[MAX_VERTEX_NUM];
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
int FirstAdjVex(ALGraph G,int v)
 {
     ArcNode *p;
     int v1;
     v1=v;/* v1为顶点v在图G中的序号 */
     p=G.vertices[v1].firstarc;
   if(p)
     return p->adjvex;
   else
     return -1;
 }
int NextAdjVex(ALGraph G,int v,int w)
 {
     ArcNode *p;
     p=G.vertices[v].firstarc;
     if(!visit[p->adjvex])
        return p->adjvex;
     else{
        while(p->nextarc!=NULL){
            p=p->nextarc;
            if(!visit[p->adjvex])
                return p->adjvex;
        }
        return -1;
     }
 }
void DFS(ALGraph G,int v1)                /*从第v1个顶点出发递归地深度优先遍历图G*/
 {
     int w1;
     visit[v1]=true;
     for(w1=FirstAdjVex(G,v1);w1>=0;w1=NextAdjVex(G,v1,w1)){
        if(!visit[w1])
        {
            DFS(G,w1);
        }
     }
 }
bool Search(ALGraph G,int i,int j)
{
    DFS(G,i);
    if(visit[j]==true)
        return true;
    else
        return false;
}
int main()
{
    int v1,w1;
    ALGraph G;
    CreateALGraph(&G);
    printALGraph(G);
    for(int i=0;i<G.vexnum;i++)
    {
        visit[i]=false;
    }
    cout<<"请输入两个点的序号：";
    cin>>v1>>w1;
    if(Search(G,v1,w1)==true)
        cout<<"两点间存在路径"<<endl;
    else
        cout<<"两点间不存在路径"<<endl;
}

#include <iostream>
using namespace std;
#define MAX_VERTEX_NUM 100      //  最大的节点数为100
bool visit[MAX_VERTEX_NUM];     //  保存被访问过的节点
typedef struct ArcNode{         //  路径
    int adjvex;                 //  路径指向
    struct ArcNode *nextarc;    //  下一条路径
    int *info;                  //  路径信息
}ArcNode;
typedef struct VNode{           //  节点
    char data;                  //  节点信息
    ArcNode *firstarc;          //  节点的第一条指出路径
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct{                 //  图的结构体
    AdjList vertices;           //  保存节点信息
    int vexnum,arcnum;          //  保存节点数和路径数
}ALGraph;
void CreateALGraph(ALGraph *G) {//  创建图
    int i, j =0;
    ArcNode *e;
    cout<<"输入节点数和路径数"<<endl;
    cin>>G->vexnum>>G->arcnum;
    cout<<"输入节点名称"<<endl;
    for(int i=0;i<G->vexnum;i++) {
        cin>>G->vertices[i].data;
        G->vertices[i].firstarc=NULL;
    }
    for(int k=0;k<G->arcnum;k++) {
        cout<<"输入路径"<<endl;
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
void printALGraph(ALGraph G) {          //打印图
    ArcNode *p;
    for(int i=0;i<G.vexnum;++i)
        cout<<G.vertices[i].data<<" ";
    cout<<endl;
    for(int i=0;i<G.vexnum;i++) {
        p=G.vertices[i].firstarc;
        while(p) {
            if(i<p->adjvex) {
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
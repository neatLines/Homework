#include <malloc.h>
#include <iostream>
using namespace std;
#define MAX_VERTEX_NUM 100
bool visit[MAX_VERTEX_NUM];
int nibolan[MAX_VERTEX_NUM+1];
char c[MAX_VERTEX_NUM];
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
int LocateVex(ALGraph G,char u)            //定位
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
    ArcNode *r[MAX_VERTEX_NUM+1];               //作为访问标记用作定位
    cout<<"请输入顶点数和边数：";
    cin>>(*G).vexnum>>(*G).arcnum;
    cout<<"请输入各顶点："<<endl;
    for(i=1;i<=(*G).vexnum;i++)
    {
        cin>>(*G).vertices[i].data;
        (*G).vertices[i].firstarc=NULL;
        r[i]=NULL;
    }
    for(k=1;k<=(*G).arcnum;k++)                   //读取各边制作邻接表
    {
        cout<<"请输入弧的两个顶点："<<endl;
        cin>>v1>>v2;
        i=LocateVex(*G,v1);
        j=LocateVex(*G,v2);
        if(!i||!j)                                //保证有这两个点
            return;
        p=(ArcNode *)malloc(sizeof(ArcNode));
        if(!p)
            exit(-1);
        p->adjvex=j;
        p->nextarc=NULL;
        if(r[i]==NULL)                             //邻接表中第一个节点
            (*G).vertices[i].firstarc=p;              //加入到邻接表
        else
            r[i]->nextarc=p;
        r[i]=p;
    }

}
void printALGraph(ALGraph G)                           //输出有向图
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
    cout<<"此表达式的的逆波兰式为：";
    for(i=1;i<=nibolan[0];i++)
        cout<<c[nibolan[i]];
    cout<<endl;
    return 0;
}

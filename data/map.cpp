//
//  main.cpp
//  xuanzhi
//
//  Created by panis on 22/11/2016.
//  Copyright © 2016 panis. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#define MAXV 50
#define MaxSize 1000
#define INF 32767


using namespace std;


//邻接矩阵存储方法

typedef struct MGraph{
    int edges[MAXV][MAXV];
    int n;
} MGraph;



//迪杰斯特拉
int getLength(MGraph g,int e) {
    int length = 0;
    int dist[MAXV] = {0};
    int no[2] = {0};
    bool hadGot[MAXV] = {0};
    hadGot[e] = 1;
    for (int i = 0; i < g.n ; i++) {
        int temp = INF;
        for (int j = 0; j < g.n; j++) {
            if (hadGot[j]) {
                for (int k = 0; k < g.n; ++k) {
                    if ( temp > g.edges[j][k]&&!hadGot[k]) {
                        no[0]=j;
                        no[1]=k;
                        dist[k] = dist[j]+g.edges[j][k];
                        e = k;
                    }
                }
            }
        }
        hadGot[e]=1;
        dist[no[1]] = dist[no[0]] + g.edges[no[0]][no[1]];
    }
    for (int i = 0; i < g.n; i++) {
        length+=dist[i];
    }
    return length;
}


int getMinLength(MGraph g) {
    int minPoint = INF;
    int l = 0;
    for (int i = 0; i < g.n ; i++) {
        int tempLength = INF;

        tempLength = getLength(g,i);
        if (minPoint > tempLength) {
            minPoint = tempLength;
            l = i;
        }
    }
    return l;
}

//主函数
int main()
{
    int i,j,n;
    MGraph g;
    printf("请输入带权无向图的顶点个数：");//6
    while(scanf("%d",&n)!=EOF)
    {
        printf("请输入带权无向图的邻接矩阵：\n");
        /*
         32767 5 8 7 32767 3
         5 32767 4 32767 32767 32767
         8 4 32767 5 32767 9
         7 32767 5 32767 5 6
         32767 32767 32767 5 32767 1
         3 32767 9 6 1 32767
         */
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                cin >> g.edges[i][j];
            }
        }
        g.n=n;
        cout << ("采用迪杰斯特拉算法得到的地址为:") << getMinLength(g) << endl;
        
        printf("\n请输入带权无向图的顶点个数：");
    }
    return 0;
}

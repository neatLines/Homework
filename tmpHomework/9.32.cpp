#include <iostream>
using namespace std;
#define max 255
typedef struct tree {
    tree *lchild;
    tree *rchild;
    int data;
} *BiTree;


int last=0;
void MaxLT_MinGT(BiTree T,int x) {//找到二叉排序树T中小于x的最大元素和大于x的最小元素
    if(T->lchild) MaxLT_MinGT(T->lchild,x); //中序遍历
    if(last<x&&T->data>=x) //找到了小于x的最大元素
        printf("a=%d\n",last);
    if(last<=x&&T->data>x) //找到了大于x的最小元素
        printf("b=%d\n",T->data);
    last=T->data;
    if(T->rchild)
        MaxLT_MinGT(T->rchild,x);
}//MaxLT_MinGT


int main()
{
    BiTree biTree = (BiTree) malloc(sizeof(tree));
    biTree->data=5;
    BiTree biTree1 = (BiTree) malloc(sizeof(tree));
    biTree1->data=1;
    BiTree biTree2 = (BiTree) malloc(sizeof(tree));
    biTree2->data=7;
    biTree->lchild=biTree1;
    biTree->rchild=biTree2;
    MaxLT_MinGT(biTree,6);
}
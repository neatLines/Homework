//
//  huffman.cpp
//  hafman
//
//  Created by panis on 2016/11/10.
//  Copyright © 2016年 panis. All rights reserved.
//

#include "huffman.hpp"
CHuffmanTree::CHuffmanTree(int s[], const int len)
:pBuffer(NULL)
,pTree(NULL)
,m_iLength(0)
{
    assert(len>0);
    pBuffer=new int[len];
    int* p=pBuffer;
    for(int i=0;i<len;++i)
    {
        ITEM it;
        it.index=i;
        it.data=s[i];
        que.push_back(it);
        *(p+i)=s[i];
    }
    m_iLength=len;
    pTree=new TREE[2*len-1];
    InitTree();
}
CHuffmanTree::~CHuffmanTree()
{//回收内存
    if(pTree)
    {
        delete[] pTree;
        pTree=NULL;
    }
    if(pBuffer)
    {
        delete[] pBuffer;
        pBuffer=NULL;
    }
}
void CHuffmanTree::InitTree() const
{
    int* p=pBuffer;
    int i=0;
    for(;i<2*m_iLength-1;++i)
    {
        (pTree+i)->lChild=NULL;
        (pTree+i)->rChild=NULL;
        (pTree+i)->pParent=NULL;
        (pTree+i)->item.index=i;
    }
    for(i=0;i<m_iLength;++i)
        (pTree+i)->item.data=*(p+i);
    for(;i<2*m_iLength-1;++i)
        (pTree+i)->item.data=0;
}
void CHuffmanTree::ShowBuffer() const
{
    for(int i=0;i<m_iLength;++i)
        cout<<*(pBuffer+i)<<"   ";
    cout<<endl;
}
void CHuffmanTree::ShowTree() const
{
    cout<<"index         lChild        rChild        pParent       data"<<endl;
    for(int i=0;i<2*m_iLength-1;++i)
    {
        cout<<(pTree+i)->item.index<<"              ";
        if((pTree+i)->lChild)
            cout<<(pTree+i)->lChild->item.data<<"             ";
        else
            cout<<"0             ";
        if((pTree+i)->rChild)
            cout<<(pTree+i)->rChild->item.data<<"             ";
        else
            cout<<"0             ";
        if((pTree+i)->pParent)
            cout<<(pTree+i)->pParent->item.data<<"             ";
        else
            cout<<"0             ";
        cout<<(pTree+i)->item.data<<endl;
    }
    
}
void CHuffmanTree::Select(int& m,int& n)
{
    if(que.size()<2)
        return;
    SortDeque();
    //经过两次冒泡排序，最小的两个元素的索引当然是0和1了
    m=que.at(0).index;
    n=que.at(1).index;
    //出队列
    que.pop_front();
    que.pop_front();
}
void CHuffmanTree::SortDeque()
{
    if(que.empty())
        return;
    //两次冒泡排序就可以筛选出最小的两个了
    for(int i=0;i<2;++i)
    {
        for(int j=que.size()-1;j>i;--j)
        {
            if(que.at(j).data<que.at(j-1).data)
            {
                ITEM temp=que.at(j);
                que.at(j)=que.at(j-1);
                que.at(j-1)=temp;
            }
        }
    }
}
void CHuffmanTree::CreateHuffmanTree()
{
    for(int i=m_iLength;i<2*m_iLength-1;++i)
    {
        int m=0,n=0;
        Select(m,n);
        (pTree+m)->pParent=(pTree+i);
        (pTree+n)->pParent=(pTree+i);
        (pTree+i)->lChild=(pTree+m);
        (pTree+i)->rChild=(pTree+n);
        (pTree+i)->item.index=i;
        (pTree+i)->item.data=(pTree+m)->item.data+(pTree+n)->item.data;
        que.push_back((pTree+i)->item);//关键！产生的新节点一定要放入队列中
    }
}
void CHuffmanTree::ShowHuffmanCode()
{
    CreateHuffmanTree();//生成霍夫曼树
    for(int i=0;i<m_iLength;++i)
    {
        TREE* p=(pTree+i);
        string s="";
        while(p->pParent)
        {//我们约定左0，右1
            if(p->pParent->lChild->item.index==p->item.index)
                s+="0";
            else
                s+="1";
            p=p->pParent;
        }
        s=string(s.rbegin(),s.rend());//逆置
        cout<<(char)(pTree+i)->item.index<<"的编码为:"<<s<<endl;//打印每个元素的霍夫曼编码
    }
}

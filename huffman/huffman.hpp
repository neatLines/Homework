#include <assert.h>
#include <iostream>
#include <string>
#include <deque>
using namespace std;
/***************************************************************************/
/*
 对于一个给定的概率数组，所有元素之和为1，为了便于算法实现，我们扩大100倍
 选出序列中最小的两个元素，删除原序列中的这两个数，相加得到一个新的元素
 再把新得到的数放入序列中，重复上述过程
 规定：1、左孩子必须不大于右孩子节点的值；2、左边编码为0，右边为1
 ***************************************************************************/
typedef struct _ITEM
{
    int index;//元素在原来的数组中的索引值
    int data;//数据
}ITEM,*PITEM;
typedef struct _TREE
{
    _TREE* lChild;//指向左孩子
    _TREE* rChild;//指向右孩子
    _TREE* pParent;//指向父节点
    ITEM item;//当前节点的数据域
}TREE,*PTREE;
class CHuffmanTree
{
public:
    CHuffmanTree(int s[],const int len);
    virtual~ CHuffmanTree();
    //初始化树
    void InitTree()const;
    //打印输入的数据
    void ShowBuffer()const;
    //打印树
    void ShowTree()const;
    void ShowHuffmanCode();
protected:
    //对队列元素进行两次冒泡排序，以便选出最小的两个数
    void SortDeque();
    //选出队列中最小的两个元素构造新的树节点
    void Select(int& m,int& n);
    //构造哈弗曼树
    void CreateHuffmanTree();
private:
    int* pBuffer;//把元素复制到自己的内存里，指向首地址
    int m_iLength;//数组元素个数
    PTREE pTree;
    deque<ITEM> que;//双向队列，在这里面进行筛选最小的两个
};

#ifndef HUFFMAN_H
#define HUFFMAN_H

class HuffmanNode {
public:
    char info; //结点信息
    double weight; //结点权值
    int parent, lchild, rchild; //父亲结点，左右孩子结点
    HuffmanNode() {
        parent=lchild=rchild=-1;
    }
    HuffmanNode(const char &data, const double &wt, const int &pa=-1, const int &lch=-1, const int &rch=-1) {
        info=data;
        weight=wt;
        parent=pa;
        lchild=lch;
        rchild=rch;
    }
}; //class HuffmanNode end

class HuffmanTree {
public:
    HuffmanTree(const int &s=100) {
        maxSize=(s>100?s:100);
        arrayTree=new HuffmanNode[maxSize+1];

        currentSize=0;
        codeArray=0;
    }
    ~HuffmanTree() {
        delete[] arrayTree;
        if (codeArray!=0)
            delete[] codeArray;
    }
    void run();

private:
    HuffmanNode *arrayTree; //哈夫曼结点数组
    int maxSize; //数组最大值
    int currentSize; //当前数组大小
    void insert(const char&, const double&); //插入结点
    void createHuffmanTree(); //创建哈夫曼树
    void createHuffmanCode(); //创建哈夫曼编码
    int findPosition(const char &) const; //返回字符在arrayTree[]中的位置
    int getLongestCodeLength() const; //返回编码系统中长度最大的编码的位置
    int isEqual(const char *s) const; //判断s是否存在于编码系统中，若存在则返回s在编码系统中的位置，否则返回-1
    void print(); //打印huffman编码
private:
    class Code { //HuffmanTree的私有类，编码类
    public:
        Code():length(10) { ptr=new char[length]; }
        ~Code() { delete[] ptr; }
        char *ptr;
        const int length;
    };
    Code *codeArray; //数组大小为currentSize
    void reverse(char arr[]);
}; //class HuffmanTree end

#endif //huffman.h end
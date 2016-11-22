#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>
#include "huffman.h"
using namespace std;

void HuffmanTree::insert(const char &data, const double &wt) { //插入结点
    if (2*currentSize-1 >= maxSize) //叶子结点为n的哈夫曼树共有2n-1个结点
        return;
    arrayTree[currentSize].info=data;
    arrayTree[currentSize].weight=wt;
    currentSize++;
}

void HuffmanTree::reverse(char arr[]) { //反转字符串
    const int len=strlen(arr);
    char *p;
    p=new char[len+1];
    strcpy(p, arr);
    p[len]='\0';
    int k=0;
    for (int i=len-1; i>=0; i--)
        arr[i]=p[k++];
    arr[len]='\0';
    delete[] p;
}

int HuffmanTree::findPosition(const char &ch) const { //返回字符ch在arrayTree[]中的位置
    for (int i=0; i<currentSize; i++)
        if (arrayTree[i].info == ch)
            return i;
    return -1;
}

int HuffmanTree::getLongestCodeLength() const { //返回编码数组codeArray[]长度最长的编码的位置
    if (currentSize == 0)
        return -1;
    int len=strlen(codeArray[0].ptr);
    int i=1;
    while (i < currentSize) {
        int tmp=strlen(codeArray[i].ptr);
        if (tmp > len)
            len=tmp;
        i++;
    }
    return len;
}

int HuffmanTree::isEqual(const char *s) const { //判断s的编码是否存在，若存在返回编码在数组codeArray[]中的位置，否则返回-1
    for (int i=0; i<currentSize; i++)
        if (strlen(s) == strlen(codeArray[i].ptr)) //可以去掉此行
            if (strcmp(s, codeArray[i].ptr) == 0)
                return i;
    return -1;
}

void HuffmanTree::print() { //打印编码
    int k=0;
    while (k < currentSize) {
        cout<<arrayTree[k].info<<'('<<arrayTree[k].weight<<"): "<<codeArray[k].ptr<<endl;
        k++;
    }
}

void HuffmanTree::createHuffmanTree() { //构造huffmanTree
    int i=currentSize;
    int k;
    double wt1, wt2;
    int lnode, rnode;
    while (i < 2*currentSize-1) {
        wt1=wt2=numeric_limits<double>::max();
        k=0;
        while (k < i) {
            if (arrayTree[k].parent==-1) {
                if (arrayTree[k].weight<wt1) {
                    wt2=wt1;
                    rnode=lnode;
                    wt1=arrayTree[k].weight;
                    lnode=k;
                }
                else if (arrayTree[k].weight<wt2) {
                    wt2=arrayTree[k].weight;
                    rnode=k;
                }
            }
            k++;
        }
        arrayTree[i].weight = arrayTree[lnode].weight+arrayTree[rnode].weight;
        arrayTree[i].lchild=lnode;
        arrayTree[i].rchild=rnode;
        arrayTree[lnode].parent=arrayTree[rnode].parent=i;
        i++;
    }
}

void HuffmanTree::createHuffmanCode() { //构造huffmanCode，即哈夫曼编码
    codeArray=new Code[currentSize];
    int i=0;
    int k, n, m;
    cout << arrayTree[i].parent;

    while (i < currentSize) {
        k = arrayTree[i].parent;
        n=0;
        m=i;
        while (k!=-1 && k<currentSize*2-1) {
            if (arrayTree[k].lchild==m)
                codeArray[i].ptr[n++]='0';
            else if (arrayTree[k].rchild==m)
                codeArray[i].ptr[n++]='1';
            m=k;
            k=arrayTree[m].parent;
        }
        codeArray[i].ptr[n]='\0';
        reverse(codeArray[i].ptr); //反转字符串，使之变成正确的编码
        i++;
    }
}

void HuffmanTree::run() { //run函数的实现
    //打开main.cpp提供输入
    ifstream fileIn("/home/panis/ClionProjects/huffman/huffman.cpp", ios::in);
    if (!fileIn) {
        cerr<<" could="" not="" open."<<endl;
        exit(1);
    }
    char ch;
    int pos;

    //从文件中读入字符，并统计各个字符个数
    fileIn>>ch;
    while (fileIn && !fileIn.eof()) {
        pos = findPosition(ch);
        if (pos != -1)
            arrayTree[pos].weight++;
        else
            insert(ch, 1);
        fileIn>>ch;
    }

    createHuffmanTree(); //构造huffman树
    createHuffmanCode(); //对统计字符进行编码

    //打开 main.huff提供输出
    ofstream fileOut("/home/panis/ClionProjects/huffman/main.huff", ios::trunc);
    if (!fileOut) {
        cerr<<" could="" not="" open."<<endl;
        exit(1);
    }
    fileIn.clear(); //刷新输入流, 注：ofstream没有flush()方法，而ifstream则有flush()方法
    fileIn.seekg(0, ios::beg);

    //把文件中的字符进行编码，并写入outFilename文件
    fileIn>>ch;
    while (fileIn && !fileIn.eof()) {
        pos = findPosition(ch);
        if (pos != -1)
            fileOut<<codeArray[pos].ptr;
        fileIn>>ch;
    }
    fileIn.close();
    fileOut.close();

    //输入输出
    fileIn.open("/home/panis/ClionProjects/huffman/main.huff", ios::in);
    fileOut.open("/home/panis/ClionProjects/huffman/main.txt", ios::trunc);
    if (!fileIn || !fileOut) {
        cerr<<"File could not open."<<endl;
        exit(1);
    }

    //把outFileName文件中的编码进行译码，并把译码结果写入secondOutName文件
    const int longestLen = getLongestCodeLength();
    char *p = new char[longestLen+1];
    int k=0;
    fileIn>>ch;
    while (fileIn && !fileIn.eof()) {
        if (k < longestLen) {
            p[k++]=ch;
            p[k]='\0';
            pos = isEqual(p);
            if (pos != -1) {
                fileOut<<arrayTree[pos].info;
                k=0;
            }
        }
        else {
            cerr<<"The code is wrong."<<endl;
            exit(1);
        }
        fileIn>>ch;
    }

    fileIn.close();
    fileOut.close();
}
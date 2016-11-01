//
//  Stack.cpp
//  longsum
//
//  Created by panis on 2016/11/1.
//  Copyright © 2016年 panis. All rights reserved.
//

#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T *m_Data;
    int m_buffSize;//栈的大小
    int m_nCount;//栈中元素个数
    const int m_onceAlloc;//一次分配的最大元素个数，这里一次性分配不止一个T类型空间，减少每次插入元素时都进行内存空间重定向和内容拷贝
public:
    Stack()
    :m_buffSize(100)
    ,m_onceAlloc(10)
    ,m_nCount(0)
    ,m_Data(NULL) {
        if(0 > m_buffSize) {
            cout << "Application for space allocation(the stack space is above zero) is invalid:buffSize = " << m_buffSize
            << ",now we use default constructor" << endl;
            m_buffSize = 0;
        }
        else {
            m_Data = new T[m_buffSize];
        }
    }
    
    //析构函数
    ~Stack() {
        if (m_Data != NULL) {
            delete[] m_Data;
            m_Data = NULL;
        }
    }
    
    //销毁栈
    bool DestroyStack() {
        delete this;
        return true;
    }
    
    //清空栈中元素
    bool Clear() {
        if (m_Data != NULL) {
            delete[] m_Data;
            m_Data = NULL;
            m_buffSize = 0;
            m_nCount = 0;
            return true;
        }
        cout << "The stack is already empty !" << endl;
        return false;
    }
    
    //判断栈是否为空
    bool isEmpty() {
        return 0 == m_nCount;
    }
    
    //获取栈的长度
    int GetLength() {
        return m_nCount;
    }
    
    //获取栈顶元素
    const T GetTop() {
        return m_Data[m_nCount - 1];
    }
    
    //入栈
    bool Push(const T &elem) {
        //如果存储元素个数小于栈的大小
        if (m_nCount < m_buffSize) {
            m_Data[m_nCount++] = elem;
        }
        else {
            //重新分配存储空间
            T *m_TempData = new T[m_buffSize + m_onceAlloc];
            //将原空间存储内容拷贝到新空间
            memcpy(m_TempData,m_Data,m_nCount*sizeof(T));
            m_buffSize = m_nCount + m_onceAlloc;
            m_TempData[m_nCount++] = elem;
            //释放原空间
            delete[] m_Data;
            m_Data = m_TempData;
        }
        return true;
    }
    
    //将栈顶元素出栈
    bool Pop() {
        //如果弹出元素后和上一次分配之前栈的大小相同
        if (--m_nCount == m_buffSize - m_onceAlloc) {
            m_buffSize -= m_onceAlloc;
            T *tempData = new T[m_buffSize];
            memcpy(tempData,m_Data,m_buffSize*sizeof(T));
            delete[] m_Data;
            m_Data = tempData;
        }
        //如果出栈元素个数小于一次性最大分配单元数时
        else {
            m_Data[m_nCount+1] = 0;
        }
        return true;
    }
};

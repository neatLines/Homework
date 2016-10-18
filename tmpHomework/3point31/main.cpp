//
//  main.cpp
//  3point31
//
//  Created by panis on 2016/10/18.
//  Copyright © 2016年 panis. All rights reserved.
//

#include <iostream>
#include<string.h>
using namespace std;
class Node
{
public:
    int Data;
    Node* Next;
    Node()
    {
        Next = nullptr;
    }
}* head;
Node* instack(char c)
{
    Node *p;
    static int count1=0;
    if(count1==0)
    {
        p=new Node;
        p->Data=c;
        p->Next=NULL;
        count1++;
        return p;
    }
    else
    {
        p=new Node;
        p->Data=c;
        p->Next=head;
        return p;
    }
}
void stack_pop()
{
    Node *p;
    p=head;
    head=head->Next;
    delete p;
}
char stack_top()
{
    return head->Data;
}
bool stack_empty()
{
    if(head==NULL)
        return true;
    return false;
}
int main()
{
    size_t k;
    char s[101],c;
    bool YON=true;
    while(cin>>s)
    {
        k=strlen(s);
        for(int i=0; i<k/2; i++)
        {
            head=instack(s[i]);//前1/2的字符入栈
        }
        for(int i=(k%2==1?k/2+1:k/2);i<k;i++)//后面的和栈顶元素判断
        {
            if(!stack_empty())
            {
                c=stack_top();//取出栈顶元素
                if(c==s[i])//如果相同则栈顶元素出栈
                {
                    stack_pop();
                }
                else
                {
                    YON=false;//否则输出置为假
                    break;
                }
            }
            else
            {
                YON=false;
                break;
            }
        }
        if(YON)
            cout<<"是回文"<<endl;
        else
            cout<<"不是回文"<<endl;
        memset(s,'\0',sizeof(s));
    }
    return 0;
}

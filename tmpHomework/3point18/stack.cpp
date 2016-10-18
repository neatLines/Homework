//
//  stack.cpp
//  3point18
//
//  Created by panis on 2016/10/17.
//  Copyright © 2016年 panis. All rights reserved.
//

#include "stack.hpp"


class Stack
{
private:
    enum {MAX = 10};
    int items[MAX];
    int top;
public:
    Stack(){
        top = 0;
    }
    bool isempty() const {
        return 0 == top;
    }
    bool isfull() const {
        return MAX == top;
    }
    
    bool push(const int & item) {
        if (top < MAX) {
            items[top++] = item;
            return true;
        } else
            return false;
    }
    
    bool pop(int & item) {
        if(top > 0) {
            item = items[--top];
            return true;
        }
        else
            return false;
    }
};

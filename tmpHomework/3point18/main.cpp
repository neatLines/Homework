//
//  main.cpp
//  3point18
//
//  Created by panis on 2016/10/17.
//  Copyright © 2016年 panis. All rights reserved.
//

#include <iostream>


#include"cstring"
#include"string"
#include"stack.cpp"
using namespace std;

char map[9] = {'<', '(', '[', '{', '>', ')', ']', '}'};

bool isMatch(string in) {
    Stack kuoHao;
    int get;
    int temp = 0;
    bool flag = true;
    unsigned long len = in.length();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 8; j++) {
            if (in[i]==map[j]) {
                temp = j;
            }
        }
        if (temp < 4) {
            kuoHao.push(temp);
        } else {
            kuoHao.pop(get);
            if (get != temp-4) {
                flag = false;
                break;
            }
        }
    }
    if (!kuoHao.isempty()) {
        return false;
    }
    return flag;
    
}

int main(int argc, const char * argv[]) {
    string test;
    cin >> test;
    cout << isMatch(test);
}

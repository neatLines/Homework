//
//  main.cpp
//  4point10
//
//  Created by panis on 2016/10/22.
//  Copyright © 2016年 panis. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int str_erase(string &str, const string src)
{
    int counter = 0;
    string::size_type pos = 0;
    while ((pos = str.find(src, pos)) != string::npos) {
        str.erase(pos, src.size());
        ++counter;
    }
    return counter;
}

int main()
{
    string a = "dsfaasdf";
    string b = "sd";
    cout << str_erase(a, b);
    cout << a;
}

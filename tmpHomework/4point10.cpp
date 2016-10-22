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

string Reverse(string &s){
    string temp;
    unsigned long i=s.length();
    while(i){
        temp+=s.at(i-1);
        --i;
    }
    return temp;
}

int main()
{
    string a = "abcdefg";
    cout << Reverse(a);
}

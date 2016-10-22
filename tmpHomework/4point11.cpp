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

void tempFunction(string& t, string &s) {
    
    for (int i = 0; i < t.length(); i++) {
        for (int j = 0; j < s.length(); j++) {
            if (s.at(j) == t.at(i)) {
                s.at(j)='O';
            }
        }
    }
}

int main()
{
    string t = "abcdefg";
    string s = "qweasdsdgaseasdasdf";
    tempFunction(t, s);
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i)!='O'&&s.find(s.at(i))>=i) {
            cout << s.at(i) << ":" << i << endl;
        }
    }
    cout << s;
}

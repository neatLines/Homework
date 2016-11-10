//
//  main.cpp
//  hafman
//
//  Created by panis on 2016/11/8.
//  Copyright © 2016年 panis. All rights reserved.
//

#include <iostream>

#include "huffman.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    char s[]="At this point you may right-click the Shadowsocks tray icon and Enable System Proxy. Then right-click the icon again and enable Mode -> Global. This will update system-wide proxy settings – this will work for Google Chrome as well as Microsoft Internet Explorer.";
    
    int temp[128]={0};
    
    for(int i=0;i<sizeof(s);++i) {
        temp[s[i]]++;
    }
    
    CHuffmanTree tree(temp,128);
    tree.ShowBuffer();
    tree.ShowTree();
    tree.ShowHuffmanCode();
    tree.ShowTree();
    return 0;
}

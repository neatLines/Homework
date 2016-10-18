//
//  main.cpp
//  3point30
//
//  Created by panis on 2016/10/18.
//  Copyright © 2016年 panis. All rights reserved.
//

#include <iostream>
#include "queue.cpp"
int main(int argc, const char * argv[]) {
    CircularQueue queue = *new CircularQueue(10);
    int ret;
    for (int i = 0; i < 8; i++) {
        queue.push(i);
    }
    std::cout << queue.isFull();
    std::cout << queue.pop(ret);
    std::cout << ret;
    std::cout << queue.pop(ret);
    std::cout << ret;
    std::cout << queue.pop(ret);
    std::cout << ret;
    std::cout << queue.pop(ret);
    std::cout << ret;
    std::cout << queue.pop(ret);
    std::cout << ret;
    std::cout << queue.pop(ret);
    std::cout << ret;
}

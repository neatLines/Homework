//
//  queue.cpp
//  3point30
//
//  Created by panis on 2016/10/18.
//  Copyright © 2016年 panis. All rights reserved.
//

#include "queue.hpp"

class CircularQueue {
private:
    int *_pQueue;
    int _front, rear, length;
    static const int _MAC_QUEUE_SIZE = 20;
    
public:
    CircularQueue(int _SIZE) {
        _pQueue = new int[_SIZE];
    }
    
    ~CircularQueue(void) {
        delete[] _pQueue;
    }
    
    int getSize(void) const {
        return length-1;
    }
    
    int getFront(void) const {
        if (isEmpty()) {
            return 0;
        }
        return _pQueue[_front];
    }
    
    bool isEmpty() const{
        return _front == rear;
    }
    
    bool isFull() const {
        return (rear+1)%length == _front;
    }
    
    bool push(const int &val) {
        if (isFull()) {
            return false;
        }
        _pQueue[rear] = val;
        rear = (rear+1)%length;
        return true;
    }
    
    bool pop(int &val){
        if (isEmpty()) {
            return false;
        }
        val = _pQueue[_front];
        _front = (_front+1)%length;
        return true;
    }
};

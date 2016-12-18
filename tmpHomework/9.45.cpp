#include <iostream>
using namespace std;
class HashItem{
    int key, val;
public:
    HashItem(int k, int v): key(k), val(v){}
    const int& getKey(){
        return key;
    }
    const int& getVal(){
        return val;
    }
};

class HashTable{
    static const int SIZE = 256;
    HashItem ** table;      // 指向对个HashItem*
public:
    HashTable(){
        table  = new HashItem*[SIZE]();     // 初始化为0
    }
    void set(int key,int val){
        int idx = key%SIZE;
        while(table[idx] && table[idx]->getKey() != key) {
            idx = (idx + 1) % SIZE;
        }
        if(table[idx])
            delete table[idx];
        table[idx] = new HashItem(key, val);
    }
    const int get(int key){
        int idx = key%SIZE;
        while(table[idx] && table[idx]->getKey() != key) {
            idx = (idx + 1) % SIZE;
        }
        return table[idx] ? table[idx]->getVal() : -1;      // 判断key不存在的情况
    }
    ~HashTable(){
        for(int i=0; i<SIZE; i++)
            if(table[i]) delete table[i];
        delete[] table;                     // table销毁
    }
};
int main()
{
    HashTable *hashTable = new HashTable();
    for (int i = 0; i < 10; ++i) {
        hashTable->set(i,200-i);
    }
    for (int j = 0; j < 10; ++j) {
        cout << hashTable->get(j) << endl;
    }
}
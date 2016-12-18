#include <iostream>
using namespace std;
typedef struct {
    int key;
}ElemType;


typedef struct {
    ElemType *elem;
    int length;
}SSTable;

int Search_Sql(SSTable ST,int key) {
    int i = 1;
    ST.elem[ST.length+1].key = key;
    for (i = 1; ST.elem[i].key!=key; ++i) {
    }
    return i;
}

int main()
{
    ElemType l[11];
    for (int i = 0; i < 10; ++i) {
        l[i+1].key = i;
    }
    SSTable ssTable;
    ssTable.elem=l;
    ssTable.length=10;
    cout << Search_Sql(ssTable,3);
}
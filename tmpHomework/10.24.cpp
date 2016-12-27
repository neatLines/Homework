#include <iostream>
using namespace std;
#define MAXSIZE 20
typedef int KeyType;
typedef struct {
    KeyType key;
}RedType;
typedef struct{
    RedType r[MAXSIZE+1];
    int length;
}Sqlist;

bool LT(KeyType r1, KeyType r2){
    if(r1<r2){
        return true;
    }else{
        return false;
    }
}


void twoPathInsertSort(Sqlist &L){
    if(!L.length)
        return;
    KeyType d[MAXSIZE]={0};
    // 设置第一个记录和最后一个记录的指针
    int first=0;
    int final=0;
    // 设置d[0]为哨兵元素
    d[0]=L.r[1].key;
    int i;
    for(i=2; i<= L.length; ++i){
        if(LT(L.r[i].key,d[first])){  // 不需移动元素
            first = (first-1+L.length)%L.length;
            d[first] = L.r[i].key ;
        }else if(LT(d[final],L.r[i].key)){ // 不需要移动元
            final = final+1 ;
            d[final] = L.r[i].key;
        }else {    // 中间插入，需要移动元素
            int j=final-1;
            final += 1;
            d[final] = d[final-1];
            while(LT(L.r[i].key,d[j])){

                d[j+1] = d[j];
                --j;
            }
            d[j+1] = L.r[i].key;
        }
    }
    // 将辅助数组的数据按序复制到表L
    for(i=1; i<= L.length; ++i){
        L.r[i].key = d[first%L.length];
        ++first;
    }
}

void initSqlist(Sqlist &L){
    printf("input the sort record length:");
    if(!scanf("%d",&L.length) && L.length <= MAXSIZE ){
        printf("input error!\n");
        exit(-1);
    }
    int i;
    for(i=1; i<= L.length; ++i){
        //printf("input the record:");
        scanf("%d",&L.r[i].key);
    }
}

void printSqlist(Sqlist &L){
    printf("Sorted Sqlist as follow:");
    int i;
    for(i=1; i <= L.length; ++i){
        printf(" %d ",L.r[i].key);
    }
    printf("\n");
}

int main()
{
    Sqlist L;
    L.length = 0;
    initSqlist(L);
    twoPathInsertSort(L);
    printSqlist(L);
    return 0;
}
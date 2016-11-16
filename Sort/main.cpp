#include <iostream>
#include <fstream>

using namespace std;
void print(int a[]){
    for(int j= 0; j<sizeof(a); j++){
        cout<<a[j] <<" ";
    }
    cout<<endl;
}


void InsertSort(int a[],int n) {
    for(int i= 1; i<n; i++){
        if(a[i] < a[i-1]){               //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入
            int j= i-1;
            int x = a[i];        //复制为哨兵，即存储待排序元素
            a[i] = a[i-1];           //先后移一个元素
            while(x < a[j]){  //查找在有序表的插入位置
                a[j+1] = a[j];
                j--;         //元素后移
            }
            a[j+1] = x;      //插入到正确位置
        }
    }

}

void ShellInsertSort(int a[], int n, int dk) {
    for(int i= dk; i<n; ++i){
        if(a[i] < a[i-dk]){          //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入
            int j = i-dk;
            int x = a[i];           //复制为哨兵，即存储待排序元素
            a[i] = a[i-dk];         //首先后移一个元素
            while(x < a[j]){     //查找在有序表的插入位置
                a[j+dk] = a[j];
                j -= dk;             //元素后移
            }
            a[j+dk] = x;            //插入到正确位置
        }
    }

}

/**
 * 先按增量d（n/2,n为要排序数的个数进行希尔排序
 *
 */
void shellSort(int a[],int n){
    int dk = n/2;
    while( dk >= 1  ){
        ShellInsertSort(a, n, dk);
        dk = dk/2;
    }
}


void bubbleSort(int a[],int n){
    for(int i =0 ; i< n-1; ++i) {
        for(int j = 0; j < n-i-1; ++j) {
            if(a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

int main(){
    int a[20000] = {0};

    for (int i = 0; i < 20000; ++i) {
        a[i] = rand();
    }
    bubbleSort(a,sizeof(a)/sizeof(int));
    ofstream outFile;
    outFile.open("/home/panis/ClionProjects/test2/bubble.dat",ios::trunc);
    for(int j=0; j<20000; j++)
        outFile<<a[j]<<" ";
    outFile.close();

    ofstream outFile2;
    for (int i = 0; i < 20000; ++i) {
        a[i] = rand();
    }
    shellSort(a,sizeof(a)/sizeof(int));
    outFile2.open("/home/panis/ClionProjects/test2/shell.dat",ios::trunc);
    for(int j=0; j<20000; j++)
        outFile2<<a[j]<<" ";
    outFile2.close();

    ofstream outFile3;
    for (int i = 0; i < 20000; ++i) {
        a[i] = rand();
    }
    InsertSort(a,sizeof(a)/sizeof(int));
    outFile3.open("/home/panis/ClionProjects/test2/Insert.dat",ios::trunc);
    for(int j=0; j<20000; j++)
        outFile3<<a[j]<<" ";
    outFile3.close();
}
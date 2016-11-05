#include <iostream>
#define Max 128
using namespace std;
template <typename T>
class twin{
public:
    int col;
    T e;
};

class CSparseMat   {
public:
    CSparseMat(){}
    CSparseMat(int r,int c,int n) {
        m_nRow=r;
        m_nCol=c;
        m_nTws=n;
        m_pt=new twin<int>[m_nTws];
        if(!m_pt)
            return;   // 输入矩阵的所有二元组
        int i;
        for(i=0;i<m_nTws;i++){
            cout<<"请输入非零元二元组的列标和值：";
            cin>>m_pt[i].col>>m_pt[i].e;
        }
        for(i=0;i<m_nRow;i++){
            cout<<"请输入每行第一个非零元在二元组中的序号(没有输入-1)：";
            cin>>rpos[i]; // 该行没有非零元输入-1
        }
        rpos[m_nRow] = m_nTws;
    }
    virtual ~CSparseMat(){}
    void ShowSparse(int i,int j) {
        if (rpos[i]==-1||j>m_nCol||i>m_nRow) {
            return;
        }
        int endline = i+1;
        while (rpos[endline]==-1) {
            endline++;
        }
        for (int k = rpos[i]; k < rpos[endline]; ++k) {
            if (m_pt[k].col==j) {
                cout << m_pt[k].e << endl;
            }
        }
    }
    twin<int>* m_pt; // 指向非零元的指针
    int rpos[Max];
    int m_nCol;  // 矩阵列数
    int m_nRow;  //矩阵行数
    int m_nTws; //非零元个数
    };

int main() {
    CSparseMat A(3,3,5);
    A.ShowSparse(2,1);
    return 0;
}
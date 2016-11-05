#include <iostream>
#define Max 128
#define MaxV 128
using namespace std;
template <typename T>
class twin{
public:
    twin(int c, int r) {
        col = c;//列
        row = r;//行
    }
    void setTwin() {
        int v=0;
        T temp;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cin >> temp;
                if (temp) {
                    B[i][j] = 1;
                    V[v]=temp;
                    v++;
                } else {
                    B[i][j] = 0;
                }

            }
        }
    }

    void showTwin() {
        int v=0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (B[i][j]) {
                    cout << V[v] <<" ";
                    v++;
                } else {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }

    int col;
    int row;

    int B[Max][Max];
    T V[MaxV];
};



int main() {
    cout << "输入矩阵大小" << endl;
    int n,c;
    cin >> n >> c;
    twin<int> *a = new twin<int>(n,c);
    a->setTwin();
    twin<int> *b = new twin<int>(n,c);
    b->setTwin();
    twin<int> *GET = new twin<int>(n,c);
    int a_MV = 0;
    int b_MV = 0;
    int GET_MV = 0;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < c; ++j) {
            if (a->B[i][j]) {
                GET->B[i][j]=1;
                GET->V[GET_MV]+=a->V[a_MV];
                a_MV++;
                flag = false;
            }
            if (b->B[i][j]) {
                GET->B[i][j]=1;
                GET->V[GET_MV]+=b->V[b_MV];
                b_MV++;
                flag = false;
            }
            if (flag){
                GET->B[i][j]=0;
            } else {
                GET_MV++;
            }
            flag = true;
        }
    }
    GET->showTwin();
    return 0;
}
#include <iostream>
#include <math.h>
#include "Stack.cpp"
using namespace std;

/// M 进制数字转 10 进制
int MToTen(char c) {
    if (c >= '0'&&c <= '9') {
        return c - '0';
    }
    else {
        return c - 'a' + 10;
    }
}


/// 10 进制数字转到 M 进制
char TenToM(int digital) {
    if (digital >= 0 && digital <= 9) {
        return '0' + digital;
    }
    else {
        return digital - 10 + 'a';
    }
}

/// M 进制数转 10 进制
double StackMToTen(int M, string x) {
    Stack<char> reverse;
    for (char n : x) {
        reverse.Push(n);
    }
    double res = 0;
    for (int i = 0; reverse.GetLength() > 0; i++) {
        res += (MToTen(reverse.Pop()))*pow(M, i);
    }
    
    return res;
}

/// M 进制数转 10 进制
double ArrayMToTen(int M, string x) {
    char reverse[100];
    int index = 0;
    for (char n : x) {
        reverse[index++] = n;
    }
    double res = 0;
    for (int i = 0; index > 0; i++, index--) {
        res += (MToTen(reverse[i]))*pow(M, i);
    }
    
    return res;
}

/// 从 10 进制转到 M 进制
string StackTenToM(int M, int x) {
    Stack<char> res;
    while (x) {
        res.Push(TenToM(x%M));
        x /= M;
    }
    string result = "";
    while (res.GetLength() > 0) {
        result += res.Pop();
    }
    return result;
}

/// 从 10 进制转到 M 进制
string ArrayTenToM(int M, int x) {
    char res[100];
    int index = 0;
    while (x) {
        res[index++] = (TenToM(x%M));
        x /= M;
    }
    string result = "";
    while (index-- >= 0){
        result += res[index];
    }
    return result;
}


int main()
{
    cout << ArrayMToTen(8, "12323");
    return 0;
}

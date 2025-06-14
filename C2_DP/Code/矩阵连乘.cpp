#include <iostream>
using namespace std;

const int MAXN = 105;
const long long INF = 1e18;

long long m[MAXN][MAXN]; // m[i][j]：从Ai乘到Aj的最小乘法次数
int s[MAXN][MAXN];       // s[i][j]：从Ai乘到Aj的最优断点位置

//可视化输出最优加括号方式
void printParenthesis(int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printParenthesis(i, s[i][j]);       //左侧子结构
    cout << " x ";
    printParenthesis(s[i][j] + 1, j);   //右侧子结构
    cout << ")";
}

int main() {
    int n = 6;
    int p[] = {30, 35, 15, 5, 10, 20, 25}; // 矩阵维度：A1=30x35, A2=35x15,...A6=20x25

    //初始化：m[i][i] = 0（单个矩阵乘法代价为0）
    for (int i = 1; i <= n; ++i) {
        m[i][i] = 0;
    }

    //计算链长从2开始的所有子问题
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            m[i][j] = INF;
            for (int k = i; k < j; ++k) {
                long long cost = m[i][k] + m[k+1][j] + 1LL * p[i-1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;  //记录断点
                }
            }
        }
    }

    cout << "最少乘法次数: " << m[1][n] << endl;
    cout << "最优加括号方式: ";
    printParenthesis(1, n);
    cout << endl;

    return 0;
}


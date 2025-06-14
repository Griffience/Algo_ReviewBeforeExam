#include <iostream>
using namespace std;

const int MAXN = 105;
const long long INF = 1e18;

long long m[MAXN][MAXN]; // m[i][j]：从Ai乘到Aj的最小乘法次数
int s[MAXN][MAXN];       // s[i][j]：从Ai乘到Aj的最优断点位置

int n = 6;
int p[] = {30, 35, 15, 5, 10, 20, 25}; // 矩阵维度：A1=30x35, A2=35x15,...A6=20x25

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

int LookupChain(int i, int j){
	if (m[i][j] > 0) return m[i][j];
	if (i==j) return 0;
	int u = LookupChain(i,i) + LookupChain(i+1, j) + p[i-1]*p[i]*p[j];
	s[i][j]=i;
	for (int k=i+1;k<j;k++){
		int t=LookupChain(i,k) + LookupChain(k+1, j) + p[i-1]*p[k]*p[j];
		if (t<u) {
			u = t;
			s[i][j] = k;
		}
	}
	m[i][j] = u;
	return u;
}

int matrixChainMem(int n){
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++){
			m[i][j]=0;
		}
	}
	return LookupChain(1,n);
}

int main() {
    matrixChainMem(6);

    cout << "最少乘法次数: " << m[1][n] << endl;
    cout << "最优加括号方式: ";
    printParenthesis(1, n);
    cout << endl;

    return 0;
}


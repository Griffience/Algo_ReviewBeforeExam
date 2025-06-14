#include <iostream>
using namespace std;

const int MAXN = 105;
const long long INF = 1e18;

long long m[MAXN][MAXN]; // m[i][j]����Ai�˵�Aj����С�˷�����
int s[MAXN][MAXN];       // s[i][j]����Ai�˵�Aj�����Ŷϵ�λ��

//���ӻ�������ż����ŷ�ʽ
void printParenthesis(int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printParenthesis(i, s[i][j]);       //����ӽṹ
    cout << " x ";
    printParenthesis(s[i][j] + 1, j);   //�Ҳ��ӽṹ
    cout << ")";
}

int main() {
    int n = 6;
    int p[] = {30, 35, 15, 5, 10, 20, 25}; // ����ά�ȣ�A1=30x35, A2=35x15,...A6=20x25

    //��ʼ����m[i][i] = 0����������˷�����Ϊ0��
    for (int i = 1; i <= n; ++i) {
        m[i][i] = 0;
    }

    //����������2��ʼ������������
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            m[i][j] = INF;
            for (int k = i; k < j; ++k) {
                long long cost = m[i][k] + m[k+1][j] + 1LL * p[i-1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;  //��¼�ϵ�
                }
            }
        }
    }

    cout << "���ٳ˷�����: " << m[1][n] << endl;
    cout << "���ż����ŷ�ʽ: ";
    printParenthesis(1, n);
    cout << endl;

    return 0;
}


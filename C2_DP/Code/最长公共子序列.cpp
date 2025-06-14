#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N], b[N], dp[N][N];

vector<int>lcs_seq;  //���������-�����洢LCS����

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= m; i++)cin >> b[i];
    
    //��dp��
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    //�����ҳ�LCS���У������½ǿ�ʼ���ϻ��ˣ�
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(a[i] == b[j]) {
            lcs_seq.push_back(a[i]);
            i--; j--;
        } else if(dp[i-1][j] >= dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

//    reverse(lcs_seq.begin(), lcs_seq.end());

    //������
    cout << "LCS����: " << dp[n][m] << endl;
    cout << "LCS����: ";
    for(int i = lcs_seq.size() - 1; i >= 0; i--) cout <<lcs_seq[i]<< " ";
    cout << endl;

    return 0;
}


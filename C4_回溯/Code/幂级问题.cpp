#include <iostream>
using namespace std;

const int N = 15;  
int n;
int path[N];  
int path_len = 0; //��ǰpath�е�Ԫ�ظ���

void dfs(int cur) {
    //�����ǰ�Ӽ�
    cout << "{";
    for (int i = 0; i < path_len; i++) {
        if (i > 0) cout << ",";
        cout << path[i];
    }
    cout << "}" << endl;

    //���Դ� cur�� n��ÿ��Ԫ��
    for (int i = cur; i <= n; i++) {
        path[path_len++] = i;  //ѡ��Ԫ�� i
        dfs(i + 1);     //�ݹ������һ��
        path_len--;          
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}


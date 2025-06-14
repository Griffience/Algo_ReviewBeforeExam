#include <iostream>
using namespace std;

const int N = 15;  
int n;
int path[N];  
int path_len = 0; //当前path中的元素个数

void dfs(int cur) {
    //输出当前子集
    cout << "{";
    for (int i = 0; i < path_len; i++) {
        if (i > 0) cout << ",";
        cout << path[i];
    }
    cout << "}" << endl;

    //尝试从 cur到 n的每个元素
    for (int i = cur; i <= n; i++) {
        path[path_len++] = i;  //选中元素 i
        dfs(i + 1);     //递归进入下一层
        path_len--;          
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}


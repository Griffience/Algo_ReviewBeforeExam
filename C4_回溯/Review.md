## 回溯题型复习


### 1.幂级问题PowerSet(60%考这个)
<img src="img/power.png" alt="" width="95%" title="">  

```cpp
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

```

### 2. 排列问题Permutation(这个是最经典的回溯，因为太简单不知道考不考,50%考这个)
<img src="img/permutation.png" alt="" width="55%" title="">

```cpp
#include<iostream>
#include<algorithm>
using namespace std;
int n;
const int N = 10;
int vis[N]={0};
int a[N];
int path[N];

void dfs(int u){
    if(u>=n+1){
        for(int i=1;i<=n;i++)cout<<path[i]<<" ";
        puts("");
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            path[u] = i;
            vis[i] = 1;
            dfs(u+1);
            vis[i]=0;
        }
    }
    
}

int main(){
    cin>>n;
    dfs(1);
    return 0;
    
}
```

### 3. 最大团问题(40%考这个，个人感觉不会考，反正我也没看这个，若是需要请自行复习)

### 4. 图的m着色问题（MColor）(65%考这个)
<img src="img/Mcolor.png" alt="" width="" title="">
<img src="img/Mcolor2.png" alt="" width="" title="">

```cpp
//采用DFS(回溯枚举) 
//大致思路
// 1.建图(用邻接矩阵bool adj[N+1][N+1]或者邻接表存下哪些顶点两两相邻)
// 2.维护颜色数组(定义int color[N+1],color[u]表示顶点u被染成的颜色-取值1.....K)
// 3. DFS枚举第u个顶点 

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100;  
bool adj[MAXN+1][MAXN+1];
int color[MAXN+1];
long long ans;
int N, K;

//从顶点u开始染色
void dfs(int u) {
    if (u > N) {
        //全部染完，计数加一
        ans++;
        return;
    }
    //尝试给 u 染 1..K 号颜色
    for (int c = 1; c <= K; c++) {
        bool ok = true;
        //检查和所有已染的邻居 v 是否冲突
        for (int v = 1; v < u; v++) {
            if (adj[u][v] && color[v] == c) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        //不冲突就染上
        color[u] = c;
        dfs(u+1);
        //回溯
        color[u] = 0;
    }
}

int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        int E;
        cin >> E;
        //清空
        memset(adj, 0, sizeof(adj));
        memset(color, 0, sizeof(color));
        ans = 0;

        //读边
        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            adj[x][y] = adj[y][x] = true;
        }

        //从顶点 1 开始染色
        dfs(1);

        //输出方案数
        cout << ans << "\n";
    }
    return 0;
}
```

### 5.N 皇后问题（Queen）(特别经典的一道题,在OJ上对应题目"一山不容二虎",acwing也将其作为例题来做,我要是出题人,我就出这个,85%考这个吧我感觉)
<img src="img/NQueen.png" alt="" width="" title="">

```cpp
//n皇后问题(经典搜索) 
//参考ACWING算法基础课  n皇后问题 
//皇后问题

#include<iostream>
#include<cstring>
using namespace std;
const int N = 20;
int n;
int t; 
//char g[N][N];
bool col[N], dg[N], udg[N];   //dg是对角线,udg是反
int cnt = 0;
 
void dfs(int u)  //u可以理解为行
{
	if(u==n)  //搜索完并且安置好每个点是啥了
	{
		cnt++;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!col[i]&&!udg[u+i]&&!dg[i-u+n])   //+n是为了偏移避免负值. 剪枝(对于不满足要求的点，不再继续往下搜索)  
		{
			//放一个皇后 
			col[i] = udg[u + i] = dg[i - u + n] = true;    //不同b对应不同对角线
			dfs(u + 1);
			//恢复现场
			col[i] = udg[u + i] = dg[i - u + n] = false;
		}
	}
}
int main()
{
	cin>>t;
	while(t--){
		cin >> n;
		cnt = 0;
		memset(col,0,sizeof(col));
		memset(dg,0,sizeof(col));
		memset(udg,0,sizeof(col));
		dfs(0);
		cout<<cnt<<endl;
	}
	
	return 0;
}

//
//#include<iostream>
//using namespace std;
//const int N = 20;
//int n;
//char g[N][N];
//bool col[N], dg[N], udg[N];   //dg是对角线,udg是反
//void dfs(int u)  //u可以理解为行
//{
//	if(u==n)  //搜索完并且安置好每个点是啥了
//	{
//		for (int i = 0; i < n; i++)cout<<g[i]<<endl;  //这里等价于 二重循环i++,j++  输出g[i][j]
//		puts("");
//		return;
//	}
//	for(int i=0;i<n;i++)
//	{
//		if(!col[i]&&!udg[u+i]&&!dg[i-u+n])   //+n是为了偏移避免负值. 剪枝(对于不满足要求的点，不再继续往下搜索)  
//		{
//			g[u][i] = 'Q';
//			col[i] = udg[u + i] = dg[i - u + n] = true;    //不同b对应不同对角线
//			dfs(u + 1);
//			//恢复现场
//			col[i] = udg[u + i] = dg[i - u + n] = false;
//			g[u][i] = '.';
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			g[i][j] = '.';
//	dfs(0);
//	return 0;
//}



```

### 6. 回溯搜索必刷-走迷宫
<img src="img/Findroad.png" alt="" width="" title="">

```cpp
//BFS走迷宫
#include <bits/stdc++.h>
using namespace std;
 
const int N = 105;
int n, m, t;
char g[N][N];
bool vis[N][N];
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
 
typedef pair<int,int>PII;
 
void solveBFS() {
    cin >> n;       
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];    
            vis[i][j] = false; //清空访问标记
        }
    }
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;  
 
    queue<PII> q;
    if (g[sx][sy] == '.') {
        q.push({sx,sy});
        vis[sx][sy] = true;
    }
 
    bool ok = false;
    while (!q.empty()) {
        PII start = q.front();  //让start点 等于 队列首个点
        q.pop(); //删除q队列首个点
 
        if (start.first==ex && start.second==ey) {
            ok = true;
            break;
        }
        int x = start.first;
        int y = start.second;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx>=0 && nx<n && ny>=0 && ny<n&& !vis[nx][ny] && g[nx][ny]=='.') {
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
 
    cout << (ok ? "YES\n" : "NO\n");
}
 
int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
 
    cin >> t;
    while (t--) solveBFS();
    return 0;
}
```




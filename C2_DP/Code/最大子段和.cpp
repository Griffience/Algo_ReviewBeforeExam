#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[100000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int maxsum = 0;
    int dp = 0; // 存储当前数字结尾的最大子段和
    for (int i = 0; i < n; i++)
    {
        dp = max(dp + a[i], a[i]);
        if (dp > maxsum)
            maxsum = dp;
    }
    cout << maxsum;
    return 0;
}
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
    int dp = 0; // �洢��ǰ���ֽ�β������Ӷκ�
    for (int i = 0; i < n; i++)
    {
        dp = max(dp + a[i], a[i]);
        if (dp > maxsum)
            maxsum = dp;
    }
    cout << maxsum;
    return 0;
}
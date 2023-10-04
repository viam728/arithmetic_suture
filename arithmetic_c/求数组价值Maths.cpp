#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
long long a[maxn];
int ans = 0;

#include <iostream>
using namespace std;

// 计算Cn-m的函数-动态规划O(nk)
// int C_dp(int n, int k) {
//     std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));

//     for (int i = 0; i <= n; i++) {
//         dp[i][0] = 1;
//     }

//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= std::min(i, k); j++) {
//             dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//         }
//     }

//     return dp[n][k];
// }

// 计算Cn-m的函数-直接求解O(m)
long long C(int n, int m)
{
    // 如果m大于n或者m小于0，返回0
    if (m > n || m < 0)
    {
        return 0;
    }
    // 如果m等于n或者m等于0，返回1
    if (m == n || m == 0)
    {
        return 1;
    }
    // 初始化结果为1
    long long result = 1;
    // 边乘边除，注意先乘后除
    for (int i = 1; i <= m; i++)
    {
        result = result * (n - i + 1) / i;
    }
    // 返回结果
    return result;
}

// O(nk*k)
int calValue(int n, int k, long long *a)
{
    long long diff = 0, selected = 0;
    long long sum = 0;
    long long C1 = 0, C2 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            diff = 2 * j - k - 1;
            C1 = C(i - 1, j - 1);
            C2 = C(n - i, k - j);
            selected = C1 + C2;
            sum += diff * selected * a[i - 1];
        }
    }

    return sum;
}

int main()
{
    int n, k; // 输入的 n 和 k
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // 输入每个数字
    }
    sort(a, a + n); // 将数字从小到大排序Sort()有O(n*log（n）)
    ans = calValue(n, k, a) % mod;
    cout << ans << endl;
    return 0;
}

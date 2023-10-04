#include<iostream>
using namespace std;
const long long mod = 1e9 + 7;
long long n, k, a[200010], ans, vis[200010];


//O(2^n)
void dfs(long long step, long long sum) {
if (step == n + 1 || sum == k) {
if (sum == k) {
for (long long i = 1; i <= k; i++) {
for (long long j = i + 1; j <= k; j++) {
ans += abs(vis[j] - vis[i]) % mod;
ans %= mod;
}
}
}
return;
}
vis[sum + 1] = a[step];
dfs(step + 1, sum + 1);
vis[sum + 1] = 9;
dfs(step + 1, sum);
}
int main() {
cin >> n >> k;
for (long long i = 1; i < n; i++) {
cin >> a[i];
}
dfs(1, 0);
cout << ans << endl;
return 0;

}

//复杂度是大于2^n的
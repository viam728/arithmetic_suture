#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int mod = 1e9 + 7; 

//价值
int value(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += abs(arr[i] - arr[j]); 
            ans %= mod; 
        }
    }
    return ans;
}

//O(2^n)
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end()); //对数组排序
    long long ans = 0;
    queue<vector<int>> q; //定义一个队列，存储每个状态
    q.push({}); //初始状态为空数组
    while (!q.empty()) {
        vector<int> cur = q.front(); //取出队首元素
        q.pop(); //弹出队首元素
        if (cur.size() == k) { //如果当前数组长度为 k，说明找到了一种选择数字的方法
            ans += value(cur); //计算当前数组的价值，并累加到答案中
            ans %= mod; //取模
        } else { //如果当前数组长度小于 k，说明还可以继续选择数字
            int last = cur.empty() ? -1 : cur.back(); //找到当前数组的最后一个数字，如果为空则设为 -1
            for (int i = 0; i < n; i++) { //遍历所有数字
                if (a[i] > last) { //如果当前数字大于最后一个数字，说明可以选择它
                    vector<int> next = cur; //复制当前数组
                    next.push_back(a[i]); //在末尾添加当前数字
                    q.push(next); //将新的状态加入队列中
                }
            }
        }
    }
    cout << ans << endl; 
    return 0;
}

//value函数的时间复杂度是O (n²)，因为它有两层循环，每层循环的次数都是n。
//main函数的时间复杂度是O (2^n)，队列存储每个状态，每个状态都是一个长度为k的数组，而k是固定的，所以每个状态占用的空间是O (1)。对于n个数字，有2n种选择方法，即2n种状态，所以队列中最多有2^n个元素。对于每个元素，出队和入队的操作都是O (1)，所以整个循环的时间复杂度是O (2^n)。另外，排序和计算价值的操作都是O (n²)
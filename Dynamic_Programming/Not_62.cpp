//
// Created by 19233 on 2024/9/23.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    vector<vector<int>>dp(2,vector<int>(n+1,0));
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j])
                dp[1][j] = dp[0][j - 1] + 1;
            else
                dp[1][j] = max(dp[0][j], dp[1][j - 1]);
        }
        copy(dp[1].begin(),dp[1].end(),dp[0].begin());
        fill(dp[1].begin(),dp[1].end(),0);
    }
    cout << dp[0][n]; // 输出最长公共子序列的长度
    return 0;
}
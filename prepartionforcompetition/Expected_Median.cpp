//
// Created by 19233 on 2024/9/30.
//
//https://codeforces.com/contest/1999/problem/F

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 200007;
const ll MOD = 1e9 + 7;

ll fact[N], inv[N];

// 快速幂函数，用于计算 a^(b) mod MOD
ll power_mod(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// 预计算阶乘和逆阶乘
void preprocess() {
    fact[0] = 1;
    for(int i = 1; i < N; ++i)
        fact[i] = fact[i-1] * i % MOD;

    // 计算 inv[N-1] = (fact[N-1])^{-1} mod MOD
    inv[N-1] = power_mod(fact[N-1], MOD-2, MOD);
    for(int i = N-2; i >= 0; --i)
        inv[i] = inv[i+1] * (i+1) % MOD;
}

// 计算组合数 C(n, k) mod MOD
ll combine(int k, int n) {
    if(k > n || k < 0)
        return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 预处理阶乘和逆阶乘
    preprocess();

    int T;
    cin >> T;
    while (T--) {
        int n, k, x;
        ll y = 0, ans = 0;
        cin >> n >> k;
        for(int i = 0; i < n; ++i) {
            cin >> x;
            y += x;
        }
        // 计算中位数为1的子序列数量
        int m = (k + 1) / 2;
        // 遍历 i 从 m 到 min(k, y)
        for(int i = m; i <= min(k, (int)y); ++i) {
            ll c1 = combine(i, y);          // C(y, i)
            ll c2 = combine(k - i, n - y);  // C(n - y, k - i)
            ans = (ans + c1 * c2 % MOD) % MOD;
        }
        cout << ans << "\n";  // 输出 ans
    }

    return 0;
}

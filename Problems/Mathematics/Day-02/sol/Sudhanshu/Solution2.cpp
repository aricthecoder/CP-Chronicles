#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
long long fact[1005], invfact[1005];

long long modpow(long long a, long long b)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for (int i = 1; i <= 1000; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invfact[1000] = modpow(fact[1000], MOD - 2);
    for (int i = 999; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end(), greater<int>());

        int x = a[k - 1];

        int total = 0, need = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == x)
                total++;
        for (int i = 0; i < k; i++)
            if (a[i] == x)
                need++;

        cout << nCr(total, need) << "\n";
    }
    return 0;
}

/*
    Approach
    - precompution factorials and inverse factorials
    - in the question it can be seen that max value can be only be attain my specific no. only after decreasing order
    - now it is possible there is a number which mai bi repeat multiple times so calculate the no. of ways using PnC using the precomputated factorials
    
    - TC : O(nlogn) SC: O(n)
*/
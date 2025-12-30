// Submission link: https://codeforces.com/contest/1475/submission/355643230

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;
const ll MOD = 1e9 + 7;

ll binexp(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

vector<ll> fac(1001);

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fac[n] * binexp(fac[r], MOD - 2) % MOD * binexp(fac[n - r], MOD - 2) % MOD;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll &x : v) cin >> x;

    sort(v.begin(), v.end());

    ll ele = v[n - k];
    ll total = 0;

    for (ll x : v) {
        if (x == ele) total++;
    }

    ll taken = 0;
    for (ll i = n - k; i < n; i++) {
        if (v[i] == ele) taken++;
    }

    cout << nCr(total, taken) << "\n";
}

int main() {
    fastio

    fac[0] = 1;
    for (int i = 1; i <= 1000; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}


/*
Explaination : 

To maximize the sum, we must always select the k largest elements of the array.
Any selection that excludes one of the k largest elements will produce a smaller sum.
If all elements were distinct, the answer would be 1, since the k largest elements
are uniquely determined. However, when duplicate values exist, multiple selections
can result in the same maximum sum.

Approach:
1. Sort the array in non-decreasing order.
2. The k largest elements are the last k elements of the sorted array.
3. Let 'ele' be the smallest element among these k elements (i.e., ele = v[n - k]).
4. Some elements larger than 'ele' are forced to be chosen, but occurrences of 'ele'
   introduce flexibility.


Time Complexity :  O(n log(n))
Space Complexity : O(n)

*/
/*

Count the number of interesting pairs (ai,aj) that have the max. absolute difference.

Ans = count(min el) * count(max el)

Time: O(n)
Space: O(1)

Submission Link: https://codeforces.com/contest/1771/submission/355675072

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        unordered_map<ll, ll> mp;
        ll _max = LONG_LONG_MIN, _min = LONG_LONG_MAX;
        for (ll i = 0; i < n; i++) {
            ll el;
            cin >> el;
            mp[el]++;
            _max = max(_max, el);
            _min = min(_min, el);
        }
        ll ans;
        if (_max == _min) {
            ans = n * (n-1);
        }
        else {
            ans = 2 * mp[_min] * mp[_max];
        }
        cout << ans << endl;
    }
}
/*
We needed to find out the max no. of resistors needed, to get to a target resistance, with only 1 unit resistors.

I wanted to convert the resistance to 1/1, so I took the larger no. and subtracted it by the maximum multiple of lower number, which is still lower than the larger one, adding 1 each time.

Time: O(log(max(a, b)))
Space: O(1)

Submission Link: https://codeforces.com/contest/343/submission/355851930
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll a, b;
    cin >> a >> b;

    ll ans = 1;
    while (a != 1 || b != 1) {
        if (a > b) swap(a, b);
        // b is always greater

        ll count = (b-1) / a;
        ans += count;
        b -= count * a;
    }

    cout << ans;
}
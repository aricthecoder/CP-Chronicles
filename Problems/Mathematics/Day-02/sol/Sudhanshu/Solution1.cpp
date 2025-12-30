#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);

        for (ll i = 0; i < n; i++)
            cin >> v[i];

        sort(v.begin(), v.end());

        ll low = v[0];
        ll high = v[n - 1];

        ll cLow = 0;
        ll cHigh = 0;

        for (auto i : v)
        {
            if (i != low)
                break;
            cLow++;
        }
        reverse(v.begin(), v.end());

        for (auto i : v)
        {
            if (i != high)
                break;
            cHigh++;
        }

        cout << ((low == high) ? (cLow * (cLow - 1)) : (cLow * cHigh * 2)) << endl;
    }

    return 0;
}

/*
APPROACH:

- Sort the array to easily identify minimum and maximum elements
- Find the minimum (low) and maximum (high) values
- Count occurrences of minimum value (cLow) and maximum value (cHigh)
- If all elements are equal (low == high), we need to choose any 2 elements from n,
    so answer = n * (n-1) (dividing by 2 would give combinations, but we want pairs)
- Otherwise, the answer is cLow * cHigh * 2 (considering both orderings of pairs)

TC: O(nlog n)
SC: O(n)

https://codeforces.com/contest/1771/submission/355619015
*/
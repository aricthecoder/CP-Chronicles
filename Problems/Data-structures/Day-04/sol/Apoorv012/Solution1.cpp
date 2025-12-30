/*

We have to find the minimum cost that we could acheive by placing ( and ) in the blank spaces. We have to make sure that () are valid.

I saw the pattern, that we can set the blank to ) as long as there is atleast one open (.

Time: O(n);
Space: O(n);

Submission Link: https://codeforces.com/contest/1997/submission/355679346

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    // cout << "n, s: " << n << " " << s << endl;

    ll ans = 0;
    stack<ll> st;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
            // cout << i << " pushed (\n";
        }
        else if (s[i] == ')') {
            if (st.empty()) {
                cout << -1 << endl;
                return;
            }
            ll start = st.top();
            st.pop();
            ans += i - start;
            // cout << i << " poped )\n";
        }
        else {
            if (st.empty()) {
                st.push(i);
                // cout << i << " pushed _\n";
            }
            else {
                ll start = st.top();
                st.pop();
                ans += i - start;
                // cout << i << " popped _\n";
            }
        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        // cout << t << " done\n";
    }
}
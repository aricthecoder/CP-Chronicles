/*
Problem: find the minimum cost after replace each _ by brackets which follow RBS

Approach:
Use a stack which hold index for '(' or '_' if stack is empty.
'_' = '(' - if empty stack.
'_' = ')' - if not empty.

Complexity:
Time: O(n)
Space: O(n): for the stack.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define out(x) cout << (x) << endl
#define outr(x)            \
    {                      \
        cout << x << endl; \
        return;            \
    }

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll res = 0;
    stack<ll> st;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == '_')
        {
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                res += (i - st.top());
                st.pop();
            }
        }
        else
        {
            res += (i - st.top());
            st.pop();
        }
    }

    out(res);
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

//submission link: https://codeforces.com/problemset/submission/1997/355793929
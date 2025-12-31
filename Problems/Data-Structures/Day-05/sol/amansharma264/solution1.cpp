/*
Problem Name: Nearest Smaller Values

Short Problem Statement:
Given an array of n integers, for each position i, find the nearest position
to the left that contains a strictly smaller value.
If no such position exists, print 0 for that index.

Approach (Using Prefix Sums / Stack Concept):
We process the array from left to right using a monotonic increasing stack.
Each stack element stores:
- the value
- its 1-based index

For every element:
1. Pop elements from the stack while they are greater than or equal to
   the current value (they cannot be the nearest smaller).
2. If the stack becomes empty, no smaller element exists on the left → print 0.
3. Otherwise, the top of the stack gives the nearest smaller value’s position.
4. Push the current element with its index into the stack.

This ensures each element is pushed and popped at most once.

Time Complexity:
O(n)

Space Complexity:
O(n)

Example:
Input:
8
2 5 1 4 8 3 2 5

Output:
0 1 0 3 4 3 3 7

Submission Link:
https://cses.fi/problemset/result/15785248/
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define ll long long
#define endl '\n'

int main() {
    fastio();

    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<pair<ll, ll>> st;

    for (ll i = 0; i < n; i++) {
        while (!st.empty() && st.top().first >= a[i]) {
            st.pop();
        }

        if (st.empty()) {
            cout << 0 << " ";
        } else {
            cout << st.top().second << " ";
        }

        st.push({a[i], i + 1});
    }

    return 0;
}

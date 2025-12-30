/*
DAY 4
Q1 Even Positions
.*/

#include <bits/stdc++.h>
using namespace std;

long long solve_case(string s) {
    int n = s.size();

    int fixedOpen = 0, fixedClose = 0;
    for (char c : s) {
        if (c == '(') fixedOpen++;
        if (c == ')') fixedClose++;
    }

    int needOpen = n / 2 - fixedOpen;
    int needClose = n / 2 - fixedClose;

    int balance = 0;

    // restore the string
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') balance++;
        else if (s[i] == ')') balance--;
        else {
            // underscore -> choose bracket
            if (needClose > 0 && balance > 0) {
                s[i] = ')';
                needClose--;
                balance--;
            } else {
                s[i] = '(';
                needOpen--;
                balance++;
            }
        }
    }

    // compute cost
    long long cost = 0;
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') st.push(i + 1);
        else {
            int openIdx = st.top(); st.pop();
            cost += (i + 1) - openIdx;
        }
    }

    return cost;
}

int main() {

    int t; 
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << solve_case(s) << "\n";
    }
    return 0;
}

//TC =O(n) and SC = O(n)
/*
My submission : https://codeforces.com/contest/1997/submission/355669016
*/
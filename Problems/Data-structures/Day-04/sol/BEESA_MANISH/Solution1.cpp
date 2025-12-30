
//TC  - O(n) and SC - O(n)
//Submission Link - https://codeforces.com/contest/1997/submission/355786129

#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long total_cost = 0;
    long long current_balance = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '_') {
            if (current_balance == 0) {
                current_balance++;
            } else {
                current_balance--;
            }
        } else if (s[i] == '(') {
            current_balance++;
        } else { 
            current_balance--;
        }
        total_cost += current_balance;
    }

    cout << total_cost << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//subission link - https://codeforces.com/contest/1777/submission/356090266


/*
 * APPROACH:
 * Line up all students from least to most smart. Add them to the team one by one until 
 * they know all the topics. Once they do, try removing the least smart student to make 
 * the smartness gap as small as possible while still covering every topic.
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_VAL = 100005;

vector<int> divs[MAX_VAL];

void precompute() {
    for (int i = 1; i < MAX_VAL; i++) {
        for (int j = i; j < MAX_VAL; j += i) {
            divs[j].push_back(i);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> freq(m + 1, 0);
    
    int covered_cnt = 0;
    int min_diff = INT_MAX;
    int left = 0;

    for (int right = 0; right < n; right++) {
        int current_smartness = a[right];

        for (int d : divs[current_smartness]) {
            if (d > m) continue;

            if (freq[d] == 0) {
                covered_cnt++;
            }
            freq[d]++;
        }

        while (covered_cnt == m) {
            min_diff = min(min_diff, a[right] - a[left]);

            int remove_smartness = a[left];
            for (int d : divs[remove_smartness]) {
                if (d > m) continue;

                freq[d]--;
                if (freq[d] == 0) {
                    covered_cnt--;
                }
            }
            left++;
        }
    }

    if (min_diff == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_diff << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

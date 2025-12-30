/*
====================================================
PROBLEM STATEMENT:
====================================================
You are given an integer n and an integer k (k ≥ 2),
along with an array of n positive integers.

Your task is to count the number of unordered pairs
(i, j) such that:
- 1 ≤ i < j ≤ n
- ai × aj is a perfect k-th power

A number is a perfect k-th power if it can be written
as x^k for some integer x.

----------------------------------------------------
PROBLEM LINK:
https://codeforces.com/problemset/problem/1225/D
====================================================
*/

/*
====================================================
APPROACH:
====================================================
Key Idea:
For a product ai × aj to be a perfect k-th power,
the total exponent of every prime factor in the
product must be divisible by k.

Steps:
1. For each number ai, perform prime factorization.
2. Reduce each prime’s exponent modulo k.
3. Store the resulting factorization as "cur".
4. Compute the complementary factorization "need"
   such that:
       cur × need → all exponents divisible by k
5. Use a map to count how many times "need"
   has appeared before.
6. Add that count to the answer.
7. Insert "cur" into the map.

----------------------------------------------------
WHY THIS WORKS:
- Pairing numbers whose prime exponents complement
  each other modulo k ensures the product becomes
  a perfect k-th power.
====================================================
*/

/*
====================================================
TIME & SPACE COMPLEXITY:
====================================================
Time Complexity:
O(n * sqrt(ai))   (prime factorization per element)

Space Complexity:
O(n)              (map storage)
====================================================
*/

/*
====================================================
EXAMPLE:
====================================================
Input:
6 3
1 3 9 8 24 1

Output:
5

Explanation:
There are 5 unordered pairs whose product is a
perfect cube.
====================================================
*/

/*
====================================================
SUBMISSION LINK:
====================================================
(Add your Codeforces submission link here after AC)
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio();

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<vector<pair<int,int>>, long long> mp;
    long long ans = 0;

    for (int x : a) {
        vector<pair<int,int>> cur, need;

        int temp = x;
        for (int p = 2; p * p <= temp; p++) {
            if (temp % p == 0) {
                int cnt = 0;
                while (temp % p == 0) {
                    temp /= p;
                    cnt++;
                }
                cnt %= k;
                if (cnt) {
                    cur.push_back({p, cnt});
                    need.push_back({p, (k - cnt) % k});
                }
            }
        }

        if (temp > 1) {
            int cnt = 1 % k;
            if (cnt) {
                cur.push_back({temp, cnt});
                need.push_back({temp, (k - cnt) % k});
            }
        }

        sort(cur.begin(), cur.end());
        sort(need.begin(), need.end());

        ans += mp[need];
        mp[cur]++;
    }

    cout << ans << '\n';
    return 0;
}

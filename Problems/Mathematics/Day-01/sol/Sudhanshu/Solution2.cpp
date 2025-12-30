#include <bits/stdc++.h>
using namespace std;

const int MAXA = 100000;
int spf[MAXA + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= MAXA; i++)
        spf[i] = i;
    for (int i = 2; i * i <= MAXA; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= MAXA; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    int n, k;
    cin >> n >> k;

    map<vector<pair<int, int>>, long long> freq;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        map<int, int> cnt;
        while (x > 1)
        {
            cnt[spf[x]]++;
            x /= spf[x];
        }

        vector<pair<int, int>> cur, need;

        for (auto &pr : cnt)
        {
            int p = pr.first;
            int r = pr.second % k;
            if (r > 0)
            {
                cur.push_back({p, r});
                need.push_back({p, (k - r) % k});
            }
        }

        sort(cur.begin(), cur.end());
        sort(need.begin(), need.end());

        ans += freq[need];
        freq[cur]++;
    }

    cout << ans << "\n";
    return 0;
}

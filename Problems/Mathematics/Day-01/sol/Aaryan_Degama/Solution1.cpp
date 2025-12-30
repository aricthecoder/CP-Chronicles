// link  :  https://codeforces.com/problemset/submission/1560/355483452

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x, y, pos;
    cin >> x >> y >> pos;

    int cs = 2 * abs(x - y);

    int opp = pos + cs / 2;

    if (pos > cs || y > cs || x > cs) {
        cout << -1 << endl;
        return;
    }

    if (opp > cs)
        opp -= cs;

    cout << opp << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
}

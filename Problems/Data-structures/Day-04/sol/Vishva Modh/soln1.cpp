#include<bits/stdc++.h>
#include<queue>
using namespace std;
typedef unordered_map<int, int> umii;
typedef unordered_map<long long, long long> umll;
typedef unordered_map<char, long long> umci;
typedef vector<pair<int, int>> vpi;
typedef vector<int> vi;
typedef long long ll;
typedef vector<long long> vll;
typedef unordered_map<int , bool> umib;
#define sum(v) accumulate(v.begin(), v.end(), 0)
#define endl '\n'
#define f0(i, n) for(long long i = 0; i < n; i++)
#define f1(i, n) for(long long i = 1; i < n; i++)
#define as(v) sort(v.begin(), v.end())
#define all(x) (x).begin(), (x).end()
#define pb push_back
template<class T> umll frequency(vector<T> &v) {umll freq;for(auto &x:v) freq[x]++; return freq;}
template<class T> umci S_frequency(vector<T> &v) {umci freq;for(auto &x:v) freq[x]++; return freq;}
template <class T> void input(vector<T> &v){for(auto &x:v)cin>>x;}
ll power(ll x, ll y){ ll res = 1; while (y > 0){ if (y & 1) res = (ll)(res*x); y = y>>1; x = (ll)(x*x); } return res; }
void pvll(const vector<long long> &arr){for(auto it : arr){cout << it << " ";}cout << endl;}
void pvi(const vector<int> &arr){for(auto it : arr){cout << it << " ";}cout << endl;}

//function to check score i will use stack data structure
//time complexity = o(n);

//submission link :- https://codeforces.com/contest/1997/submission/355833501


ll checkscore(string s)
{
    ll ans=0;
    stack<ll>st;

    for(ll i=0;i<s.size();i++)
    {
        if(s[i] == '(')
        {
            st.push(i);
        }
        else{
            ll a = st.top();
            ans+= i-a;
            st.pop();
        }
    }
    return ans;
}

void solve(){

//-------------INPUT-------------
    ll n; 
    cin >> n;
    // make an rbs first
    // approach whenever open>0 do it close to make minimum score

    string s;
    cin >> s;


//-------------CODE--------------

    ll open=0;
    ll close=0;

    for(ll i=0;i<n;i++)
    {
        if(s[i] == '(')
        {
            open++;
        }
        else if(s[i] == ')')
        {
            open--;
        }
        else if(s[i] == '_' && open==0)
        {
            s[i] = '(';
            open++;
        }
        else if(s[i] == '_' && open>0)
        {
            s[i] = ')';
            open--;
        }
    }

    cout << checkscore(s) << endl;
    


}


int main(){
    int tt; cin >> tt; while(tt--)
{solve();};
}

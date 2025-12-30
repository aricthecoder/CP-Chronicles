// Submission Link: https://codeforces.com/contest/1997/submission/355835686

/*
So first I made the RBS with minimmum cost by putting closing bracket as soon as we get a opening bracket before it, i.e., closing bracket as early as 
possible(greedy appraoch). After getting corect bracket sequence I put the indexes of '(' in vector o and indexes of ')' in vector c in order they occur. Both 
vector must contain n/2 elements and now for final answer I simply added the difference of each element in o and c at same index to ans to calculate cost 
which was initially zero and then printed the ans.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--) {
        long long n;
        cin>>n;
        string s;
        cin>>s;
        long long a=0;
        for(long long i=0; i<n; i++) {
            if(s[i]=='(') a++;
            if(s[i]==')') a--;
            if(s[i]=='_') {
                if (a>0) {
                    s[i]=')';
                    a--;
                }
                else {
                    s[i]='(';
                    a++;
                }
            }
        }
        long long ans=0;
        vector <long long> o, c;
        for(long long i=0; i<n; i++) {
            if(s[i]=='(') o.push_back(i);
            else c.push_back(i);
        }
        for(long long i=0; i<n/2; i++) ans+=(c[i]-o[i]);
        cout<<ans<<endl;
    }
}

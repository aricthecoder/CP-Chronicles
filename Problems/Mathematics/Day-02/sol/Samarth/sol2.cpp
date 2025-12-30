#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

/*

PROBLEM STATEMENT:
Masha works in an advertising agency. In order to promote the new brand, she wants to conclude contracts with some bloggers. In total, Masha has connections of n different bloggers. Blogger numbered i has ai

followers.

Since Masha has a limited budget, she can only sign a contract with k

different bloggers. Of course, Masha wants her ad to be seen by as many people as possible. Therefore, she must hire bloggers with the maximum total number of followers.

Help her, find the number of ways to select k

bloggers so that the total number of their followers is maximum possible. Two ways are considered different if there is at least one blogger in the first way, which is not in the second way. Masha believes that all bloggers have different followers (that is, there is no follower who would follow two different bloggers).

For example, if n=4
, k=3, a=[1,3,1,2], then Masha has two ways to select 3

bloggers with the maximum total number of followers:

    conclude contracts with bloggers with numbers 1

, 2 and 4. In this case, the number of followers will be equal to a1+a2+a4=6
.
conclude contracts with bloggers with numbers 2
, 3 and 4. In this case, the number of followers will be equal to a2+a3+a4=6

    . 

Since the answer can be quite large, output it modulo 10^9+7.


APPROACH:
well the logic for the ques is easy but the implementaion to make the NCR
in the range of h is hard.
the logic was to count till k and then further count the freq of continued no.
the ans would be sCt .
to make it in range i got the chance to learn modular operations about division
to do that i learned fermat's little theoram to calculate inverse of the denominator
i also learned bin exponantion to calculate a^b in log(b)time which is extreamely
eff way of calculating powers 

Time Complexity:O(n+s+t+logbase2(m))which is O(n) only as log(m) is appx 30;

Submission Link:
https://codeforces.com/contest/1475/submission/355485356



*/

const ll h=1000000007;

ll binexp(int a,int b){
	if(b==1)return a;
	
	ll set=binexp(a,b/2);
	
	set=(set*set)%h;
	if (b&1)
		return (set*a)%h;
	else 
		return set;

}


long long fac(int r){
	ll ans =1;
	while(r>0){
		ans=(ans*r)%h;
		r--;
	}
	return ans;
}

long long comb(int s,int t){
	ll a= fac(s);
	ll b=(fac(s-t)*fac(t))%h;
	return (a*binexp(b,h-2))%h;
}

void solve(){
	int n,k;cin>>n>>k;vector<int> a(n);for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end(),greater<int>());int i=1,freq=1;k--;	
	while(k--){
		if(a[i]==a[i-1])freq++;
		else freq=1;
		i++;
	}
	int t=freq;
	while(i<n){
		if(a[i]==a[i-1])freq++;
		else break;
		i++;
	}
	int s=freq;
	cout<<comb(s,t)<<endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	int t;cin>>t;
	while(t--)
		solve();
	
}

#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

/*
PROLBLEM STATEMENT:
Monocarp had a regular bracket sequence s of length n (n

is even). He even came up with his own way to calculate its cost.

He knows that in a regular bracket sequence (RBS), each opening bracket is paired up with the corresponding closing bracket. So he decided to calculate the cost of RBS as the sum of distances between pairs of corresponding bracket pairs.

For example, let's look at RBS (())(). It has three pairs of brackets:

    (__)__: the distance between brackets at position 1

and at 4 is 4−1=3
;
_()___: the distance is 3−2=1
;
____(): the distance is 6−5=1

    . 

So the cost of (())() is 3+1+1=5.

Unfortunately, due to data corruption, Monocarp lost all characters on odd positions s1,s3,…,sn−1
. Only characters on even positions (s2,s4,…,sn

) remain. For example, (())() turned to _(_)_).

Monocarp wants to restore his RBS by placing brackets on the odd positions. But since the restored RBS may not be unique, he wants to choose one with minimum cost. It's too hard to do for Monocarp alone, so can you help him?

Reminder: A regular bracket sequence is a string consisting of only brackets, such that this sequence, when inserted 1-s and +-s, gives a valid mathematical expression. For example, (), (()) or (()())() are RBS, while ), ()( or ())(() are not.


APPROACH:
my first thought was to just fill in the blanks not to calculate the cost so i did trial & error with few test cases and found that
if(s[i-1]=')')then s[i]must be '(' and vice versa for min cost;
then to calculate the cost i also found a pattern where iterating over odd indices (0 indexing) if s[i]='(' you will add 1 to ans and also increase cost of prev bracket by 2
until you encounter '(' then you will pour the value of keeper into ans and reset value of keeper to 1;


Time Compx:O(n);
Space Compx:O(n);



SUBMISSION LINK:
https://codeforces.com/contest/1997/submission/355680953


*/



void solve(){
	int n;cin>>n;string s;cin>>s;
	ll keeper=1,sum=0;
	for(int i=1;i<n;i+=2){
		if(s[i]==')'){
			sum+=keeper;
			keeper=1;
		}
		else {
			sum+=1;
			keeper+=2;
		}
	}
	cout<<sum<<endl;


}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	int t;cin>>t;
	while(t--)
		solve();
	
}

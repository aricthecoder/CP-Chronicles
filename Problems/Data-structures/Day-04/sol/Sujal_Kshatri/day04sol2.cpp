//submission link - https://codeforces.com/problemset/submission/1912/355802995

/*
Approach:

We start with a number `num`.

From each list, we take numbers from left to right.
If numbers go down first but later go up, we save that part as a "good chunk".

For every good chunk, we remember:
-how much `num` we need to start it
- how much `num` increases after it

Then we sort all chunks by how much `num` they need.
We take chunks one by one if we can afford them.

This way, `num` grows as much as possible.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long num,k;
	cin >> num >> k;
	long long i,j;
	vector<pair<long long,long long>> v;
	for(i=0;i<k;i++)
	{
		long long n;
		cin >> n;
		long long maxi=0,add=0;
		for(j=0;j<n;j++)
		{
			long long x;
			cin >> x;
			add += x;
			maxi = max(maxi,-add);
			if(add>0)
			{
				v.push_back({maxi,add});
				add=0;
			}
		}
	}
	sort(v.begin(),v.end());
	for(auto x:v)
	{
		if(x.first>num) 
		break;
		num += x.second;
	}
	cout << num << endl;
	return 0;
}

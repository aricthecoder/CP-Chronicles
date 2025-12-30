/*
Problem Statement: 
There are n people standing in a circle (n is even). Each person looks at the person standing exactly opposite to them. Given three distinct integers a, b, and c: Person a is looking at person b. Find the person that person c is looking at. If no valid circle can be formed, print -1.

Approach:
If person a looks at b, then the total number of people in the circle is:
n = 2 * |a - b| For person c, if c + n/2 ≤ n, answer = c + n/2, else, answer = c - n/2 If n is zero or any of a, b, or c exceeds n, the configuration is invalid.

Time Complexity:
O(1)

Space Complexity:
O(1)*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long a,b,c;
        cin>>a>>b>>c;
        long n=2*abs(a-b);
        long ans=0;
        if(n==0||n<a||n<b||n<c){
            cout<<-1<<endl;
            continue;
        }
        if(c+(n/2)<=n){
            ans=c+(n/2);
        }
        else{
            ans=c-(n/2);
        }
        cout<<ans<<endl;
    }
    return 0;
}
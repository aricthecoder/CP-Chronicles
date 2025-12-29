/*Problem 
Hossam woke up bored, so he decided to create an interesting array with his friend Hazem.

Now, they have an array a
 of n
 positive integers, Hossam will choose a number ai
 and Hazem will choose a number aj
.

Count the number of interesting pairs (ai,aj)
 that meet all the following conditions:

1≤i,j≤n
;
i≠j
;
The absolute difference |ai−aj|
 must be equal to the maximum absolute difference over all the pairs in the array. More formally, |ai−aj|=max1≤p,q≤n|ap−aq|
.
Input
The input consists of multiple test cases. The first line contains a single integer t
 (1≤t≤100
), which denotes the number of test cases. Description of the test cases follows.

The first line of each test case contains an integer n
 (2≤n≤105
).

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤105
).

It is guaranteed that the sum of n
 over all test cases does not exceed 105
.

Output
For each test case print an integer — the number of interesting pairs (ai,aj)
.
Approach : 
find the largest difference which will be equal to maximum-minimum.
check if all elements are same : if maximum=minimum then all elements same. and required ordered pairs will be simply = n*(n-1). 
if all are not same , then count the occurance of maximum and minimum since only these elements will contribute to required pairs.
and no of pairs=maxcount*mincount*2. the extra 2 is for ordered pairs.
*/
// Codeforces Submission Link:
// https://codeforces.com/contest/1771/submission/355653565






#include <iostream>
#include <climits>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        long long int arr[n];
        long long int mini= INT_MAX;
        long long int cmini=0,cmaxi=0;
        long long int maxi=INT_MIN;
        for(long long int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>maxi){
                maxi=arr[i];
            }
            if(arr[i]<mini){
                mini=arr[i];
            }
        }
        if(maxi==mini){
            cout<<n*(n-1)<<endl;
        }
        else{
        for(long long int i=0;i<n;i++){
            if(arr[i]==maxi) cmaxi++;
            if(arr[i]==mini) cmini++;
        }
        cout<<2*cmaxi*cmini<<endl;
    }
    }
    return 0;
}

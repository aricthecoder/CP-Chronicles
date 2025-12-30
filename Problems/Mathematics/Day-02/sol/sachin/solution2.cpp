/*Masha works in an advertising agency. In order to promote the new brand, she wants to conclude contracts with some bloggers. In total, Masha has connections of n
 different bloggers. Blogger numbered i
 has ai
 followers.

Since Masha has a limited budget, she can only sign a contract with k
 different bloggers. Of course, Masha wants her ad to be seen by as many people as possible. Therefore, she must hire bloggers with the maximum total number of followers.

Help her, find the number of ways to select k
 bloggers so that the total number of their followers is maximum possible. Two ways are considered different if there is at least one blogger in the first way, which is not in the second way. Masha believes that all bloggers have different followers (that is, there is no follower who would follow two different bloggers).

For example, if n=4
, k=3
, a=[1,3,1,2]
, then Masha has two ways to select 3
 bloggers with the maximum total number of followers:

conclude contracts with bloggers with numbers 1
, 2
 and 4
. In this case, the number of followers will be equal to a1+a2+a4=6
.
conclude contracts with bloggers with numbers 2
, 3
 and 4
. In this case, the number of followers will be equal to a2+a3+a4=6
.
Since the answer can be quite large, output it modulo 109+7
.

Input
The first line contains one integer t
 (1≤t≤1000
) — the number of test cases. Then t
 test cases follow.

The first line of each test case contains two integers n
 and k
 (1≤k≤n≤1000
) — the number of bloggers and how many of them you can sign a contract with.

The second line of each test case contains n
 integers a1,a2,…an
 (1≤ai≤n
) — the number of followers of each blogger.

It is guaranteed that the sum of n
 over all test cases does not exceed 1000
.

Output
For each test case, on a separate line output one integer — the number of ways to select k
 bloggers so that the total number of their followers is maximum possible.*/

/*Approach :
  sort the array.
  let total elements be n and no of bloggers to be selected is k.
  mark the element which is the first element in the bloggers included.
  count the occurances of that element, say a.
  count the no of elements greater than that boundary element, say b.
  Since total required was k and b are greater than k , this implies we need to select remaining k-b elements from a. therefore ans will be combitorial(a,k-b).*/






#include <iostream>
#include <algorithm>
using namespace std;
const long long MOD = 1000000007;
long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
long long modInverse(long long a) {
    return power(a, MOD - 2);
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long int n,k;
        cin>>n;
        cin>>k;
        int arr[n];
        long long int count=0;
        long long int big=0;
        for(int i=0;i<n;i++){
                cin>>arr[i];
        }
        if(n==k){
            cout<<1<<endl;
        }else{
            sort(arr,arr+n);
            for(int i=n-1;i>=0;i--){
                if(arr[i]==arr[n-k]){
                    count=(count+1)%MOD;
                }
                if(arr[i]>arr[n-k]){
                    big++;
                }
            }
            k=k-big;
            if(k>(count/2)){
                k=count-k;
            }
            if(k==0){
                cout<<1<<endl;
            }
            else{
            long long int dup=count;
            for(int i=1;i<k;i++){
                count = (count * (dup - i)) % MOD;
                count = (count * modInverse(i + 1)) % MOD;

            }
             cout<<count<<endl;
        }
        }
       
    }
    return 0;
}

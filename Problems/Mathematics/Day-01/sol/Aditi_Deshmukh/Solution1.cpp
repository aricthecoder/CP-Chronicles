//We need to find what numbered person is oppisite to the person numbered 'c'
//On the basis of 'a' and 'b' being opposites
//Time and space complexity are both O(1)


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a,b,c;
	    cin>>a>>b>>c;
	    //eg: 1,4,5

	    int n=abs(a-b)*2;
	    //n=6

	    if(c>n){
	        //5>6 is false
		//c>n then c would be out of the possible numbers
		cout<<"-1"<<endl;
	        continue;
	    }
	   
	    if(c>(n/2)){
		//5>3 implies the number opposite to it is in the lower half
	        cout<<c-(n/2)<<endl;
	    }
	    else{
	        cout<<c+(n/2)<<endl;
	    }

}



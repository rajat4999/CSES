#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long n;
	cin>>n;
	long long ans=0;
	for(int i=0;i<64;i++){
	    long long curr=0;
	    long long p=1LL<<i;
	    long long q=n/(p<<1);
	    curr+=(q*p);
	    long long rem=(n%(p<<1))+1;
	    if(rem>p) curr+=(rem-p);
	    if(curr==0) break;
	    ans+=curr;
	    
	}
	
	cout<<ans<<endl;
	

}

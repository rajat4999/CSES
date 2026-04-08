#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	long long ans=0;
	vector<int>v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=1;i<n;i++) {
	    int temp=max(0,(v[i-1]-v[i]));
	    v[i]+=temp;
	    ans+=(long long) temp;
	}
	cout<<ans<<endl;

}

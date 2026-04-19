#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<long long>v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	std::sort(v.begin(), v.end());
	int mid=(n-1)/2;
	long long size=v[mid];
	long long ans=0;
	for(long long x:v){
	    ans+=abs(x-size);
	}
	cout<<ans<<endl;
	

}

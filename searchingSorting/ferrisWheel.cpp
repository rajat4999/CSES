#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,x;
	cin>>n>>x;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	std::sort(v.begin(), v.end());
	int i=0,j=n-1;
	int ans=0;
	while(i<=j){
	    if(i==j){
	        ans++;
	        break;
	    }
	    if(v[i]+v[j]<=x) {
	        ans++;
	        i++;
	        j--;
	    }
	    else {
	        ans++;
	        j--;
	    }
	}
	cout<<ans<<endl;
	

}

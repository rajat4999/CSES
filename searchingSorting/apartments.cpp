#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int m,n,k;
	cin>>n>>m>>k;
	vector<int>v1(n),v2(m);
	for(int i=0;i<n;i++) cin>>v1[i];
	for(int i=0;i<m;i++) cin>>v2[i];
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int i=0,j=0;
	int ans=0;
	while(i<n and j<m){
	    if(v1[i]<v2[j]-k) i++;
	    else if(v1[i]>v2[j]+k) j++;
	    else {
	        i++;
	        j++;
	        ans++;
	    }
	}
	cout<<ans<<endl;

}

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int>s1,s2;
	if(n%4==0){
	    int i=1,j=i+3;
	    while(i<=n and j<=n){
	        s1.push_back(i);
	        s1.push_back(j);
	        s2.push_back(i+1);
	        s2.push_back(j-1);
	        i=j+1;
	        j=i+3;
	    }
	}
	else if(n%4==3){
	    s1.push_back(3);
	    s2.push_back(1);
	    s2.push_back(2);
	    int i=4,j=i+3;
	    while(j<=n and i<=n){
	        s1.push_back(i);
	        s1.push_back(j);
	        s2.push_back(i+1);
	        s2.push_back(j-1);
	        i=j+1;
	        j=i+3;
	    }
	}
	else {
	    cout<<"NO\n";
	    return 0;
	}
	
	cout<<"YES\n";
	cout<<s1.size()<<endl;
	for(int x:s1) cout<<x<<" ";
	cout<<endl;
	cout<<s2.size()<<endl;
	for(int x:s2) cout<<x<<" ";
	cout<<endl;

}

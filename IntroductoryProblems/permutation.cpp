#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	if(n==1) {
	    cout<<1<<endl;
	    return 0;
	}
	if(n==2 or n==3){
	    cout<<"NO SOLUTION";
	    return 0;
	}
	if(n==4) {
	    cout<<2<<" "<<4<<" "<<1<<" "<<3;
	    return 0;
	}
	int i=1,j=n;
	vector<int>v(n+1);
	for(int k=1;k<=n;k++){
	    if(k%2==1) v[k]=i++;
	    else v[k]=j--;
	}
	int temp=v[1];
	v[1]=v[n];
	v[n]=temp;
	for(int i=1;i<=n;i++) cout<<v[i]<<" ";
	

}

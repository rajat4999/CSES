#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	// your code goes here
    int n;
    cin>>n;
    ll ans=LLONG_MIN;
    ll curr=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        curr+=a;
        ans=max(ans,curr);
        if(curr<0) curr=0;
    }
    cout<<ans<<endl;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(vector<ll>&v,int i,ll sum1,ll sum2){
    if(i>=v.size()) return abs(sum1-sum2);
    ll one=solve(v,i+1,sum1+v[i],sum2);
    ll two=solve(v,i+1,sum1,sum2+v[i]);
    
    return  min(two,one);
}
int main() {
	// your code goes here
    int n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll ans=solve(v,0,0,0);
    cout<<ans<<endl;
}

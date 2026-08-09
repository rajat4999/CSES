#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>findSubset(vector<long long>& nums){
    int n=nums.size();
    vector<ll>ans;
    for(long long mask=0;mask<1<<n;mask++){
        ll sum=0;
        for(int i=0;i<n;i++){
            if(mask & 1<<i) sum+=nums[i];
        }
        ans.push_back(sum);
    }
    return ans;
}
int main() {
	ll n,x;
	cin>>n>>x;
	ll ans=0;
	vector<long long>nums(n);
	for(int i=0;i<n;i++) cin>>nums[i];
	vector<ll>left(nums.begin(),nums.begin()+n/2);
	vector<ll>right(nums.begin()+n/2,nums.end());
	vector<ll>leftSum=findSubset(left);
	vector<ll>rightSum=findSubset(right);
	sort(leftSum.begin(),leftSum.end());
	for(ll r:rightSum){
	    ll t=x-r;
	    auto lo=std::lower_bound(leftSum.begin(), leftSum.end(), t);
	    auto hi=std::upper_bound(leftSum.begin(), leftSum.end(), t);
	    ans+=hi-lo;
	    
	}
	
	cout<<ans<<endl;
	
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
	// your code goes here
    int n,k;
    cin>>n>>k;
    
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    map<int ,int>mp;
    for(int i=0;i<k;i++) mp[nums[i]]++;
    int i=0,j=k;
    vector<int>ans;
    ans.push_back(mp.size());
    while(j<n){
        mp[nums[j]]++;
        mp[nums[i]]--;
        if(mp[nums[i]]<=0) mp.erase(nums[i]);
        ans.push_back(mp.size());
        i++;
        j++;
    }
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

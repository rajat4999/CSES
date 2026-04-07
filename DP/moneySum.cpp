#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
set<int> f(vector<int>&v,int idx,int n,set<int>s,int ans,vector<vector<set<int>>>&dp){
  if(idx>=n) {
    s.insert(ans);
    return s;
  }

  if(!dp[idx][ans].empty()) return dp[idx][ans];
  set<int>accept=f(v,idx+1,n,s,ans+v[idx],dp);
  set<int> reject=f(v,idx+1,n,s,ans,dp);
  set<int> finalSet;
  set_union(accept.begin(),accept.end(),reject.begin(),reject.end(),inserter(finalSet,finalSet.begin()));
  return dp[idx][ans]=finalSet;
  
}
int main() {
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  set<int>temp;
  vector<vector<set<int>>>dp(n+1,vector<set<int>>(1e5+7,temp));
  set<int>s=f(v,0,n,temp,0,dp);
  cout<<s.size()-1<<endl;
  for(int x:s){
    if(x!=0) cout<<x<<" ";
  }
  cout<<endl;
}
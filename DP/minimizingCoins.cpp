#include<bits/stdc++.h>
using namespace std;
int f(int x, vector<int>&coins,vector<int>&dp){
  int n=coins.size();
  if(x==0) return 0;
  // if(x<0) return 1e9;
  if(dp[x]!=-2) return dp[x];
  int ans=1e9;
  for(int i=0;i<n;i++){
    if(x-coins[i]<0) continue;
    ans=min(ans,f(x-coins[i],coins,dp));
  }
  if(ans==1e9) return dp[x]=1e9;
  return dp[x]=1+ans;
}
int main(){
  int n,x;
  cin>>n>>x;
  vector<int>coins(n);
  vector<int>dp(1e6+10,-2);
  for(int i=0;i<n;i++) cin>> coins[i];
  int ans=f(x,coins,dp);
  if(ans>=1e9) cout<<-1<<endl;
  else cout<<ans<<endl;
}
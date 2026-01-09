#include<bits/stdc++.h>
using namespace std;
constexpr long long mod=1000000007;
long long f(int x,vector<long long>&dp){
  if(x==0) return 1;
  if(dp[x]!=-1) return dp[x];
  long long sum=0;
  for(int i=1;i<=6;i++){ 
    if(x-i<0) break;
    sum=(sum%mod+f(x-i,dp)%mod)%mod;
  }
  return dp[x]=sum%mod;
}
int main(){
  int x;
  cin>>x;
  vector<long long>dp(1e6+7,-1);
  long long ans=f(x,dp);
  cout<< ans;
}
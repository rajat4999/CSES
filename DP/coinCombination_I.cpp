#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
// int f(vector<int>&v,int x,vector<int>&dp){
//   if(x==0) return 1;
//   int ans=0;
//   if(dp[x]!=-1) return dp[x];
//   for(int i=0;i<v.size();i++){
//     if(x-v[i]<0) continue;
//     ans=(ans%mod+f(v,x-v[i],dp)%mod)%mod;
//   }
//   return dp[x]=ans%mod;
// }
int main(){
  int n,x;
  cin>>n>>x;
  vector<int>v(n);
  vector<int>dp(x+1,0);
  for(int i=0;i<n;i++) cin>>v[i];
  // int ans=f(v,x,dp);
  sort(v.begin(),v.end());
  dp[0]=1;
  for(int i=1;i<=x;i++){
    for(int c:v){
      if(i-c>=0){
        dp[i]=((long long)dp[i]+(long long)dp[i-c])%mod;
      }
      else break;
    }
  }
  cout<<dp[x]<<endl;
  
}
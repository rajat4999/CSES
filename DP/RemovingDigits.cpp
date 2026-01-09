#include<bits/stdc++.h>
using namespace std;
int f(int n,vector<int>&dp){
  if(n<=9) return 1;
  if(n==0) return 0;
  if(dp[n]!=-1) return dp[n];
  string s=to_string(n);
  int ans=1e9;
  for(int i=0;i<s.size();i++){
    if(s[i]!='0') ans=min(ans,f(n-(s[i]-'0'),dp));
  }
  return dp[n]=1+ans;
}
int ftd(int n){
  vector<int>dp(n+1);
  dp[0]=0;
  for(int i=1;i<=9 && i<=n ;i++) dp[i]=1;
   string s=to_string(n);
  int ans=1e9;
  for(int i=0;i<s.size();i++){
    if(s[i]!='0') ans=min(ans,f(n-(s[i]-'0'),dp));
  }
  return dp[n]=1+ans;


}
int main(){
  int n;
  cin>>n;
  vector<int>dp(n+1,-1);
  cout<<f(n,dp)<<endl;
}
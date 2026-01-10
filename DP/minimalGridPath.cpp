#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
string f(vector<string>&v,int i,int j,int n,vector<vector<string>>&dp){
  if(i>=n || j>=n) return "zzzzz";
  if(i==n-1 && j== n-1) return {v[i][j]};
  if(dp[i][j]!="a") return dp[i][j];
  string right=f(v,i+1,j,n,dp);
  string down=f(v,i,j+1,n,dp);

  return dp[i][j] =v[i][j]+min(right,down);

}
int main() {
  int n;
  cin>>n;
  vector<string>v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  vector<vector<string>>dp(n,vector<string>(n,"a"));
  string ans=f(v,0,0,n,dp);
  cout<<ans<<endl;
}
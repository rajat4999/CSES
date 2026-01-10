#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int f(vector<vector<char>>&grid,int i,int j,int n,vector<vector<int>>&dp){
  if(i>=n || j>=n) return 0;
  if(grid[i][j]=='*') return 0;
  if(i==n-1 && j== n-1) return 1;
  if(dp[i][j]!=-1) return dp[i][j];
  int right=f(grid,i+1,j,n,dp)%mod;
  int down=f(grid,i,j+1,n,dp)%mod;
  return dp[i][j] = (right+down)%mod;
}
int main() { 
  int n;
  cin>>n;
  vector<vector<char>>grid(n,vector<char>(n,'.'));
  vector<vector<int>>dp(n,vector<int>(n,-1));
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>grid[i][j];
  int ans=f(grid,0,0,n,dp);
  cout<<ans<<endl;
}
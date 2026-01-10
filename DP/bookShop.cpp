#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;


// greedy approach gives wrong ans
// int greedy(vector<int>&cost,vector<int>&pages,int x){
//   int ans=0;
//   int n=cost.size();
//   priority_queue<pair<double,pair<int,int>>>pq;
//   for(int i=0;i<n;i++){
//     pq.push({pages[i]/(double)cost[i],{pages[i],cost[i]}});
//   }
  
//   while(!pq.empty() && x!=0){
//     int page=pq.top().second.first;
//     int cost=pq.top().second.second;
//     pq.pop();

//     if(x>=cost){
//       ans+=page;
//       x-=cost;
//     }
//   }
//   return ans;
// }


//solved by dp
// it will aslo give TLE due to stackoverflow
// int f(vector<int>&cost,vector<int>&pages,int idx,int x,vector<vector<int>>&dp){
//   if(idx>=cost.size() || x<=0  ) return 0;
//   if(dp[idx][x]!=-1) return dp[idx][x];
//   int accept=0;
//   if(cost[idx]<=x) accept=pages[idx]+f(cost,pages,idx+1,x-cost[idx],dp);
//   int reject=f(cost,pages,idx+1,x,dp);
//   return dp[idx][x]=max(accept,reject);
// }


int main() {
  int n,x;
  cin>>n>>x;
  vector<int>cost(n);
  vector<int>pages(n);
  for(int i=0;i<n;i++) cin>>cost[i];
  for(int i=0;i<n;i++) cin>>pages[i];
  // int ans=greedy(cost,pages,x);
  // vector<vector<int>>dp(n+7,vector<int>(x+7,-1));
  // int ans=f(cost,pages,0,x,dp);

  int dp[n+1][x+1];
  for(int i=0;i<=n;i++) dp[i][0]=0;
  for(int i=0;i<=x;i++) dp[0][i]=0;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=x;j++){
      dp[i][j]=dp[i-1][j];

      if(j>=cost[i-1]){
        dp[i][j]=max(dp[i][j],dp[i-1][j-cost[i-1]]+pages[i-1]);
      }
    }
  }
  

  cout<<dp[n][x]<<endl;

}           
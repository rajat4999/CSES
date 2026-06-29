#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<string>>dp;
string solve(vector<vector<char>>&grid,int i, int j){
    if(i==n-1 and j==n-1) return  string(1,grid[i][j]);
    if(i>=n or j>=n) return "zz";
    if(dp[i][j]!="0") return dp[i][j];
    return dp[i][j]=grid[i][j]+min(solve(grid,i+1,j),solve(grid,i,j+1));
    
}
int main() {
	// your code goes here
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    dp.assign(n,vector<string>(n,"0"));
    
    cout<<solve(grid,0,0);
    
}

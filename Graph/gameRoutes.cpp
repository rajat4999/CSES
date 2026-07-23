#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007;

int n,m;
int main() {
	// your code goes here
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>indeg(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    
    vector<int>topo;
    queue<int>q;
    for(int i=1;i<n+1;i++) if(indeg[i]==0) q.push(i);
    
    while(!q.empty()){
        int u=q.front();
        q.pop();
        topo.push_back(u);
        for(int v:adj[u]){
            indeg[v]--;
            if(indeg[v]==0) q.push(v);
        }
    }
    
    vector<int>dp(n+1,0);
    
    dp[1]=1;
    
    for(int u:topo){
        for(int v:adj[u]){
            dp[v]=(dp[u]+dp[v])%mod
        }
    }
    
    
    cout<<dp[n]<<endl;
}

#include <bits/stdc++.h>
using namespace std;

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
    
    vector<int>dp(n+1,-1e9);
    vector<int>parent(n+1,-1);
    
    dp[1]=1;
    
    for(int u:topo){
        if(dp[u]!=-1e9){
            for(int v:adj[u]){
                if(dp[v]<1+dp[u]){
                    dp[v]=1+dp[u];
                    parent[v]=u;
                }
            }
        }
    }
    
    if(dp[n]<0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    
    cout<<dp[n]<<endl;
    int curr=n;
    vector<int>path;
    while(curr!=-1){
        path.push_back(curr);
        curr=parent[curr];
    }
    reverse(path.begin(),path.end());
    for(int x:path ) cout<<x<<" ";
    cout<<endl;
}

#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>par;
vector<int>dist;
unordered_set<int>vis;
void bfs(vector<vector<int>>&adj,int src){
    queue<pair<int,int>>q;
    q.push({src,0});
    vis.insert(src);
    while(!q.empty()){
        auto [curr, parent]=q.front();
        q.pop();
        if(dist[curr]>=dist[parent]+1){
            dist[curr]=dist[parent]+1;
            par[curr]=parent;
        }
        
        for(int x:adj[curr]){
            if(!vis.count(x)){
                vis.insert(x);
                q.push({x,curr});
            }
        }
    }
    
}
int main() {
	// your code goes here
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    par.assign(n+1,-1);
    dist.assign(n+1,1e9);
    dist[1]=0;
    
    bfs(adj,1);
    
    if(dist[n]==1e9) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int>ans;
    
    int i=n;
    while(i>0){
        ans.push_back(i);
        i=par[i];
    }
    
  
    
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    
    for(int x:ans) cout<<x<<" ";
    cout<<endl;
    
    
}

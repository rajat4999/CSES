#include <bits/stdc++.h>
using namespace std;
void dfs(int src,vector<bool>& vis,vector<vector<int>>&adj){
    vis[src]=true;
    for(int x:adj[src]){
        if(!vis[x]){
            dfs(x,vis,adj);
        }
    }
}


int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<vector<int>>edges;
	vector<vector<int>>adj1(n+1),adj2(n+1);
	
	for(int i=0;i<m;i++){
	    int u,v,w;
	    cin>>u>>v>>w;
	    edges.push_back({u,v,w});
	    adj1[u].push_back(v);
	    adj2[v].push_back(u);
	}
	
	vector<bool>vis1(n+1,false),vis2(n+1,false);
	
	dfs(1,vis1,adj1);
	dfs(n,vis2,adj2);
	
	vector<long long>dist(n+1,LLONG_MIN);
	dist[1]=0;
	
	for(int i=0;i<n;i++){
	    for(auto x:edges){
	        int u=x[0];
	        int v=x[1];
	        int w=x[2];
	        
	        if(dist[u]==LLONG_MIN) continue;
	        if(dist[u]+1LL*w>1LL* dist[v]) {
	            if(i==n-1){
	                if(vis1[u] and vis2[v]){
	                    cout<<-1<<endl;
	                    return 0;
	                }
	            }
	            else dist[v]=dist[u]+1LL*w;
	        }
	        
	    }
	}
	
	
	cout<< dist[n]<<endl;
	return 0;

}

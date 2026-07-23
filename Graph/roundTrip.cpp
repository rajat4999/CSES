#include <bits/stdc++.h>
using namespace std;
int n,m;

int startIdx=-1,endIdx=-1;
vector<int>parent;
unordered_set<int>vis;


bool dfs(vector<vector<int>>&adj,int src,int par){
    vis.insert(src);
    parent[src]=par;
    
    for(int x:adj[src]){
        if(!vis.count(x)) {
            if(dfs(adj,x,src)) return true;
        }
        else if(x!=par){
            startIdx=x;
            endIdx=src;
            return true;
        }
    }
    
    return false;
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
	
	
	vis.clear();
	parent.assign(n+1,-1);
	
	
	for(int i=1;i<=n;i++){
	    if(!vis.count(i) and dfs(adj,i,-1)) break;
	}
	
	if(startIdx==-1){
	    cout<<"IMPOSSIBLE"<<endl;
	    return 0;
	}
	
	vector<int>ans;
	ans.push_back(startIdx);
	int r=endIdx;
	while(r!=startIdx){
	    ans.push_back(r);
	    r=parent[r];
	}
	ans.push_back(startIdx);

    cout<<ans.size()<<endl;
    for(int x:ans) cout<<x<<" ";
    cout<<endl;
	
	return 0;
	
	
	

}

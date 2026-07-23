#include <bits/stdc++.h>
using namespace std;
int startIdx=-1,endIdx=-1;
int n,m;
vector<int>parent;
vector<bool>vis;
unordered_set<int>st;

bool dfs(vector<vector<int>>&adj,int src,int par){
    vis[src]=true;
    st.insert(src);
    parent[src]=par;
    for(int x:adj[src]){
        if(!vis[x]){
            if(dfs(adj,x,src)) return true;
        }
        
        else{
            if(st.count(x)){
                startIdx=x;
                endIdx=src;
                return true;
            }
        }
    }
    st.erase(src);
    return false;
}
int main() {
	// your code goes here
	cin>>n>>m;
	parent.assign(n+1,-1);
	vis.assign(n+1,false);
	vector<vector<int>>adj(n+1);
	for(int i=0;i<m;i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	}
	bool found=false;
	for(int i=1;i<=n;i++){
	    if(!vis[i] and dfs(adj,i,-1)) {
	        found=true;
	        break;
	    }
	}
	
	if(!found) {
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
	std::reverse(ans.begin(), ans.end());
	
	cout<<ans.size()<<endl;
	for(int x:ans) cout<<x<<" ";
	cout<<endl;
	return 0;
	
	

}

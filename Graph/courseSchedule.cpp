#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int>indegree;
queue<int>q;
vector<bool>vis;

void bfs(vector<vector<int>>&adj,vector<int>&ans){
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        ans.push_back(curr);
        
        for(int x:adj[curr]){
            if(!vis[x]){
                indegree[x]--;
                if(!indegree[x]){
                    q.push(x);
                    vis[x]=true;
                }
            }
        }
    }
}

int main() {
	// your code goes here
	cin>>n>>m;
	vector<vector<int>>adj(n+1);
	indegree.assign(n+1,0);
	vis.assign(n+1,false);
	
	for(int i=0;i<m;i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    indegree[v]++;
	}
	
	
	for(int i=1;i<=n;i++){
	    if(indegree[i]==0){
	        q.push(i);
	        vis[i]=true;
	    }
	    
	}
	vector<int>ans;
	bfs(adj,ans);
	
	if(ans.size()!=n) {
	    cout<<"IMPOSSIBLE"<<endl;
	    return 0;
	    
	}
	
	for(int x:ans){
	    cout<<x<<" ";
	}
	cout<<endl;
	return 0;

}

#include <bits/stdc++.h>
using namespace std;

int n,m;
unordered_set<int>vis;

int bfs(vector<vector<int>>&adj,int src){
    vis.insert(src);
    queue<int>q;
    q.push(src);
    int last=-1;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        last=f;
        for(int x:adj[f]){
            if(!vis.count(x)){
                vis.insert(x);
                q.push(x);
            }
        }
    }
    return last;
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
	
	set<pair<int,int>>st;
	int ans=0;
	int last=-1;
	vis.clear();
	for(int i=1;i<=n;i++){
	    if(!vis.count(i)){
	        if(last!=-1){
	            st.insert({last,i});
	        }
	        ans++;
	        last=bfs(adj,i);
	    }
	    
	}
	
	cout<<ans-1<<endl;
	for(auto x:st){
	    cout<<x.first<<" "<<x.second<<endl;
	}

}

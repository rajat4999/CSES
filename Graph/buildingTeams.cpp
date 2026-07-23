#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>color;
bool flag=true;
void bfs(vector<vector<int>>&adj,int i){
    color[i]=1;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int x:adj[curr]){
            if(color[x]==0){
                color[x]=-color[curr];
                q.push(x);
            }
            else if(color[x]==color[curr]){
                flag=false;
                return;
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
	
	color.assign(n+1,0);
	
	for(int i=1;i<=n;i++){
	    if(color[i]==0){
	        bfs(adj,i);
	    }
	    
	    if(!flag){
	        cout<<"IMPOSSIBLE"<<endl;
	        return 0;
	    }
	}
	
	for(int i=1;i<=n;i++){
	    int x=color[i];
	    if(x==1) cout<<1<<" ";
	    else cout<<2<<" ";
	}
	cout<<endl;
	
	

}

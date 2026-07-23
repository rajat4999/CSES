#include <bits/stdc++.h>
using namespace std;



int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<vector<int>>edges;
	
	for(int i=0;i<m;i++){
	    int u,v,w;
	    cin>>u>>v>>w;
	    edges.push_back({u,v,w});
	}
	
	vector<int>parent(n+1,-1);
	
	
	vector<long long>dist(n+1,0);
	dist[1]=0;
	
	int st=-1;
	
	for(int i=0;i<n;i++){
	    st=-1;
	    for(auto x:edges){
	        int u=x[0];
	        int v=x[1];
	        int w=x[2];
	        
	        if(dist[u]+1LL*w<1LL* dist[v]) {
	            dist[v]=dist[u]+1LL*w;
	            parent[v]=u;
	            st=v;
	            
	            
	        }
	        
	    }
	}
	
	
	if(st==-1)  cout<<"NO"<<endl;
	
	else{
	    cout<<"YES"<<endl;
	    for(int i=0;i<n;i++) st=parent[st];
	    
	    int curr=st;
	    vector<int>path;
	    while(true){
	        path.push_back(curr);
	        curr=parent[curr];
	        
	        if(curr==st){
	            path.push_back(curr);
	            break;
	        }
	    }
	    
	    
	    reverse(path.begin(), path.end());
	    for(int x:path) cout<<x<<" ";
	    cout<<endl;
	}
	
	
	
	
	
	
	return 0;

}

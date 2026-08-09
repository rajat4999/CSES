#include <bits/stdc++.h>
using namespace std;
vector<int>parent,Rank;
int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

bool Union(int a,int b){
    a=find(a);
    b= find(b);
    
    if(a==b) return false;
    if(Rank[a]>=Rank[b]){
        Rank[a]+=Rank[b];
        parent[b]=a;
    }
    
    else {
        Rank[b]+=Rank[a];
        parent[a]=b;
    }
    
    return true;
}
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<pair<int,pair<int,int>>>edges(m);
	for(int i=0;i<m;i++){
	    int u,v,w;
	    cin>>u>>v>>w;
	    edges[i]={w,{u,v}};
	}
	
	sort(edges.begin(),edges.end());
	
	parent.assign(n+1,0);
	Rank.assign(n+1,1);
	
	for(int i=1;i<=n;i++) parent[i]=i;
	
	long long sum=0;
	
	for(auto x:edges){
	    long long  w=1LL*x.first;
	    int u=x.second.first;
	    int v=x.second.second;
	    
	    if(Union(u,v)) sum+=w;
	}
	
	int a=find(1);
	for(int i=2;i<=n;i++){
	    if(find(i)!=a) {
	        cout<<"IMPOSSIBLE";
	        return 0;
	    }
	}
	
	cout<<sum<<endl;
	
	

}

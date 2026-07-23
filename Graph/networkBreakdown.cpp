#include <bits/stdc++.h>
using namespace std;
vector<int>parent,Size;

int find(int x){
    if(x==parent[x]) return x;
    return parent[x]=find(parent[x]);
}

int Union(int a,int b){
    a=find(a);
    b=find(b);
    
    if(a==b) return -1;
    
    if(Size[a]>=Size[b]){
        Size[a]+=Size[b];
        parent[b]=a;
    }
    else {
        Size[b]+=Size[a];
        parent[a]=b;
    }
    
    return max(Size[a],Size[b]);
}
int main() {
	// your code goes here
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>>edges;
	parent.assign(n+1,0);
	Size.assign(n+1,1);
	for(int i=1;i<=n;i++) parent[i]=i;
	int s=1;
	for(int i=0;i<m;i++){
	    int a,b;
	    cin>>a>>b;
      if(a>b) swap(a,b);
	    edges.push_back({a,b});
	    
	}
	vector<pair<int,int>>rem(k);
	set<pair<int,int>>st;
	for(int i=0;i<k;i++){
	    int a,b;
	    cin>>a>>b;
      if(a>b) swap(a,b);
	    rem[i]={a,b};
	    st.insert({a,b});
	}
	
	for(auto x:edges){
	    if(st.count({x[0],x[1]})) continue;
	    int temp=Union(x[0],x[1]);
	    if(temp!=-1) n--;
	}
	
	vector<int>ans;
	
	for(int i=k-1;i>=0;i--){
      ans.push_back(n);
	    int temp=Union(rem[i].first,rem[i].second);
	    if(temp!=-1){
	        n--;
	    }
	}
	

	
	
	for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
	
// 	int maxi=*std::max_element(size.begin(), size.end());
	
// 	cout<<maxi<<endl;
	

}

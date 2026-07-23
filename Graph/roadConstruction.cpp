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
	int n,m;
	cin>>n>>m;
	parent.assign(n+1,0);
	Size.assign(n+1,1);
	for(int i=1;i<=n;i++) parent[i]=i;
	int s=1;
	for(int i=0;i<m;i++){
	    int a,b;
	    cin>>a>>b;
	    int ans=Union(a,b);
	    if(ans!=-1) {
	        n--;
	        s=max(s,ans);
	    }
	    
	    cout<<n<<" "<<s<<endl;
	    
	}
	
// 	int maxi=*std::max_element(size.begin(), size.end());
	
// 	cout<<maxi<<endl;
	

}

#include <bits/stdc++.h>
using namespace std;
void tower(int n,int a,int b,int c,vector<pair<int,int>>&v){
    if(n==1){
        v.push_back({a,c});
        return;
    }
    tower(n-1,a,c,b,v);
    v.push_back({a,c});
    tower(n-1,b,a,c,v);
}
int main() {
	// your code goes here
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    tower(n,1,2,3,v);
    cout<<v.size()<<endl;
    for(auto x:v){
        cout<<x.first<<" "<<x.second<<endl;
    }
}

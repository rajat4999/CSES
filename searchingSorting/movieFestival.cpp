#include <bits/stdc++.h>
using namespace std;
static bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    return a.second<b.second;
}
int main() {
	// your code goes here
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    int ans=1;
    int i=0;
    while(i<n){
        int j=i+1;
        while(j<n and v[j].first<v[i].second) j++;
        if(j<n){
            ans++;
        }
            i=j;
    }
    cout<<ans<<endl;
}

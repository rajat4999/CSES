#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n;
    cin>>n;
    vector<int>v(n+1);
    int idx=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v[x]=idx;
        idx++;
    }
    int ans=1;
    int prev=-1;
    for(int i=1;i<=n;i++){
        if(v[i]<prev){
            ans++;
        }
        prev=v[i];
    }
    cout<<ans<<endl;
}

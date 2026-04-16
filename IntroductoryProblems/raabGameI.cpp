#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    if(a+b>n){
        cout<<"NO"<<endl;
        return;
    }
    if((a+b)>0 and (a==0 or b==0)) {
        cout<<"NO"<<endl;
        return;
    }
    int k=a+b;  //no. of non tie
    vector<int>p1;
    vector<int>p2;
    if(k>0){
        for(int i=1;i<=k;i++){
            p1.push_back(i);
            p2.push_back(i);
        }
        // right rotate p1 by a unit
        reverse(p1.begin(), p1.end() - a); 
        reverse(p1.end() - a, p1.end());
        reverse(p1.begin(), p1.end());
    }
    for(int i=k+1;i<=n;i++){
        p1.push_back(i);
        p2.push_back(i);
    }
    cout<<"YES"<<endl;
    for(int i=0;i<p1.size();i++) cout<<p1[i]<<" ";
    cout<<endl;
    for(int i=0;i<p1.size();i++) cout<<p2[i]<<" ";
    cout<<endl;
    
    
    
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
        
    }
}

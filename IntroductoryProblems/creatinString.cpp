#include <bits/stdc++.h>
using namespace std;
void solve(string& s,string temp,vector<string>&ans){
    if(s==""){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<s.size();i++){
        if(i>0 and s[i]==s[i-1]) continue;
        string l=s.substr(0,i);
        string r=s.substr(i+1);
        string x=l+r;
        solve(x,temp+s[i],ans);
    }
}
int main() {
	// your code goes here
    string s;
    cin>>s;
    vector<string>ans;
    sort(s.begin(),s.end());
    string temp="";
    solve(s,temp,ans);
    cout<<ans.size()<<endl;
    for(string x:ans) cout<<x<<endl;
    
}

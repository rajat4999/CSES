#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    string s;
    cin>>s;
    int n=s.size();
    unordered_map<char,int>mp;
    for(char x:s) mp[x]++;
    int o=0;
    char oc;
    for(auto x:mp){
        if(x.second%2!=0){
            o++;
            oc=x.first;
        }
    }
    if(o>1) {
        cout<<"NO SOLUTION";
        return 0;
    }
    mp[oc]--;
    if(mp[oc]==0) mp.erase(oc);
    string s1="",s2="";
    for(auto x:mp){
        int i=x.second;
        while(i>0){
            if(i%2==0){
                s1+=x.first;
            }
            else s2+=x.first;
            i--;
        }
    }
    reverse((s2).begin(), (s2).end());
    if(o==1) s1+=oc;
    s1+=s2;
    cout<<s1<<endl;
}

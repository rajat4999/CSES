#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>dp;
int solve(string& s1,string &s2,int i,int j){
    if(i==n) return m-j;
    if(j>=m) return n-i;
    if(dp[i][j]!=-1) return dp[i][j];
     if(s1[i]==s2[j]) return dp[i][j]=solve(s1,s2,i+1,j+1);
     else{
        return  dp[i][j]=1+min({solve(s1,s2,i+1,j+1),solve(s1,s2,i+1,j),solve(s1,s2,i,j+1)});
     }
}
int main() {
	// your code goes here
	string s1,s2;
	cin>>s1>>s2;
	n=s1.size();
	m=s2.size();
	dp.assign(n+1,vector<int>(m+1,-1));
	cout<<solve(s1,s2,0,0)<<endl;
	

}

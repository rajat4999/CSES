#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<vector<vector<ll>>>>dp;
ll solve(string & s,int i,int tight,int prev,int lz){
  if(i==s.size()) return 1;
  int limit=(tight)?s[i]-'0':9;
  ll ans=0;
  if(dp[i][tight][prev][lz]!=-1) return dp[i][tight][prev][lz];
  for(int d=0;d<=limit;d++){
    int nextTight=tight and(d==limit);
    if(lz and d==0) ans+=solve(s,i+1,nextTight,10,1);
    else {
      if(d!=prev) ans+=solve(s,i+1,nextTight,d,0);
    }
  }
  return dp[i][tight][prev][lz]= ans;
}
void countingNumbers(ll a,ll b){  
  string num1=to_string(a);
  string num2=to_string(b);
  
  dp.clear();
  dp.resize(num1.size(),vector<vector<vector<ll>>>(2,vector<vector<ll>>(11,vector<ll>(2,-1))));
  ll ans1=solve(num1,0,1,10,1);
  
  dp.clear();
  dp.resize(num2.size(),vector<vector<vector<ll>>>(2,vector<vector<ll>>(11,vector<ll>(2,-1))));
  ll ans2=solve(num2,0,1,10,1);
  ll valid=1;
  for(int i=1;i<num1.size();i++){
    if(num1[i-1]==num1[i]){
      valid=0;
      break;
    }
  }
  cout<<ans2-ans1+valid<<endl;
}

int main(){
  ll a,b;
  cin>>a>>b;
  countingNumbers(a,b);
}
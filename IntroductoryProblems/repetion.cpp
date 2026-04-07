#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin>>s;
  n=s.size();
  int i=0,j=1;
  int ans=1;
  while(j<n){
      bool flag=false;
      while(s[i]==s[j]) {
          flag=true;
          j++;
      }
      
      ans=max(j-i,ans);
      if(flag) {
          i=j-1;
      }
      i++;
      j++;
  }
  cout<<ans<<endl;
}
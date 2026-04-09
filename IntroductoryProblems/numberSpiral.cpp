#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define ll long long
int main() {
  int t;
  cin>>t;
  while(t--){
    ll y,x;
    cin>>y>>x;
    ll z=max(y,x);
    ll up=z*z;
    ll lo=(z-1)*(z-1);
    if(z%2==0){
      if(z==y){
        cout<<up-x+1<<endl;
      }
      else cout<<lo+y<<endl;
    }
    else{
      if(z==y){
        cout<<lo+x<<endl;
      }
      else cout<<up-y+1<<endl;
    }
  }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long sum=(1LL*n*(n+1))/2;
  for(int i=0;i<n-1;i++){
    int temp;
    cin>>temp;
    sum-=(long long)temp;
  }
  cout<<sum<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n;
    cin>>n;
    int div=5;
    int ans=0;
    int curr=1;
    while(curr>0){
        curr=n/div;
        ans+=curr;
        div*=5;
    }
    cout<<ans<<endl;
}

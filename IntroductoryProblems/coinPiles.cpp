#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        if((a+b)%3==0 and a<=2*b and b<=2*a) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

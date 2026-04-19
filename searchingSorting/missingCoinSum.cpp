#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n;
    cin>>n;
    vector<long long>v;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        v.push_back(x);
    }
    std::sort(v.begin(), v.end());
    long long maxi=1;
    for(long long x:v){
        if(x>maxi)break;
        maxi+=x;
    }
    cout<<maxi<<endl;
}

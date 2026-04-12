#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i=0;i<pow(2,n);i++){
        int num=i;
        num=num^(num>>1);
        bitset<16>bin(num);
        string s=bin.to_string();
        cout<<s.substr(16-n,n)<<endl;
    }

}

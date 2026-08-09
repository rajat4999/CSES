#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n,k;
    cin>>n>>k;
    vector<long long>nums(n);
    long long a,b,c,x;
    cin>>x>>a>>b>>c;
    nums[0]=x;
    for(int i=1;i<n;i++){
        nums[i]=(nums[i-1]*a+b)%c;
        
    }
    
    long long Xor=0;
    for(int i=0;i<k;i++ ){
        Xor^=nums[i];
    }
    long long sum=Xor;
    
    int i=0,j=k;
    while(j<n){
        sum^=nums[i];
        sum^=nums[j];
        Xor^=sum;
        i++;
        j++;
    }
    
    // for(int x:nums) cout<<x<<" ";
    cout<<Xor<<endl;
}

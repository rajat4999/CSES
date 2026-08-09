#include <bits/stdc++.h>
using namespace std;
#define ll long long


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
    
    deque<int>dq;
    for(int i=0;i<n;i++){
        while(!dq.empty() and dq.front()<=i-k) dq.pop_front();
        while(!dq.empty() and nums[dq.back()]>=nums[i]) dq.pop_back();
        dq.push_back(i);
        if(!dq.empty() and i>=k-1) Xor^=nums[dq.front()];
    }
    
    // for(int x:nums) cout<<x<<" ";
    cout<<Xor<<endl;
}

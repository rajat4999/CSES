// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	// your code goes here
//     int n,k;
//     cin>>n>>k;
//     vector<long long>nums(n);
//     long long a,b,c,x;
//     cin>>x>>a>>b>>c;
//     nums[0]=x;
//     for(int i=1;i<n;i++){
//         nums[i]=(nums[i-1]*a+b)%c;
        
//     }
    
//     long long Xor=0;
//     vector<int>mp(32,0);
//     for(int i=0;i<k;i++ ){
//         for(int j=0;j<32;j++){
//             if(nums[i] & (1<<j)) mp[j]++;
//         }
//         Xor|=nums[i];
//     }
//     long long sum=Xor;
    
//     int i=0,j=k;
//     while(j<n){
//         long long curr=0;
//         for(int l=0;l<32;l++){
//             if(nums[i] &(1<<l)) mp[l]--;
//             if(nums[j]&(1<<l)) mp[l]++;
//             if(mp[l]>0)curr+=(1<<l);
//         }
//         Xor^=curr;
//         i++;
//         j++;
        
        
//     }
    
//     // for(int x:nums) cout<<x<<" ";
//     cout<<Xor<<endl;
// }


#include <bits/stdc++.h>
using namespace std;
#define ll long long
stack<pair<ll,ll>>s1,s2;

void add(ll val){
    ll currOr=(s1.empty())?val:s1.top().second|val;
    s1.push({val,currOr});
}

void Remove(){
    if(s2.empty()){
        while(!s1.empty()){
            ll curr=(s2.empty())?s1.top().first:s1.top().first|s2.top().second;
            s2.push({s1.top().first,curr});
            s1.pop();
        }
    }
    if(!s2.empty()) s2.pop();
}

ll getOr(){
    if(s1.empty() and !s2.empty()) return s2.top().second;
    if(s2.empty() and !s1.empty()) return s1.top().second;
    if(s1.empty() and s2.empty()) return 0;
    return s1.top().second | s2.top().second;
}

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
    
    for(int i=0;i<k;i++){
        add(nums[i]);
    }
    
    Xor^=getOr();
    for(int i=k;i<n;i++){
        Remove();
        add(nums[i]);
        Xor^=getOr();
        
    }
    
    // for(int x:nums) cout<<x<<" ";
    cout<<Xor<<endl;
}


#include <bits/stdc++.h>
using namespace std;
multiset<int>Right;
multiset<int,greater<int>>Left;

void balance(){
    if(Left.size()>Right.size()+1){
        int val=*Left.begin();
        Left.erase(Left.begin());
        Right.insert(val);
        
    }
     else if(Right.size()>Left.size()){
        int val=*Right.begin();
        Right.erase(Right.begin());
        Left.insert(val);
    }
    
}

void add(int x){
    if(Left.empty() or *Left.begin()>=x) Left.insert(x);
    else Right.insert(x);
    balance();
    
   
    
}

int getMedian(){
    return *Left.begin();
}
int main() {
	// your code goes here
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<int>ans;
    for(int i=0;i<k;i++){
        add(nums[i]);
    }
    ans.push_back(getMedian());
    int i=0,j=k;
    while(j<n){
        int prev=nums[i];
        int nxt=nums[j];
        if(prev<=*Left.begin()){
            auto it=Left.find(prev);
            if(it!=Left.end()){
                Left.erase(it);
            }
        }
        else {
            auto it=Right.find(prev);
            if(it!=Right.end()){
                Right.erase(it);
            }
        }
        
        balance();
        
        add(nxt);
        
        ans.push_back(getMedian());
        i++;
        j++;
        
    }
    
    for(int x: ans) cout<<x<<" ";
    
}

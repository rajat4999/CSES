#include <bits/stdc++.h>
using namespace std;
// int ans;
vector<string>board(8);
bool isSafe(int i,int j){
    for(int k=0;k<=j;k++){
        if(board[i][k]=='Q') return false;
    }
    for(int k=0;k<=i;k++){
        if(board[k][j]=='Q') return false;
    }
    
    for(int r=i,c=j;r>=0 and c>=0; r--,c--){
        if(board[r][c]=='Q') return false;
    }
    for(int r=i,c=j;r>=0 and c<8; r--,c++){
        if(board[r][c]=='Q') return false;
    }
    
    return true;
    
}

void solve(int i,int n,int& ans){
    if(i==n){
        ans++;
        return;
    }
    for(int j=0;j<n;j++){
        if(isSafe(i,j) and board[i][j]!='*'){
            board[i][j]='Q';
            solve(i+1,n,ans);
            board[i][j]='.';
            // ans--;
        }
    }
    // ans--;
}

int main() {
	// your code goes here
    string temp;
    for(int i=0;i<8;i++) {
        cin>>temp;
        board[i]=temp;
    }
    int ans=0;
    solve(0,8,ans);
    cout<<ans;
    
}

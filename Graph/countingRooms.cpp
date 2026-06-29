#include <bits/stdc++.h>
using namespace std;

int n,m;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void bfs(vector<vector<char>>&grid,int i,int j){
    grid[i][j]='*';
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        auto [r,c]=q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nr=r+dir[i][0];
            int nc=c+dir[i][1];
            if(nr<0 or nc<0 or nr>=n or nc>=m or grid[nr][nc]!='.') continue;
            q.push({nr,nc});
            grid[nr][nc]='*';
        }
        
    }
}
int solve(vector<vector<char>>&grid){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                ans++;
                bfs(grid,i,j);
            }
        }
    }
    return ans;
}
int main() {
	// your code goes here
	cin>>n>>m;
	vector<vector<char>>grid(n,vector<char>(m,'.'));
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        cin>>grid[i][j];
	    }
	}
	
	cout<<solve(grid)<<endl;

}

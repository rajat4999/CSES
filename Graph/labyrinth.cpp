#include <bits/stdc++.h>
using namespace std;
int n,m;
int endi,endj;
char d[4]={'D','U','R','L'};
int dir[4][3]={{1,0,0},{-1,0,1},{0,1,2},{0,-1,3}};
void bfs(vector<vector<char>>&grid,int i,int j){
    int ans=0;
    bool found=false;;
    queue<pair<int,int>>q;
    q.push({i,j});
    grid[i][j]='*';
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        int r=x.first;
        int c=x.second;
        if(r==endi and c==endj){
            found=true;
            break;
        }
        for(auto x:dir){
            int nr=r+x[0];
            int nc=c+x[1];
            if(nr<0 or nc<0 or nr>=n or nc>=m or( grid[nr][nc]!='.' and grid[nr][nc]!='B')) continue;
            ans++;
            grid[nr][nc]=d[x[2]];
            q.push({nr,nc});
            
        }
    }
    
    if(found){
        cout<<"YES"<<endl;
        string path="";
        int r=endi,c=endj;
        while(r!=i or c!=j){
            char move=grid[r][c];
            path+=move;
            if(move=='U') r++;
            else if(move=='D') r--;
            else if(move=='L') c++;
            else c--;
        }
        std::reverse(path.begin(), path.end());
        
        cout<<path.size()<<endl;
        cout<<path<<endl;
        
    }
    else{
        cout<<"NO"<<endl;
    }
    
    
}

int main() {
	// your code goes here
	cin>>n>>m;
	vector<vector<char>>grid(n,vector<char>(m,'.'));
	
	int starti,startj;
	for(int i=0;i<n;i++) {
	    for(int j=0;j<m;j++){
	        cin>>grid[i][j];
	        if(grid[i][j]=='A') {
	            starti=i;
	            startj=j;
	        }
	        else if(grid[i][j]=='B'){
	            endi=i;
	            endj=j;
	        }
	    }
	}
	bfs(grid,starti,startj);

}

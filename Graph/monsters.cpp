#include <bits/stdc++.h>
using namespace std;


int n,m;
string d="DURL";
int dir[4][3]={{1,0,0},{-1,0,1},{0,1,2},{0,-1,3}};
vector<vector<int>>dist;
vector<vector<bool>>vis;
queue<pair<int,int>>q;
int iA,jA;


void multiBFS(vector<vector<char>>grid){
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];
                
                if(nr<0 or nc<0 or nr>=n or nc>=m or grid[nr][nc]=='#') continue;
                if(!vis[nr][nc]){
                    dist[nr][nc]=1+dist[r][c];
                    vis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
            
            
        }
    }
}

vector<vector<int>>direction(n,vector<int>(m,0));

void bfs(vector<vector<char>>grid,int i, int j){
    bool found=false;
    queue<pair<int,int>>q;
    q.push({i,j});
    direction[i][j]=0;
    int endi,endj;
    while(!q.empty()){
        auto [r,c]=q.front();
        q.pop();
        
        if(r==n-1 or c==m-1 or r==0 or c==0){
            found=true;
            endi=r;
            endj=c;
            break;
        }
        
        for(auto x:dir){
            int nr=r+x[0];
            int nc=c+x[1];
            if(nr<0 or nc<0 or nr>=n or nc>=m or grid[nr][nc]!='.' or dist[nr][nc]<=1+direction[r][c]) continue;
            grid[nr][nc]=d[x[2]];
            direction[nr][nc]=1+direction[r][c];
            q.push({nr,nc});
            
        }
    }
    
    if(found){
        cout<<"YES"<<endl;
        string path;
        int r=endi,c=endj;
        while(r!=iA or c!=jA){
            path+=grid[r][c];
            char move=grid[r][c];
            if(move=='U') r++;
            else if(move=='D') r--;
            else if(move=='L') c++;
            else if(move=='R') c--;
            
        }
        
        cout<<path.size()<<endl;
        std::reverse(path.begin(), path.end());
        cout<<path<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
}


int main() {
	// your code goes here
    cin>>n>>m;
    dist.assign(n,vector<int>(m,1e9));
    direction.assign(n,vector<int>(m,0));
    
    vector<vector<char>>grid(n,vector<char>(m,'.'));
    vis.clear();
    vis.assign(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='M') {
                q.push({i,j});
                vis[i][j]=true;
                dist[i][j]=0;
                
            }
            else if(grid[i][j]=='A') {
                iA=i;
                jA=j;
            }
        }
    }
    
    multiBFS(grid);
    vis.assign(n,vector<bool>(m,false));
    bfs(grid,iA,jA);
    
    return 0;
    
    
    
}

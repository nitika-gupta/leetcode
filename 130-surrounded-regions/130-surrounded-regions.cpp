class Solution {
public:
    void dfs1(vector<vector<char>>& grid,vector<vector<int>>& vis,int r,int c, int n ,int m){
        if(r<0 || c<0 || c>m-1 || r> n-1 )
                return;
        if(grid[r][c]!='O' ||  vis[r][c]!=0)
            return;
        vis[r][c]=1;
        grid[r][c]='X';
        dfs1(grid,vis,r,c+1,n,m);
         dfs1(grid,vis,r+1,c,n,m);
         dfs1(grid,vis,r-1,c,n,m);
         dfs1(grid,vis,r,c-1,n,m);
        
    }
    
     void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int r,int c, int n ,int m){
        if(r<0 || c<0 || c>m-1 || r> n-1 )
                return;
        
        if(grid[r][c]!='O' || vis[r][c]==1)
            return;
        
        vis[r][c]=1;
        dfs(grid,vis,r,c+1,n,m);
         dfs(grid,vis,r+1,c,n,m);
         dfs(grid,vis,r-1,c,n,m);
         dfs(grid,vis,r,c-1,n,m);
    }
    
    void solve(vector<vector<char>>& grid) {
        int n= grid.size();
        int m =grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1 && !vis[i][j])
                    
                    dfs(grid,vis,i,j,n,m);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='O'){
                    dfs1(grid,vis,i,j,n,m);
                }
            }
        }
        
        
    }
};
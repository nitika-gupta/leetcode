class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int r,int c,int n,int m){
        
        
        if(r<0 || r>=n || c<0 || c>=m ){
            return;
        }
        if(grid[r][c]=='0' || vis[r][c])
            return;
        
        vis[r][c]=1;
        
        dfs(grid,vis,r-1,c,n,m);
        dfs(grid,vis,r+1,c,n,m);
        dfs(grid,vis,r,c-1,n,m);
        dfs(grid,vis,r,c+1,n,m);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n =grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]!='0'){
                    count++;
                    dfs(grid,vis,i,j,n,m);
                }
            }
        }
        return count;
    }
};
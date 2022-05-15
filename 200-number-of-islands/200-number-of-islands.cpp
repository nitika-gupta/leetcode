class Solution {
public:
    
    void dfs(int r, int c,vector<vector<char>>& grid,vector<vector<int>>& vis){
       // cout<<"hi";
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]=='0' || vis[r][c]==1){
            return;
        }
        vis[r][c]=1;
        
        dfs(r-1,c,grid,vis);
        dfs(r,c-1,grid,vis);
        dfs(r+1,c,grid,vis);
        dfs(r,c+1,grid,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    //cout<<count;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
        
    }
};
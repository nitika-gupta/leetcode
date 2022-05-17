class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int &c ,int &ans){
        if(i<0|| j<0|| i>=grid.size()|| j>=grid[i].size() || vis[i][j]==1 ||  grid[i][j]==0){
            
            return;
        }
        vis[i][j]=1;
        c++;
       
        dfs(i-1,j,grid,vis,c,ans);
        dfs(i,j-1,grid,vis,c,ans);
        dfs(i+1,j,grid,vis,c,ans);
        dfs(i,j+1,grid,vis,c,ans);
        
            
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=INT_MIN;
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    c=0;
                    dfs(i,j,grid,vis,c,ans);
                    if(c>ans)
                        ans=c;
                    cout<<ans<<" ";
                }
            }
        }if(ans==INT_MIN)
            return 0;
        return ans;
    }
};
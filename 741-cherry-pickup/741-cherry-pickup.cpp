class Solution {
public:
    int solve(int r1,int c1,int r2,int c2,vector<vector<int>>& grid,vector<vector<vector<vector<int>>>> & dp){
        if(r1>=grid.size() || r2>=grid.size() || c1>=grid[0].size() || c2>=grid[0].size() || grid[r1][c1]==-1 ||                    grid[r2][c2]==-1){
            return -1e9;
        }
        
        if(r1==grid.size()-1  && c1==grid[0].size()-1   ){
            return dp[r1][c1][r2][c2]= grid[r1][c1];
        }
        if(dp[r1][c1][r2][c2]!=-1)
            return dp[r1][c1][r2][c2];
        int cherries=0;
        if(r1==r2 && c1==c2){
            cherries+=grid[r1][c1];
            
        }
        else{
            cherries+=grid[r1][c1] + grid[r2][c2];
        }
        
        int x=solve(r1+1,c1,r2+1,c2,grid,dp);
        int y=solve(r1,c1+1,r2,c2+1,grid,dp);
        int z=solve(r1+1,c1,r2,c2+1,grid,dp);
        int w=solve(r1,c1+1,r2+1,c2,grid,dp);
        cherries+=max({x,y,z,w});
        return dp[r1][c1][r2][c2]=cherries;
        
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        int ans= solve(0,0,0,0,grid,dp);
        if(ans<0)
            return 0;
        return ans;
    }
};
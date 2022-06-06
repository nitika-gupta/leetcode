class Solution {
public:
    int solve(int r1,int c1,int c2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int n=grid.size();
        int m=grid[0].size();
        int r2=r1;
        if( r1>=n || c1<0 || c1>=m || c2<0 || c2>=m || r2>=n){
            return 0;
        }
        int cherries=0;
        if(r1 ==n-1 && r2==n-1 && c1==c2){
            return grid[r1][c1];
        }
        if(r1 ==n-1 && r2==n-1 && c1!=c2){
            return grid[r1][c1] + grid[r2][c2];
        }
        if(dp[r1][c1][c2]!=-1)
            return dp[r1][c1][c2];
        // if(r2==n-1){
        //     return grid[r2][c2];
        // }
        if(r1==r2 && c1==c2){
            cherries+=grid [r1][c1];
        }
        else{
            cherries+=grid[r1][c1] + grid[r2][c2];
        }
        
        int f1=solve(r1+1,c1-1,c2-1,grid,dp);
        int f2=solve(r1+1,c1-1,c2,grid,dp);
        int f3=solve(r1+1,c1-1,c2+1,grid,dp);
        int f4=solve(r1+1,c1,c2-1,grid,dp);
        int f5=solve(r1+1,c1,c2,grid,dp);
        int f6=solve(r1+1,c1,c2+1,grid,dp);
        int f7=solve(r1+1,c1+1,c2-1,grid,dp);
        int f8=solve(r1+1,c1+1,c2,grid,dp);
        int f9=solve(r1+1,c1+1,c2+1,grid,dp);
                
        cherries+=max({f1,f2,f3,f4,f5,f6,f7,f8,f9});
        return dp[r1][c1][c2]=cherries;
        
        
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(m,-1))));
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,grid,dp);
    }
};
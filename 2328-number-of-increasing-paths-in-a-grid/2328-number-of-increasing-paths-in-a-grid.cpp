class Solution {
public:
    int mod = 1e9+7;
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>> & dp){
        
//         if(i<0 || j>=grid[0].size() || i>=grid.size() || j<0 ){
//             return 0;
//         }
    
       if(dp[i][j]!=-1)
           return dp[i][j];
        
        
        int x[]={1,0,-1,0};
        int y[]={0,1,0,-1};
        int count=1;
        for(int k=0;k<4;k++){
            
            int ni= x[k]+i;
            int nj= y[k]+j;
            
            
             if(ni>=0 &&  nj<grid[0].size() &&  ni< grid.size() && nj>=0 ){
                
                 if(grid[i][j]> grid[ni][nj]){
                     count= (count+solve(ni,nj,grid,dp))%mod;
                 }
        }
        }
        return dp[i][j]=count;
        
        
        
        
        
//         if(grid[i][j]>prev){
       
//         return dp[i][j][prev] = ( 1 +solve(i+1,j,grid,dp,grid[i][j]) + solve(i,j+1,grid,dp,grid[i][j]) + solve(i-1,j,grid,dp,grid[i][j]) + solve(i,j-1,grid,dp,grid[i][j]));
            
//         }
//         else 
//             return  0;

//         ;
        
        
        
        
        
    }
    int countPaths(vector<vector<int>>& grid) {
       vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
       // vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(1e5,-1)));
        
        long long int count =0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                 count=(count+  solve(i,j,grid,dp))%mod;
            }
        }
       return count;
        
    }
};
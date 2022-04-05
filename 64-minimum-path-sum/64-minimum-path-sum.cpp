class Solution {
public:
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
       
        if(i==0 && j==0){
           
            return grid[i][j];
        }
     //  cout<<i<<" "<<j<<" "<<endl;
        if(i<0 || j<0)
            return 1e9;
       
        if(dp[i][j]!=-1)
            return dp[i][j];
           int up = grid[i][j] + f(i-1,j, grid,dp);
     
        
           int left= grid[i][j] + f(i,j-1, grid,dp);
        return dp[i][j]= min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        
//         dp[n-1][m-1]=grid[n-1][m-1];
        
//         for(int i=n-1;i>=0;i--){
//             for(int j=m-1;j>=0;j--){
                
//                 if(i==n-1 && j==m-1){
//                     dp[i][j]=grid[i][j];
//                     continue;
//                 }
                
//                 if(i<n-1 && j<m-1){
//                     dp[i][j]= grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
//                 }
//                 else if(i<n-1 && j>=m-1){
//                     dp[i][j]=grid[i][j] +dp[i+1][j];
//                 }
//                 else if(i>=n-1 && j<m-1){
//                     dp[i][j]=grid[i][j] + dp[i][j+1];
//                 }
//             }
//         }
//         return dp[0][0];
        
        int sum=0;
        int mini=INT_MAX;
        
        int x=f(n-1,m-1,grid,dp);
        return x;
    }
};
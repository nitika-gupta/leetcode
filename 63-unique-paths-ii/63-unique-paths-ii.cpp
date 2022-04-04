class Solution {
public:
    int f(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp ){
        if(i==0 && j==0){
            return 1;
            
        } 
        if(i<0 || j<0 || obstacleGrid[i][j]==1){
            return 0;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
       return dp[i][j]= f(i-1,j, obstacleGrid,dp) + f(i,j-1,obstacleGrid,dp);
       //  return  f(i-1,j, obstacleGrid,dp) + f(i,j-1,obstacleGrid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if( obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
            return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1, obstacleGrid, dp);
    }
};
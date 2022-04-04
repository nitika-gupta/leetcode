class Solution {
public:
    int f(int i,int j,vector<vector<int>> & dp){
         if(i==0  && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return (dp[i][j]=f(i-1,j,dp) + f(i,j-1,dp));
        
    }
    int uniquePaths(int m, int n) {
        // if(m-1==0  && n-1==0)
        //     return 1;
        // if(m<0 || n<0)
        //     return 0;
        // return uniquePaths(m-1,n) + uniquePaths(m,n-1);
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return f(m-1,n-1,dp);
        
    }
};
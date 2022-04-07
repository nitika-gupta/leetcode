class Solution {
public:
    int f(int i, int j, vector<vector<int>> & matrix, vector<vector<int>> & dp){
        
        if(i==matrix.size()-1)
            return matrix[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
          int x=INT_MAX-101;
           int y=INT_MAX-101;
         int z=INT_MAX-101;
        if(j!=0)
         x= matrix[i][j] + f(i+1,j-1,matrix,dp);
         y= matrix[i][j] + f(i+1,j, matrix,dp);
       if(j!= matrix.size()-1)
         z= matrix[i][j] + f(i+1,j+1,matrix,dp);
        return dp[i][j]= min(x, min(y,z));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=INT_MAX;
        int  i=0;
        for(int j=0;j<n;j++){
            ans= min(ans,f(i,j,matrix,dp));
            
        }
        return ans;
    }
};
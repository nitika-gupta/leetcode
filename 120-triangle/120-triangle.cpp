class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i==triangle.size()-1)
            return triangle[i][j];
        if(dp[i][j]!= -1)
            return dp[i][j];
        
        int x= triangle[i][j] + f(i+1,j,triangle,dp);
       // if((j+1) <triangle[i+1].size())
          
        int y= triangle[i][j] + f(i+1, j+1, triangle,dp);
        return dp[i][j]= min(x,y);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        int m= triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,triangle,dp);
    }
};
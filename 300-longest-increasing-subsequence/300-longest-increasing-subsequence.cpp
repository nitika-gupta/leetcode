class Solution {
public:
    
    int f(int i,vector<int> &nums, int& ans, int prev, vector<vector<int>>& dp){
        if(i==nums.size()){
            return 0;
        }
        if(prev!=-1)
            if(dp[i][prev]!=-1)
                return dp[i][prev];
        int x=0,y=0;
        
        if(prev ==-1 || nums[prev]<nums[i]){
            x=  1 +f(i+1,nums,ans,i,dp);
        }
        
         y=   f(i+1,nums,ans,prev,dp);
        if(prev!=-1)
            return dp[i][prev]=max(x,y);
        return max(x,y);
        }
    
    int lengthOfLIS(vector<int>& nums) {
        int ans =INT_MIN;
        int n= nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return  f(0,nums,ans,-1,dp);
    }
};
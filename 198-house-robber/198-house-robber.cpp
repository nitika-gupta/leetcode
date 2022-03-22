class Solution {
public:
    // int solve(int n,vector<int>& nums,vector<int>&dp){
    //     if(n==0)
    //         return dp[n]=nums[n];
    //     if(n<0)
    //         return 0;
    //     if(dp[n]!=-1)
    //         return dp[n];
    //     int pick=nums[n]+solve(n-2,nums,dp);
    //     int npick = solve(n-1,nums,dp);
    //     return dp[n]=max(pick,npick);
    // }
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> dp(n,-1);
    //     return solve(n-1,nums,dp);
    // }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        dp[0]=nums[0];
       // dp[1]=nums[1];
        for(int i=1;i<n;i++){
            int take =nums[i];
            if(i>1)
                take+=dp[i-2];
            int ntake=dp[i-1];
            dp[i]=max(take,ntake);
        }
        return dp[n-1];
    }
};
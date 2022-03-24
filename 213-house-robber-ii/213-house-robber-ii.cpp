class Solution {
public:
    int solve(int n,vector<int>& nums,vector<int> & dp){
        if(n==0){
            return dp[n]=nums[n];
            
        }
        if(n<0){
            return 0;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int pick= nums[n];
            if(n>1)
                pick+=solve(n-2,nums,dp);
        int npick= solve(n-1,nums,dp);
        return dp[n]=max(pick,npick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        vector<int> t1;
        vector<int> t2;
        for(int i=1;i<n;i++)
            t1.push_back(nums[i]);
        for(int i=0;i<n-1;i++)
            t2.push_back(nums[i]);
        vector<int> dp(n,-1);
        
        int x=solve(t1.size()-1,t1,dp);
        // vector<int> num1;
        // for(int i=1;i<nums.size();i++)
        //     num1.push_back(nums[i]);
        vector<int> dp1(n,-1);
        int y= solve(t2.size()-1,t2,dp1);
        return max(x,y);
    }
};
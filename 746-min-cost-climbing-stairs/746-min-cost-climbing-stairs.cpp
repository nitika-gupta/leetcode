class Solution {
public:
    
    int solve(vector<int>& cost, int n,vector<int> &dp){
        
        if(n==-1){
            return 0;
        }
        if(n<-1)
            return 1e8;
        if(dp[n]!=-1)
            return dp[n];
        int take = min(cost [n] +  solve(cost,n-1,dp),cost [n] +   solve(cost,n-2,dp));
        // int ntake = solve(cost,n-1);
        // return min(take,ntake);
        return dp[n] = take;
    }
    int minCostClimbingStairs(vector<int>& cost) {

        
        int n= cost.size();
        // int res=INT_MAX;
        // for(int i=n;i>=1;i--){
        //      res = min(res,solve(cost,i-1));
        // }
        // return res;
        vector<int> dp(n,-1);
        return min(solve(cost,n-1,dp), solve(cost,n-2,dp));
    }
};
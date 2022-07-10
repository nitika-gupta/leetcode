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
        return dp[n] = take;
    }
    int minCostClimbingStairs(vector<int>& cost) {

        
        int n= cost.size();
        
        vector<int> dp(n,-1);
        //return min(solve(cost,n-1,dp), solve(cost,n-2,dp));
        
        for(int i=0;i<n;i++){
            if(i<2){
                dp[i]=cost[i];
                continue;
            }
            
            dp[i]= min(cost[i] + dp[i-1], cost[i] + dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};
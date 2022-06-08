class Solution {
public:
    
    int solve(int day,int bought,vector<int>& prices, int fee,vector<vector<int>> &dp){
        if(day==prices.size()){
            return 0;
        }
        if(dp[day][bought]!=-1)
            return dp[day][bought];
        
        if(bought==0){
            int x= -prices[day] + solve(day+1,1,prices,fee,dp);
            int y= solve(day+1,0,prices,fee,dp);
            return dp[day][bought]=max(x,y);
        }
        else{
            int x=prices[day] -fee +solve(day+1,0,prices,fee,dp);
            int y=solve(day+1,1,prices,fee,dp);
            return dp[day][bought]=max(x,y);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
       return solve(0,0,prices,fee,dp);
    }
};
class Solution {
public:
    int mod=1e9 +7;
    int f(int i,int flag,int n,vector<vector<int>> &dp){
        
        if(i>=n)
            return 1;
        if(dp[i][flag]!=-1)
            return dp[i][flag];
        
        if(flag==0){
            return dp[i][flag]=(f(i+1,0,n,dp)%mod + f(i+1,1,n,dp)%mod)%mod;
            
        }
        else{
            return dp[i][flag]=f(i+1,0,n,dp)%mod;
        }
    }
    int countHousePlacements(int n) {
        vector<vector<int>> dp(n,vector<int>(2,-1));
        long long int x= f(0,0,n,dp)%mod;
        return (x*x)%mod;
    }
};
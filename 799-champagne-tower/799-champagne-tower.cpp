class Solution {
public:
double champagneTower(int x, int n, int m) {
        vector<vector<double>>dp(n+1,vector<double>(n+1,0));
        dp[0][0]=(double)x;
        for(int i=0;i<=n-1;i++){
            for(int j=0;j<=i;j++){
                if(dp[i][j]<=1)continue;
                double cur=dp[i][j]-1;
                dp[i+1][j]+=(double)cur/2.0;
                dp[i+1][j+1]+=(double)cur/2.0;
            }
        }
        return (dp[n][m]>=1?1:dp[n][m]);
		}
};
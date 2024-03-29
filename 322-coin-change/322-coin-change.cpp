class Solution {
public:
    //int f(int i, int t, vector<int> & coins, vector<vector<int>> & dp){
//         if(i==0){
//             if(t%coins[0]==0)
//                 return dp[i][t]= t/coins[0];
//         return 1e9;
//         }
        
//         // if(t==0)
//         //     return 1;
//         if(dp[i][t]!=-1)
//             return dp[i][t];
        
//         int pick=1e9;
//         if(coins[i]<=t)
//             pick= 1 +f(i,t-coins[i],coins,dp);
//         int np= f(i-1,t, coins,dp);
//         return dp[i][t] =min(pick,np);
//     }
     int coinChange(vector<int>& coins, int T) {
         
         int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(T+1,0));
        
        
        for(int i=0;i<=T;i++){
            if(i%coins[0]==0) dp[0][i]=(i/coins[0]);
            else dp[0][i]=1e9;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=T;j++){
                int notTake=dp[i-1][j];
                int take=1e9;
                if(coins[i]<=j)
                    take=1+dp[i][j-coins[i]];
                dp[i][j]=min(take, notTake);
            }
        }
         
        if (dp[n-1][T]>=1e9)
            return -1;
         return dp[n-1][T];
         
         
         
         
         
//         if(amount==0)
//             return 0;
//         if(coins.size()==1){
            
//             if(amount%coins[0]==0)
//                 return amount/coins[0] ;
//             else 
//                 return -1;
//             }
//         int n =coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,-1));
//         if(f(coins.size()-1, amount, coins,dp)==1e9)
//             return -1;
//         return f(coins.size()-1, amount, coins,dp);
        
        
//         ------------------------ TABULATION-----------------
        
//         int n= coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1));
        
//         int j=0;
//         for(int i=0;i<n;i++){
//             dp[i][j]=0;
//         }
//         int i=0;
//         for(int j=1;j<amount+1;j++){
//              dp[i][j]=1e9;
//         }
        
//         i=1;
//         for(int j=1;j<amount+1;j++){
//             if(t%coins[i-1]==0)
//                 dp[i][j]
//         }
        
//         for(int i=1;i<n;i++){
//             for(int j=1;j<=amount;j++){
                
//             }
//         }
        
        
        
        
        
        
//         int n=coins.size();
//         vector<vector<int>> dp(n+1, vector<int>(amount+1));
        
//         for(int i=0;i<n+1;i++){
//             for(int j=0;j<amount+1;j++){
//                 if(j==0){
//                     dp[i][j]=0;
//                 }
//                 if(i==0){
//                     dp[i][j]=INT_MAX-1;
//                 }
//             }
//         }
          
//        int i=1;
//             for(int j=1;j<amount+1;j++){
//                 if(j%coins[0]==0)
//                     dp[i][j]=j/coins[0];
//                 else
//                     dp[i][j]=INT_MAX-1;
//             }
        
        
//         for(int j=2;j<n+1;j++){
//             for(int k=1;k<amount+1;k++){
//                 if(coins[j-1]<=k){
//                     dp[j][k] = min(1+ dp[j][k-coins[j-1]], dp[j-1][k]);
//                 }
//                 else{
//                     dp[j][k]=dp[j-1][k];
//                 }
//             }
//         }
//         if(dp[n][amount]==INT_MAX-1)
//             return -1;
        
//         return dp[n][amount];
        
        
    }
};
class Solution {
public:
    int solve(int day,int bought,int price,vector<int>& prices,vector<vector<int>> &dp){
        cout<<day<<" "<<bought<<" "<<price<<endl;
        if(day==prices.size() )
            return 0;
        
        // if(day==prices.size()-1 && bought==0){
        //     return 0;
        // }
       
        if(dp[day][bought]!=-1)
            return dp[day][bought];
        if(bought==0){
            //  int profit=0;
            // //cout<<prices[day]<<" ";
            // if(prices[day]>price){
            //  profit=prices[day]-price;
            // // cout<<"hi";
            // }
            int x=  -prices[day] +solve(day+1,1,prices[day],prices,dp);
            int y=solve(day+1,0,price,prices,dp);
             return dp[day][bought] = max(x,y);
        }
        else{
            
//             int profit=0;
//             cout<<prices[day]<<" ";
//             if(prices[day]>=price){
//              profit=prices[day]-price;
//              cout<<"hi";
//             }
                
               int  x= prices[day] + solve(day+1,0,0,prices,dp);
            int y=solve(day+1,1,price,prices,dp);
             return dp[day][bought] =max(x,y);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
       // vector<int> dp(n,-1);
        return solve(0,0,0,prices,dp);
//         int profit=0;
//         int i=1;
//         while(i<n){
//             if(prices[i-1]<prices[i]){
//                 profit+=(prices[i]-prices[i-1]);
//                 i++;
//             }
//             i++;
            
//         }
//         return profit;
        
    }
};
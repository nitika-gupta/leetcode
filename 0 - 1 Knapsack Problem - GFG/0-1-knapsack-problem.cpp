// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int i,int w, int wt[],int val[],int n,vector<vector<int>> &dp){
        if(i==0){
            if(wt[0]<=w){
                return dp[i][w]=val[0];
            }
            return 0;
        }

        if(w==0){
            return 0;
        }
       // int take=0;
       if(dp[i][w]!=-1)
        return dp[i][w];
        
        if(w<wt[i]){
            return dp[i][w]=solve(i-1,w,wt,val,n,dp);
        }else{
        
          int  take= val[i] + solve(i-1,w-wt[i],wt,val,n,dp);
        int     nt= solve (i-1,w,wt,val,n,dp);
        return dp[i][w]= max(take,nt);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
       return solve(n-1,W,wt,val,n,dp);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
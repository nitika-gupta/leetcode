// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int lp(string a,string b,int n,int m,vector<vector<int>> &dp){
        if(n==0 || m==0)
            return 0;
            
        if(dp[n][m]!=-1)
        return dp[n][m];
        
        if(a[n-1]==b[m-1]){
            return dp[n][m]=1+ lp(a,b,n-1,m-1,dp);
        }
        else{
            return dp[n][m]=max(lp(a,b,n-1,m,dp),lp(a,b,n,m-1,dp));
        }
        
        
    }
    int longestPalinSubseq(string a) {
        //code here
        string b=a;
        reverse(b.begin(),b.end());
        int n=a.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return lp(a,b,n,n,dp);
        
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
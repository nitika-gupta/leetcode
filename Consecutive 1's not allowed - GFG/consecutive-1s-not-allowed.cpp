// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	int m=1e9+7;
	ll count(int n,vector<long long int>& dp){
	    if(n<=1)
	        return 2;
	        
	   if(n==2)
	   return 3;
	   if(dp[n]!=-1)
	        return dp[n];
	   
	   return ((count(n-1,dp))%m +(count(n-2,dp))%m)%m;
	}
	ll countStrings(int n) {
	    
	    // code here
	    if(n<=1)
	        return 2;
	        
	   if(n==2)
	   return 3;
	    vector<long long int> dp(n+1);
	    //return count(n,dp);
	    dp[0]=2;
	    dp[1]=2;
	    dp[2]=3;
	    for(int i=3;i<=n;i++){
	        dp[i]=((dp[i-1])%m+(dp[i-2])%m)%m;
	    }
	    return dp[n];
	    
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    int m=1e9+7;
	    vector<long long int> dp(N+1);
	    dp[0]=2;
	    dp[1]=2;
	    dp[2]=3;
	    
	    for(int i=3;i<=N;i++){
	        dp[i]=((dp[i-1])%m +(dp[i-2])%m)%m;
	        
	    }
	    long long int x=dp[N];
	    x=(x*x)%m;
	    return x;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
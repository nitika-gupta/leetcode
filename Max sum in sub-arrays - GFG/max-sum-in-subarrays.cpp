// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends


class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes here
        long long m1=arr[0];
        long long m2;
        long max=INT_MIN;
        for(int i=1;i<N;i++){
            m2=arr[i];
            if(max<m1+m2)
                max=m1+m2;
            m1=m2;
        }
        return max;
    }
};



// { Driver Code Starts.
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
	    for(ll i=0;i<n;i++)
		    cin>>a[i];
		Solution ob;
	    cout<<ob.pairWithMaxSum(a,n)<<endl;
	}
	return 0;
}

  // } Driver Code Ends
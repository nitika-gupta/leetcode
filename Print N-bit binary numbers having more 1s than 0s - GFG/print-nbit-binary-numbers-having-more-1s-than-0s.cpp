// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
void solve(string s,vector<string> & res,int o,int z,int n){
    if(n==0){
        res.push_back(s);
        return;
    }
    
    if(o==z){
        solve(s+"1",res,o+1,z,n-1);
    }
    else if(o>z){
        solve(s+"1",res,o+1,z,n-1);
        solve(s+"0",res,o,z+1,n-1);
    }
}
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string> res;
	    solve("",res,0,0,N);
	    return res;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends
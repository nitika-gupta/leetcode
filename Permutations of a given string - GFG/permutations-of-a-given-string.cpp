// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void f(int index,int n,vector<string>&ans,string S)
    	{
    	    if(index==n-1)
    	    {
    	        ans.push_back(S);
    	        return;
    	    }
    	    for(int i=index;i<n;i++)
    	    {   if(i!=index && S[i]==S[index])
    	        {
    	            continue;
    	        }
    	        swap(S[i],S[index]);
    	        if(i!=index && S[i]==S[index])
    	        {
    	            continue;
    	        }
    	        f(index+1,n,ans,S);
    	        //swap(S[i],S[index]);
    	        
    	    }
    	}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    int n=S.size();
		    f(0,n,ans,S);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
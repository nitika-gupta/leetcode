// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    unordered_map<char,int> mp;
	    for(int i=0;i<s.length();i++){
	        mp[s[i]]++;
	    }
	    
	    unordered_set<int> v;
	    for(auto it: mp)
	    {
	        v.insert(it.second);
	    }
	    
	    if(v.size()==1)
	        return true;
	   if(v.size()>2)
	        return false;
	        
	        vector<int> res;
	       
	    for(auto it: v){
	        if(it==1)
	            return true;
	       else res.push_back(it);
	       
	       if(abs(res[0]-res[1])==1)
	            return true;
	            
	       
	       
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}


  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	string removeDups(string s) 
	{
	    // Your code goes here
	    vector<int> v(26,0);
	    string res="";
	    for(int i=0;i<s.length();i++){
	        char x=s[i];
	        v[x-'a']++;
	        if(v[x-'a'] >1){
	            continue;
	        }
	        else
	        res+=s[i];
	    }
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
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}  // } Driver Code Ends
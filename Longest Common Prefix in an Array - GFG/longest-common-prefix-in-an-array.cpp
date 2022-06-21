// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        string s=arr[0];
        for(int i=1;i<n;i++){
            string t=arr[i];
            string res="";
            int x=min(s.length(),t.length());
            for(int j=0;j<x;j++){
                if(s[j]!=t[j])
                    break;
                res+=s[j];
            }
            s=res;
            
        }
        if(s=="")
        return "-1";
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
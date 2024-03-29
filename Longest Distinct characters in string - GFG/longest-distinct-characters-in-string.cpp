// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    unordered_map<char,int> mp;
    int n=s.length();
    int i=0,j=0;
    int ans=INT_MIN;
    while(j<n){
        mp[s[j]]++;
        if(mp.size()==(j-i+1)){
            
            ans=max(ans,j-i+1);
            j++;
        }
        else if(mp.size()<(j-i+1)){
           // int x=mp.size();
            while(mp.size()<(j-i+1)){
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                    
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
    }
    return ans;
    
}
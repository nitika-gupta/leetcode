// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            unordered_map<char,int> mp;
            set<char> m1;
            for(int i=0;i<A.length();i++){
                mp[A[i]]++;
            }
            
            for(auto it: B){
                if(mp.find(it)!=mp.end()){
                    
                        m1.insert(it);
                }
            }
            
            
            string s="";
            for(auto it: A){
                if(m1.find(it)==m1.end()){
                    s+=it;
                }
            }
            for(auto it: B){
                if(m1.find(it)==m1.end()){
                    s+=it;
                }
            }
            
            unordered_map<char,int> res;
            for(auto it:s){
                res[it]++;
            }
            string s1="";
            for(auto it: res){
                s1+=it.first;
            }
            
            if(s1.empty())
                return "-1";
                sort(s1.begin(),s1.end());
                
                
            return s1;
            
        }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
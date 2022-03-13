// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    void solve(string in,string op,vector<string>& res,int ind){
        if(ind==in.length()){
            //cout<<op;
            res.push_back(op);
            return;
        }
        if(ind==0){
            op.push_back(in[0]);
            solve(in,op,res,ind+1);
        }
        else{
            string s1=op+" "+in[ind];
            string s2=op+in[ind];
            solve(in,s1,res,ind+1);
            solve(in,s2,res,ind+1);
        }
    }
    vector<string> permutation(string s){
        // Code Here
        
        vector<string> res;
        
        solve(s,"",res,0);
        return res;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends
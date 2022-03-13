class Solution {
public:
    void solve(string in,string op,vector <string > &res,int ind){
        if(ind==in.length()){
         //   cout<<op;
            res.push_back(op);
            return;
        }
        
        if(!isdigit(in[ind])){
            
            char ch= toupper(in[ind]);
            char ch1=tolower(in[ind]);
            solve(in,op+ch1,res,ind+1);
            cout<<"ch"<<ch<<" ";
            solve(in,op+ch,res,ind+1);
        }
        else{
            op+=in[ind];
            solve(in,op,res,ind+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        solve(s,"",res,0);
        return res;
    }
};
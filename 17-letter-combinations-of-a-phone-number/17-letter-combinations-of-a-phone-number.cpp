class Solution {
public:
    void solve(vector<string>& res,string input ,string output,vector<string> &in){
        if(input.length()==0){
            res.push_back(output);
            return;
        }
        
        int x=input[0]-'0';
        for(auto it: in[x]){
            solve(res,input.substr(1,input.length()),output+it,in);
            
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> in(10);
        if(digits.length()==0){
            return res;
        }
        
        in[2]="abc";
        in[3]="def";
        in[4]="ghi";
        in[5]="jkl";
        in[6]="mno";
        in[7]="pqrs";
        in[8]="tuv";
        in[9]="wxyz";
        solve(res,digits,"",in);
        return res;
       
        
        
    }
};
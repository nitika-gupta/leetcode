class Solution {
public:
    void f(int i,vector<int>& c, int t, vector<vector<int>>& res,vector<int>&v,int sum){
        if(sum<0)
            return;
        if(sum==t){
            res.push_back(v);
            return;
        }
        if(i==c.size())
            return;
        
        else{
       
        for(int j=i;j<c.size();j++){
            if(c[i]>t-sum)
                return;
            if(j>i && c[j]==c[j-1])
                continue;
            
            v.push_back(c[j]);
            f(j+1,c,t,res,v,sum+c[j]);
            v.pop_back();
            
        }
        }
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        
        vector<vector<int>> res;
        vector<int>v;
        sort(c.begin(),c.end());
        f(0,c,target,res,v,0);
        return res;
        
        
    }
};
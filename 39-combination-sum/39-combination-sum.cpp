class Solution {
public:
    
    void solve(vector<int>& candidates,int t,int cur,vector<int>& v,vector<vector<int>>& res,int index){
       if(index==candidates.size()){
        if(cur==t)
            res.push_back(v);
        return;
       }
        
        if(cur>t)
            return;
        
        v.push_back(candidates[index]);
        solve(candidates,t,cur+ candidates[index],v,res, index);
        v.pop_back();
        solve(candidates,t,cur,v,res, index+1);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> res;
        
        solve(candidates,target,0,v,res,0);
        return res;
    }
};
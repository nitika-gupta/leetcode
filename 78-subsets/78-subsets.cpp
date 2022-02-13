class Solution {
public:
    
    vector<vector<int>> res;
    
    void solve(vector<int>& nums, vector<int>& op,int index){
        res.push_back(op);
        for(int i=index;i<nums.size();i++){
            op.push_back(nums[i]);
            solve(nums,op,i+1);
            op.pop_back();
        }
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        solve(nums,op,0);
       /* map<vector<int>,int> s;
        for(int i=0;i<res.size();i++){
            if(s.find(res[i])==s.end()){
                s[res[i]]++;
            }
        }
        vector<vector<int>> ans;
        for(auto it:s){
            ans.push_back(it.first);
        }*/
        return res;
    }
};
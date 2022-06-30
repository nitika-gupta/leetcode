class Solution {
public:
    
    void f(vector<int> & nums, int i, vector<int> v,map<vector<int>,int> & mp){
        if(i==nums.size()){
            //sort(v.begin(),v.end());
            mp.insert({v,1});
            return;
        }
        for(auto it: v){
            cout<<it<<" ";
        }
        cout<<endl;
        f(nums,i+1,v,mp);
        v.push_back(nums[i]);
        f(nums, i+1, v, mp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        map<vector<int>,int> mp;
        f(nums,0,v,mp);
        vector<vector<int>> res;
        for(auto it: mp){
            res.push_back(it.first);
        }
        return res;
    }
};
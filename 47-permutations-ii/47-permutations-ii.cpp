class Solution {
public:
    void help(vector<int> & nums, map<vector<int>,int> &mp, vector<int>& freq,vector<int> &v){
        if(v.size()==nums.size()){
            mp.insert({v,1});
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(freq[i]==0){
                freq[i]=1;
                v.push_back(nums[i]);
                help(nums,mp,freq,v);
                freq[i]=0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<vector<int>,int> mp;
        vector<int> v;
        vector<int> freq(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            help(nums,mp,freq,v);
        }
        vector<vector<int>> ans;
        for(auto it: mp){
            ans.push_back(it.first);
        }
        return ans;
    }
};
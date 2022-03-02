class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(auto it: nums1){
            mp[it]++;
        }
        
        for(auto it: nums2){
            if(mp.find(it)!=mp.end()){
                res.push_back(it);
                mp[it]--;
                if(mp[it]==0)
                    mp.erase(it);
            }    
        }
        return res;
    }
};
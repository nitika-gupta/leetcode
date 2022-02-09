class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int i=0;
        int j=1;
        int count=0;
        map<pair<int,int>,int> mp;
       
       
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[j]-nums[i])==k && mp.find({nums[j],nums[i]})==mp.end())
                    mp[{nums[i],nums[j]}]++;
            }
        }
        return mp.size();
        
    }
};
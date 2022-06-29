class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto it: nums){
            mp[it]++;
        }
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-1)==mp.end()){
                int y=nums[i];
                while(mp.find(y)!=mp.end()){
                    y+=1;
                }
                res=max(res,y-nums[i]);
                
            }
        }
        return res;
    }
};
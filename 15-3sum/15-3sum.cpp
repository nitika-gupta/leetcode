class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
         map<vector<int>,int> mp; 
        for(int i=0;i<nums.size()-2;i++){
            
            if(i>0){
                if(nums[i-1]==nums[i])
                    continue;
            }
            int j = i+1;
            int k= nums.size()-1;
            
            while(j<k){
                
                if(nums[i] + nums[j] + nums[k]==0){
                    res.push_back({nums[i],nums[j],nums[k]});
                   // mp[{nums[i],nums[j],nums[k]}]++;
                    
                    while(j+1<k && nums[j] == nums[j+1])j++;
                    while(j<k-1 && nums[k] == nums[k-1])k--;
                    j++;
                    k--;
                }
                else if(nums[i] + nums[j] + nums[k] <0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        // for(auto it: mp){
        //     res.push_back(it.first);
        // }
        return res;
    }
};
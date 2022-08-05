class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
         map<vector<int>,int> mp; 
        for(int i=0;i<nums.size()-2;i++){
          
            int j = i+1;
            int k= nums.size()-1;
            
            while(j<k){
                
                if(nums[i] + nums[j] + nums[k]==0){
                    mp[{nums[i],nums[j],nums[k]}]++;
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
        for(auto it: mp){
            res.push_back(it.first);
        }
        return res;
    }
};
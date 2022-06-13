class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0;
        int i=0;
        int j=0;
        int mx=INT_MIN;
        unordered_map<int,int> mp;
        while(i<nums.size()){
           
            mp[nums[i]]++;
            sum+=nums[i];
           
            if(mp.size()==(i-j+1)){
               
                mx=max(mx,sum);
                i++;
            }
            else if(mp.size()<(i-j+1)){
                while(mp.size()<(i-j+1)){
                    mp[nums[j]]--;
                    sum-=nums[j];
                    if(mp[nums[j]]==0){
                        mp.erase(nums[j]);    
                    }
                    
                                  
                    j++;
                    
                }
                
             i++;    
            }
            
        }
   
        return mx;
        
    }
};
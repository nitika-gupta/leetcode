class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int low1 = 0;
        int high1 = nums[nums.size()-1];
        
        while(low1<=high1){
            int mid1 = low1 + (high1 - low1)/2;
            
            
            int low = 0;
            int high = nums.size()-1;
            
            while(low<=high){
                int mid = low + (high - low)/2;
                
                if(nums[mid]>= mid1){
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
               
            }
            int numbers = nums.size() - low;
            if(numbers == mid1)
                return mid1;
            
            else if(numbers > mid1){
                low1 = mid1 + 1;
            }
            else{
                high1 = mid1 - 1;
            }
            
        }
        return -1;
        
    }
};
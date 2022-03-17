class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k%2==1 && nums.size()==1){
            return -1;
        } 
        if(k==0){
            return nums[0];
        }
        if(k<nums.size()){
            if(k==1){
                return nums[1];
            }
            if(k==2)
            return max(nums[0],nums[2]);
        
          //  return *max_element(nums.begin(),nums.begin()+k+1);
            return(max(*max_element(nums.begin(),nums.begin()+k-1),nums[k]));
        }
        else{
            if(k==nums.size()){
                return(*max_element(nums.begin(),nums.end()-1));
            }
            return *max_element(nums.begin(),nums.end());
        }
    }
};
class Solution {
public:
    int searchInsert(vector<int>& nums, int k) {
             int s=0;
        int N=nums.size();
    int e=N-1;
    while(s<=e){
        int mid=s+ (e-s)/2;
        if(nums[mid]==k){
            return mid;
        }
        if(nums[mid]>k){
            e=mid-1;
            
        }
        else if(nums[mid]<k){
            s=mid+1;
        }
    }
        
    return e+1;
    }
};
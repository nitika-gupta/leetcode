class Solution {
public:
    int dominantIndex(vector<int>& nums) {
                
        int n=nums.size();
        vector<int> arr(nums.size());
        for(int i=0;i<n;i++)
            arr[i]=nums[i];
        sort(arr.begin(),arr.end());
        
        if(n==1){
            return 0;
        }
        int max=arr[n-1];
        
        for(int i=0;i<n;i++){
            if(max!= nums[i] && 2*nums[i]>max){
                return -1;
            }
        }
        int res;
        
        for(int i=0;i<n;i++){
            if(max==nums[i]){
                res=i;
                break;}
        }
        return res;
    }
};
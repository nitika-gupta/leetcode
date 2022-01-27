class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n);
        
        left[0]=nums[0];
        int p=1;
        for(int i=1;i<n;i++){
            left[i]=left[i-1]* nums[i];
        }
       
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                left[i]=left[i-1];
                p*=nums[i];
            }
            else if(i==0){
                left[i]=p;
            }
            else{
                left[i]=p*left[i-1];
                p*=nums[i];
            }
        }
     return left;
    }
};
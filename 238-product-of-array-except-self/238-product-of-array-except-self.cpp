class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            left[i]=left[i-1]* nums[i];
        }
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]*nums[i];
        }
        
        vector<int> op(n);
        for(int i=0;i<n;i++){
            if(i==0){
                op[i]=right[i+1];
                
            }
            else if(i==n-1){
                op[i]=left[i-1];
            }
            else
            op[i]=left[i-1]*right[i+1];
        }
        return op;
    }
};
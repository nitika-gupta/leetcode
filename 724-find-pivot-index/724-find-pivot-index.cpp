class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum= accumulate(nums.begin(),nums.end(),0);
        int ls=0;
        int rs=sum;
        
        for(int i=0;i<nums.size();i++){
           
            rs-=nums[i];
        
        if(ls==rs){
            return i;
        }
        else{
           ls+=nums[i]; 
        }
        
    }
        return -1;
    }
};
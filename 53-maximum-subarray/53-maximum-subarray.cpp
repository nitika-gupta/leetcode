class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>ca(nums.size()+1);
        
        ca[0]=0;
        for(int i=1;i<=nums.size();i++)
        {
            if(ca[i-1]+nums[i-1]<0)
            {
                ca[i]=0;
            }
            else
                ca[i]=ca[i-1]+nums[i-1];
            
            cout<<ca[i];
        }
        
        
        if( *max_element(ca.begin(),ca.end())==0)
        {
            return *max_element(nums.begin(),nums.end());
        }
        else
            return *max_element(ca.begin(),ca.end());
    }
    
};
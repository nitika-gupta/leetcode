class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=i+1;
        vector<int>::iterator it;
        it= nums.begin();
        while(j<nums.size()){
            if(nums[i]==nums[j] && abs(j-i)<2){
                j++;
            }
            else if(nums[i]==nums[j] && abs(j-i)>=2){
              
                nums.erase(nums.begin() +j);
            }
            else if(nums[i]!=nums[j]){
                i=j;
                j++;
            }
        }
        cout<<nums.size();
        return nums.size();
    }
};
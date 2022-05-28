class Solution {
public:
    int missingNumber(vector<int>& nums) {
       set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        
        int j;
        for(j=0;j<=nums.size();j++){
            if(s.find(j)==s.end()){
                break;
            }
        }
        return j;
    
    }
};
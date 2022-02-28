class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
           if(nums.size()==0) return {};
        vector<string> ans;
        int n=nums[0];
        int c=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]+1==nums[i]){
                n=nums[i];
            }
            else{
                if(n==c){
                    ans.push_back(to_string(n));
                }else{
                    ans.push_back(to_string(c)+"->"+to_string(n));
                }
                n=nums[i];
                c=nums[i];
            }
        }
        if(n==c){
            ans.push_back(to_string(n));
        }else{
            ans.push_back(to_string(c)+"->"+to_string(n));
        }
        return ans;
    }
};
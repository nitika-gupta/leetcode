class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int max=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                sum++;
                
            }
            else 
                sum--;
            if(sum==0){
                if(max<i)
                    max=i+1;
            }
            else if(mp.find(sum)==mp.end()){
                 mp[sum]=i;
             }
            else{
                int x= i-mp[sum];
                
                if(max<x)
                    max=x;
            }
             
        }
        return max;
    }
};
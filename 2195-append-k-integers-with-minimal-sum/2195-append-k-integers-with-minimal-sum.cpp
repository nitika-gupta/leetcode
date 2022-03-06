class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long sum=0;
        int prev=0;
        int i=0;
        sort(nums.begin(),nums.end());
        while(k>0 && i<nums.size()){
            int len=nums[i]-prev-1;
            if(len>k)
                len=k;
            if(len>0){
                long long st=prev;
                long long e=st+len;
                
                sum+= (e*(e+1))/2- (st*(st+1))/2;
              
                k=k-len;
                
            }
            prev=nums[i];
                i++;
        }
        if(k>0){
            int st=prev;
            int e=st+k;
            sum+=(e*(e+1))/2- (st*(st+1))/2;
        }
        return sum;
    }
};
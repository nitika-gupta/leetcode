class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> maxa(n,-1);
        maxa[0]=nums[0];
        for(int i=1;i<n;i++){
            maxa[i]=max(maxa[i-1],nums[i]);
        }
        
        vector<int> mina(n,-1);
        mina[n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--){
            mina[i]=min(mina[i+1],nums[i]);
        }
        
        int i=0;
        int j=n-1;
        int flag1=0;
        int flag2=0;
        while(i<j){
            if(mina[i]==maxa[i]){
                i++;
            }
            else 
                flag1=1;
            if(mina[j]==maxa[j]){
                j--;
            }
            else
                flag2=1;
            
            if(flag1 && flag2)
                break;
            
        }
        if(i==j)
            return 0;
        return j-i+1;
    }
};
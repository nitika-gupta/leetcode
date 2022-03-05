class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int inc=0;
        int exc=0;
        int count[10001]={0};
        for(int val :nums){
            count[val]++;
        }
        for(int i=0;i<=10000;i++){
            int ni=exc+ count[i]*i;
            int ne=max(inc,exc);
            inc=ni;
            exc=ne;
        }
        return max(inc,exc);
    }
};
class Solution {
public:
    
//     int solve(int index, int flag , vector<int> & nums,int prev, vector<vector<int>>& dp){
        
//         if(index== nums.size()){
//             return 0;
//         }
//         if(dp[index][flag]!=-1)
//             return dp[index][flag];
//         int x =nums[index]-prev;
//         int flag1=0;
//         if(x<0)
//             flag1=1;
        
//         if(flag1== flag){
//            return dp[index][flag] = solve(index +1, flag,nums, prev,dp);
//         }
//         else {
//            return dp[index][flag]= max( 1+ solve(index+1,flag1, nums,nums[index],dp) ,solve(index +1, flag,nums,prev,dp));
//         }
        
//     }
    
//     int wiggleMaxLength(vector<int>& nums) {
//         if(nums.size()==1)
//             return nums.size();
        
//         int flag=0;
//         if(nums[1]-nums[0] <0){
//             flag=1;
//         }
        
        
//         vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
//         unordered_map<int,int> mp;
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]++;
            
//         }
//         cout<<mp.size();
//         if(mp.size()==1){
//             return 1;
//         }
        
//         return 2 + solve(2,flag,nums,nums[1],dp);
        
        
//     }
    int solve(vector<int> &temp,vector<int> &dp,int ind, int prev,int n)
{
    if(ind>=n)
        return 0;
    if(dp[prev+1]!=-1)
        return dp[prev+1];
    int take=0, nottake=solve(temp,dp,ind+1,prev,n);
    if(prev==-1 || (temp[prev]<0 && temp[ind]>=0) || (temp[prev]>=0 && temp[ind]<=0))
        take=1+solve(temp,dp,ind+1,ind,n);
    return dp[prev+1]=max(take,nottake);
}
int wiggleMaxLength(vector<int>& nums) {
    int n=nums.size();
    if(n<2)
        return n;
    vector<int> temp;
    for(int i=1;i<nums.size();i++)
    {
        int diff=nums[i]-nums[i-1];
        if(diff!=0)
            temp.push_back(diff);
    }
    vector<int> dp(n,-1);
    int size=temp.size();
    return 1+solve(temp,dp,0,-1,size);
}
};
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        if(nums.size()==1 && nums[0]==1)
            return 0;
        vector<int> temp=nums;
        int target=0;
        for(int i=0;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            if(nums[i]==1)
                target++;
        }
        
        if(target==0)
            return 0;
        int i=0;
        int j=0;
        int ans=0;
        int mini=INT_MAX;
        while(j<temp.size()){
            if(temp[j]==0)
                {
                    ans++;
                }
            if(j-i+1<target)
            {
                
                j++;
            }
            else if(j-i+1==target)
            {
                mini=min(mini,ans);
                
                j++;
                if(temp[i]==0)
                {
                    ans--;
                }
                
                i++;
            }
        }
        return mini;
        
//         if(target==0)
//             return 0;
//         int i=0,j=0;
//         int window=INT_MAX;
//         unordered_map<int,int> mp;
//         while(j<temp.size()){
//             mp[temp[j]]++;
//             if(mp[1]<target){
//                 j++;
//             }
//             if(mp[1]==target){
               
//                 window =  min(window, j-i+1);
//                 j++;
//             }
//             else if(mp[1]>target){
                
//                 while(mp[1]>target){
//                     mp[temp[i]]--;
//                     if(mp[temp[i]]==0)
//                         mp.erase(temp[i]);
//                     i++;
//                 }
//                 window = min(window, j-i +1);
//                 if(temp[i]==0){
//                     while(temp[i]==0){
//                         mp[temp[i]]--;
//                         if(mp[temp[i]]==0)
//                              mp.erase(temp[i]);
//                         i++;
                        
//                     }
//                     window = min(window, j-i +1);
//                 }
//                 j++;
                
                
//             }
            
//         }
//         return window-target;
        
        
    }
};
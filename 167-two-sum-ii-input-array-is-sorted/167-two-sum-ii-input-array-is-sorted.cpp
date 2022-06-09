class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        // unordered_map<int,int> mp;
        // vector<int> ans;
        // for(int i=0;i<num.size();i++){
        //     if(mp.find(num[i])==mp.end()){
        //         mp.insert({t-num[i],i});
        //     }
        //     else{
        //          int x=mp[num[i]];
        //         ans.push_back(x+1);
        //         ans.push_back(i+1);
        //         break;
        //     }
        // }
        // return ans;

        int i=0;
        int j=num.size()-1;
        vector<int> ans;
        while(i<j){
             int sum=num[i]+num[j];
            if(sum==t){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;   
            }
            else if(sum<t){
                i++;
            }
            else{
                j--;
            }
            
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<num.size();i++){
            if(mp.find(num[i])==mp.end()){
                mp.insert({t-num[i],i});
            }
            else{
                 int x=mp[num[i]];
                ans.push_back(x+1);
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
    }
};
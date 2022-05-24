class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        vector<int> prev(2,1);
        
        
        ans.push_back({1});
        
            if(n==1)
                return ans;
        if(n==2){
            ans.push_back(prev);
            return ans;
        }
       ans.push_back(prev);
        while(n>2){
             vector<int >cur(prev.size()+1);
            cur[0]=1;
            
            for(int i=1;i<prev.size();i++){
                cur[i]=prev[i-1]+prev[i];
             }
            cur[prev.size()]=1;
            ans.push_back(cur);
            prev=cur;
            n--;
        }
        return ans;
    }
};
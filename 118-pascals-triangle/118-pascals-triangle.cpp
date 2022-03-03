class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        
        vector<vector<int>> res;
        vector<int> prev;
        prev.push_back(1);
        res.push_back(prev);
        if(n==1){
            return res;
            
        }
        
        while(--n){
            vector<int> v;
            v.push_back(prev[0]);
            for(int i=1;i<prev.size();i++){
                v.push_back(prev[i] + prev[i-1]);
            }
            v.push_back(prev[prev.size()-1]);
            res.push_back(v);
            prev=v;
        }
        return res;
    }
};
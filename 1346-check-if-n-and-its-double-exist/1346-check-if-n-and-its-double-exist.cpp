class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<double,int> mp;
        
        for(int i=0;i< arr.size();i++){
            if(mp.find(2*arr[i])!= mp.end())
                return true;
            if(mp.find((double)((double)arr[i]/2.0))!=mp.end())
                return true;
            mp[(double)arr[i]]++;
            
        }
        return false;
    }
};
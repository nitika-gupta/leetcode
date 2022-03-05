class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> mp;
        for(int it=s.length()-1;it>=0;it--){
            mp[s[it]].first++;
            mp[s[it]].second=it;
            
        }
        
       for(auto it: mp){
            cout<<it.first<< " "<< it.second.first<<" "<<it.second.second<<endl;
           if(it.second.first==1){
               return it.second.second;
           }
         }
        return -1;
    }
};
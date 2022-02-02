class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp;
        vector<int> res;
        if(s.length()<p.length())
            return res;
        int ans=0;
        for(int i=0;i<p.length();i++)
            mp[p[i]]++;
        int count=mp.size();
        int k=p.length();
        int i=0;
        int j=0;
        while(j<s.length()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            if(j-i+1<k)
                j++;
            else if(j-i+1==k){
                if(count==0){
                    res.push_back(i);    
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                     count++;
                }
                 i++;
                j++;
            }
           
            
        }
        return res;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int mx=0;
        if(s.size()==1)
            return 1;
        unordered_map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
        if(mpp.size()==s.length()){
            return s.length();
        }
        unordered_map<char,int> mp;
        while(j<s.length()){
            if(mp.find(s[j])==mp.end()){
                mp[s[j]]=j;
                j++;
                
                
            }
            else{
                int x=mp[s[j]];
                mx=max(mx,j-1-i+1);
                for(int k=i;k<=x;k++){
                    mp.erase(s[k]);
                }
                i=x+1;
                mp[s[j]]=j;
                j++;
                
            }
        }
        int y=mp.size();
        return max(mx,y);
    }
};
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.size()!=t.size())
        {
            return false;
        }
        unordered_map<char,int>mp1,mp2;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(mp1.find(s[i])==mp1.end())
            {
                mp1[s[i]]=t[i];
            }
            else
            {
                if(mp1[s[i]]!=t[i])
                {
                    return false;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(mp2.find(t[i])==mp2.end())
            {
                mp2[t[i]]=s[i];
            }
            else
            {
                if(mp2[t[i]]!=s[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
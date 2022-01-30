class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char,int> mp;
        mp.insert({'a',1});mp.insert({'A',1});
        mp.insert({'e',1});mp.insert({'E',1});
        mp.insert({'i',1});mp.insert({'I',1});
        mp.insert({'o',1});mp.insert({'O',1});
        mp.insert({'u',1});mp.insert({'U',1});
        
        
        int i=0,j=s.length()-1;
        
        while(i<j){
        if(mp.find(s[i])!=mp.end() && mp.find(s[j])!=mp.end() ){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        else if(mp.find(s[i])==mp.end())
            i++;
        else
            if(mp.find(s[j])==mp.end())
                j--;
        }
        return s;
    }
};
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
           mp[s[i]]++;
        }
      
 
        for(int i=0;i<t.length();i++){
            mp[t[i]]--;
            }
          char x;
        for(auto it: mp){
            if(it.second==-1){
                x=it.first;
                break;
            }
        }
       
        return x;
    }  
     
};
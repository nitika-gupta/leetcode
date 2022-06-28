class Solution {
public:
    int minDeletions(string s) {
       unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;    
        }
        
        unordered_map<int,int> mpp;
        int count=0;
        for(auto it: mp){
            if(mpp.find(it.second)==mpp.end()){
                mpp[it.second]++;
                
            }
            else{
                int x=it.second;
                
                while(mpp.find(x)!=mpp.end()){
                    x--;
                    count++;
                   
                }
                 
                if(x>0)
                mpp[x]++;
                
            }
        }
        
        return count;
       
    }
    
    
};
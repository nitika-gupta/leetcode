class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp.insert({'I',1});
        mp.insert({'V',5});
        mp.insert({'X',10});
        mp.insert({'L',50});
        mp.insert({'C',100});
        mp.insert({'D',500});
        mp.insert({'M',1000});
    
        
        if(s.length()==1){
            return mp.at(s[0]);
        }
        
        int sum=mp.at(s[s.length()-1]);
        
        for(int i=s.length()-2;i>=0;i--){
            if(mp.at(s[i])<mp.at(s[i+1])){
                sum-=mp.at(s[i]);
            }
            else{
             
                sum+=mp.at(s[i]);
              
            }
        }
        return sum;
    }
};
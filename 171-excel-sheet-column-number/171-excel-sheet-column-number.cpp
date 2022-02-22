class Solution {
public:
    int titleToNumber(string columnTitle) {
        unordered_map<char,int> mp;
        int i=1;
        char c;
        for( c='A';c<='Z';c++){
            mp.insert({c,i});
            i++;
        }
        int res=0;
        int p=0;
        int n=columnTitle.length();
        for(int j=n-1;j>=0;j--){
            int x=mp[columnTitle[j]];
            res= res+ pow(26,p)*x;
            p++;
        }
        
        
        return res;
    }
};
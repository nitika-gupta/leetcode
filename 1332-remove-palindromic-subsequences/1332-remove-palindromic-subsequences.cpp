class Solution {
public:
    
    int removePalindromeSub(string s) {
        if(s.length()==1)
            return 1;
        int i=0;
        int count=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                count=1;
                break;
            }
            i++;
            j--;
        }
        if(count==1)
            return 2;
        return 1;
        
    }
};
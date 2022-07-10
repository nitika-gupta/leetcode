class Solution {
public:
    bool canChange(string s, string t) {
        int i=0,j=0;
        
        int n=s.length();
        while(true){
            while(s[i]=='_'){
                i++;
            }    
            while(t[j] == '_')
            {
                j++;
            }
            
            if(s[i]!=t[j]){
                return false;
            }
            
            if(s[i]=='L'){
                if(i<j)
                    return false;
            }
            else{
                if(j<i)
                    return false;
            }
            
            if(i==n && j== n)
                break;
            i++;
            j++;
        }
        return true;
    }
};
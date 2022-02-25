class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1=0,v2=0;
         int i=0;
        int j=0;
        int cur=0;
        while(i<version1.length() || j<version2.length()){
            
             cur=0;
            while(i<version1.length() && version1[i]!='.'){
                cur= cur*10 +(version1[i]-'0');
                i++;
            }
            v1+=cur;
             cur=0;
            while(j<version2.length() && version2[j]!='.'){
                cur= cur*10 +(version2[j]-'0');
                j++;
            }
            v2+=cur;
            
            if(v1<v2)
                return -1;
            else if(v1>v2)
                return 1;
            
            i++;
            j++;
            
        }
        return 0;
    }
};
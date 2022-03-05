class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[256]={0};
        
        for(int i=0;i<s.length();i++){
            char a=s[i];
            int x=a;
            arr[a]++;
        }
        for(int i=0;i<t.length();i++){
            char a=t[i];
            int x=a;
            arr[x]--;
        }
        for(int i=0;i<256;i++){
            if(arr[i]!=0){
                return false;
            }
        }
        return true;
        
    }
};
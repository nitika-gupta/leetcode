class Solution {
public:
    int countSubstrings(string s) {
        
        bool dp[s.length()][s.length()];
        int count =0;
        for(int g=0;g<s.length();g++){
            for(int i=0,j=g;j<s.length();i++,j++){
                if(g==0){
                    dp[i][j]=true;
                }
                else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
                else
                {
                    if(dp[i+1][j-1]==true && s[i]==s[j]){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
                
                 if(dp[i][j]==true){
                count++;
            }
           
            }
        }
        return count;
    }
};
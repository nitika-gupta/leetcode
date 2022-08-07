class Solution {
public:
    
    
       int solve(int i, string&s,int k,char t,vector<vector<int>> &dp,int prev){
        if(i== s.length())
            return 0;
        
        if(i==0){
            //t+s[i];
            int asci = s[i] - 'a';
            int take =  1 + solve(i+1,s,k, s[i],dp,asci);
            //t.pop_back();
            int ntake = solve(i+1,s,k,t,dp,prev);
            return  max(take,ntake);
        }
        if(prev!=-1)
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        
          int take =0;
        
        if(prev==-1){
            
            //t=t+s[i];
            int asci = s[i] - 'a';
            int take =  1 + solve(i+1,s,k, s[i],dp,asci);
            //t.pop_back();
            int ntake = solve(i+1,s,k,t,dp,prev);
            return max(take,ntake);
        }
       
      
        
        int ascic = s[i]-'a';
        
        if(abs(prev-ascic)<=k){
           // t=t+s[i];
             int asci = s[i] - 'a';
            take = 1+ solve(i+1,s,k,s[i],dp,asci);
           // t.pop_back();
        }
        
        int ntake=solve(i+1,s,k,t,dp,prev);
          if(prev!=-1)
        return dp[i][prev] = max(take,ntake);
          return max(take,ntake);
        
       
    }
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.length(),vector<int>(26,-1));
        
        char t;
        return solve(0,s,k,t,dp,-1);
        
    }
    



};
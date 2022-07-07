class Solution {
public:
    
     bool helper(string& s1, string& s2, string &s3, int l1, int l2, int l3, vector<vector<int>>&dp) {
        if(l1<0 && l2<0 && l3<0) {
            return true;
        }
        if(l1>=0 && l2>=0 && dp[l1][l2]!=-1) {
            return dp[l1][l2];
        }
        if(l1>=0 && s1[l1]==s3[l3] && l2>=0 && s2[l2]==s3[l3] ) {
            return dp[l1][l2] = (helper(s1, s2, s3, l1-1, l2, l3-1, dp) || helper(s1, s2, s3, l1, l2-1, l3-1, dp));
        }
        else if(l1>=0 && s1[l1]==s3[l3])
            return helper(s1, s2, s3, l1-1, l2, l3-1, dp);
        
        else if(l2>=0 &&s2[l2]==s3[l3])
            return helper(s1, s2, s3, l1, l2-1, l3-1, dp);
        
        else return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
			return false;
        vector<vector<int>>dp(s1.size()+1, (vector<int>(s2.size()+1, -1)));
        // memset(dp, -1, sizeof(dp));
        return helper(s1, s2, s3,s1.size()-1, s2.size()-1, s3.size()-1, dp);
    }
    
//     bool solve(string s1, string s2, string s3,int i, int j,int k,vector<vector<vector<int>>>& dp){
        
//         if(i == s1.length() && j == s2.length() && k==s3.size())
//             return true;
        
//         // if(i>=s1.length() || j>=s2.length() || k>=s3.length())
//         //     return false;
//         if(i<=s1.length()-1 && j<=s2.length()-1 && k <=s3.length()-1 && dp[i][j][k]!=-1)
//             return dp[i][j][k];
        
//         //cout<<i<<j<<k<<endl;
//       if(k <=s3.length()-1 && i<=s1.length()-1 && s1[i]==s3[k] &&  j<s2.length() && s2[j]==s3[k] ){
//             return dp[i][j][k] = solve(s1,s2,s3,i+1,j,k+1,dp) || solve(s1,s2,s3,i,j+1,k+1,dp);
//         }
        
//         if(k <=s3.length()-1 && i<=s1.length()-1 && s1[i]==s3[k]){
//             return dp[i][j][k] = solve (s1,s2,s3,i+1,j,k+1,dp);  
//         }
        
//         if(k <=s3.length()-1 && j<=s2.length()-1 &&  s2[j]==s3[k]){
//             return dp[i][j][k] = solve (s1,s2,s3,i,j+1,k+1,dp);   
//         }
        
//        return  false;        
        
//     }
//     bool isInterleave(string s1, string s2, string s3) {
//         vector<vector<vector<int>>> dp(s1.length(),vector<vector<int>>(s2.length(),vector<int>(s3.length(),-1)));
//         return solve(s1,s2,s3,0,0,0,dp);
//     }
    
//       bool solve(string s1, string s2, string s3,int i, int j,int k){
        
//         if(i == s1.length() && j == s2.length() && k==s3.size())
//             return true;
       

//         if(s1[i]==s3[k] && s2[j]==s3[k]){
//             return solve(s1,s2,s3,i+1,j,k+1) || solve(s1,s2,s3,i,j+1,k+1);
//         }
//         if(  s1[i]==s3[k]){
//             return solve (s1,s2,s3,i+1,j,k+1);  
//         }
        
//         if( s2[j]==s3[k]){
//             return solve (s1,s2,s3,i,j+1,k+1);   
//         }
        
//        return  false;        
        
//     }
//     bool isInterleave(string s1, string s2, string s3) {
//         vector<vector<vector<int>>> dp(s1.length(),vector<vector<int>>(s2.length(),vector<int>(s3.length(),-1)));
//         return solve(s1,s2,s3,0,0,0);
//     }
 };
class Solution {
public:
    int f(int ind, vector<string>& strs, int m , int n,vector<vector<vector<int>>>& dp){
        if(ind==strs.size() || (n==0 && m==0))
            return  0;
        if(dp[ind][m][n]!=-1)
            return dp[ind][m][n];
        int nz=0;
        int no=0;
        
        for(int i=0;i<strs[ind].size();i++){
            if(strs[ind][i]=='0')
                nz++;
            else if(strs[ind][i]=='1'){
                no++;
            }
        }
      cout<<nz<<" "<<no<<endl;
        if(nz>m || no>n){
            return dp[ind][m][n]=f(ind+1,strs,m,n,dp);
        }
        int x= 1+f(ind+1,strs, m-nz,n-no,dp);
         int y=f(ind+1,strs,m,n,dp);
       
        return dp[ind][m][n]=max(x,y);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
            //vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
//             return f(0,strs,m,n,dp);
       // int findMaxForm(vector<string>& strs, int m, int n) {
	// dp[i][j] will store Max subset size possible with zeros_limit = i, ones_limit = j
	vector<vector<int> > dp(m + 1, vector<int>(n + 1));
	for(auto& str : strs) {
		// count zeros & ones frequency in current string            
		int zeros = count(begin(str), end(str), '0'), ones = size(str) - zeros; 
		// which positions of dp will be updated ?
		// Only those having atleast `zeros` 0s(i >= zeros) and `ones` 1s(j >= ones)
		for(int i = m; i >= zeros; i--)
			for(int j = n; j >= ones; j--)                    
				dp[i][j] = max(dp[i][j], // either leave the current string
							   dp[i - zeros][j - ones] + 1); // or take it by adding 1 to optimal solution of remaining balance
		// at this point each dp[i][j] will store optimal value for items considered till now & having constraints i and j respectively
	}
	return dp[m][n];

        
    }
};
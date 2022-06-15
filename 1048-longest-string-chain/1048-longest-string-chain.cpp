class Solution {
public:
bool predecessor(string &prev, string &curr) {
		int n = prev.size(), m = curr.size();
        
 
		if (n+1 != m) {
            return false;
        }

        int i=0, j=0;
		while (j < m) {
			if (prev[i] == curr[j]) {
				i++, j++;
			}
			else j++;
		}

		return i==n;
	}
   
    static bool compare (string& first, string& second) {
        return first.size() < second.size();
    }
    
	int longestStrChain(vector<string>& words) {
      
		sort(words.begin(), words.end(), compare);
        
  
		vector<int> dp(words.size(), 1);
		int ans = 1; 
        
	
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (predecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
			}
		
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};
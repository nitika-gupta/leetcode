// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string start, string target, vector<string>& wordList) {
        // Code here
        unordered_map<string,int> mp;
        for(int i=0;i< wordList.size();i++){
            mp[wordList[i]]++;
        }
        //cout<<"hi";
        if(mp.find(target)==mp.end())
        return 0;
        //   if(mp.find(start)==mp.end())
        // return 0;
        
        
        queue<string> q;
        q.push(start);
        int dist=1;
        int ans=0;
        while(!q.empty()){
            int len=q.size();
            dist++;
            for(int i=0;i<len;i++){
                string t=q.front();
                q.pop();
                
                for(int j=0;j<t.length();j++){
                    string temp=t;
                    for(char a='a';a<='z';a++){
                        temp[j]=a;
                        
                        if(mp.find(temp)!=mp.end()){
                            if(temp==target){
                                
                            return dist;
                        }
                        q.push(temp);
                        mp.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
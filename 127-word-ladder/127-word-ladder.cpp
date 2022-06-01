class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        for(int i=0;i<wordList.size();i++){
            mp[wordList[i]]++;
            }
        if(mp.find(endWord)==mp.end())
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int ans =0;
        int dist=1;
        while(!q.empty()){
            dist++;
            cout<<dist<< " "<< ans<<" ";
            int len=q.size();
            for(int x=0;x<len;x++){
            string t=q.front();
            q.pop();
                
            for(int i=0;i<beginWord.length();i++){
                string temp=t;
                for(char a='a';a<='z';a++){
                    temp[i]=a;
                   
                    if(mp.find(temp)!=mp.end()){
                         cout<<temp<<" ";
                        if(temp==endWord){
                            ans=max(ans,dist);
                            return ans;
                        }
                        q.push(temp);
                        mp.erase(temp);
                    }
                }
            }
        }
          //  dist++;
    }
        return ans;
        
    }
};
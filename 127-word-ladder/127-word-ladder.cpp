class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> myset;
        bool isPresent=false;
        for(auto it:wordList){
            if(endWord==it)
                isPresent=true;
            myset.insert(it);
            
        }
        if(isPresent==false)
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int d=0;
        
        while(!q.empty()){
            d++;
            int ls=q.size();
            while(ls--){
                string curr=q.front();
                q.pop();
                
                for(int i=0;i<curr.length();i++){
                    string temp =curr;
                    for(char c='a';c<='z';c++){
                        temp[i]=c;
                        if(curr==temp)
                            continue;
                        if(temp==endWord)
                            return d+1;
                        if(myset.find(temp)!=myset.end()){
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
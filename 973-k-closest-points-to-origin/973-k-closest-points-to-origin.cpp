class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        
        for(auto it: points){
            int x= pow(it[0],2) +pow(it[1],2) ;
            pq.push({x,{it[0],it[1]}});
            if(pq.size()>k)
                pq.pop();
            
        }
        
        vector<vector<int>> res;
        
        while(pq.size()>0){
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            res.push_back(temp);
            pq.pop();
        }
        return res;
    }
};
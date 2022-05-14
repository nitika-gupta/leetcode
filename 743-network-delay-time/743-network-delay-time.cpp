class Solution {
public:
  
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        pq.push({dist[k],k});
        
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                if(it.second+ d <dist[it.first]){
                    dist[it.first]=it.second +d;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        int ans=-1e9;
        for(int i=1;i<n+1;i++){
            ans=max(ans,dist[i]);
        }
        if(ans==1e9)
            return -1;
        return ans;
    }
};
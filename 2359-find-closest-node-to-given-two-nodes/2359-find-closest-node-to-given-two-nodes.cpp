class Solution {
public:
    
    void dijkastra(vector<int> adj[],int s, vector<int> & dist){
        
        dist[s]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({s,0});
        
        while(!pq.empty()){
            int node = pq.top().first;
            int wt = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                if(dist[it]> 1 + wt){
                    dist[it]= 1 + wt;
                    pq.push({it,dist[it]});
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
         int n = edges.size();
        vector<int> adj[n];
        
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1)
            adj[i].push_back(edges[i]);
        }
        vector<int> d1(n,INT_MAX);
        dijkastra(adj, node1,d1);
        vector<int> d2(n,INT_MAX);
        dijkastra(adj,node2,d2);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=n-1;i>=0;i--){
            if(d1[i]!=INT_MAX && d2[i]!=INT_MAX){
                int x = max(d1[i],d2[i]);
                pq.push({x,i});
            }
        }
        if(pq.size()==0)
            return -1;
        return pq.top().second;
    }
};
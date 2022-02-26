#define vi vector<int>
#define vvi vector<vi>
class Solution
{
    public:
    int dp[(1<<12)+1][13][13]; //3D DP 
    int dfs(vvi &e,int mask,int cur,int prev)
    {
        mask = mask | (1<<cur); //mask will store the visited nodes in binary, and we add marked visited current node
        int n=e.size(); //size of the edges
        int ans=(1<<12); //that is your max possible answer initially which stores all the 2^12 possibilities
        if(mask==((1<<n)-1)) return 0; //if we have visited all the nodes, we return //TOP DOWN DP
        if(prev!=INT_MAX and dp[mask][cur][prev]!=-1) //if you have visited, the previous node and also updated dp
            return dp[mask][cur][prev];  //return the stored length of the shortest path
        if(prev!=INT_MAX)//if you have not visited that node, mark it visited by setting changing it from -1 to max
            dp[mask][cur][prev]=ans;  //mark the DP visited
        for(auto x:e[cur]) //for all the neighboring vertices of your current node
            ans=min(ans,1+dfs(e,mask,x,cur)); //updating the length of the shortest path by calling DFS on it
        if(prev!=INT_MAX) dp[mask][cur][prev]=ans; //if the previous node is visited already, then set the dp 
        return ans; //return the answer at the end.
    }

    int shortestPathLength(vvi & graph) //utility to calculate the shortest path in your graph
    { 
        memset(dp,-1,sizeof dp); //setting the DP to -1
        int lenofshortpath=(1<<12); //initialised with maximum i.e. 2^12
        vvi e(graph.size(),vi()); //making the adjacency matrix
        for(int i=0;i<graph.size();i++) 
            for(auto j:graph[i]) //constructing the adjacency matrix
                e[i].push_back(j),e[j].push_back(i); //connecting node i to j and j to i
        for(int i=0;i<graph.size();i++)  //for all the nodes in the graph
            lenofshortpath=min(lenofshortpath,dfs(e,0,i,INT_MAX)); //ans will contain the shortest path
        return lenofshortpath;
    }
};
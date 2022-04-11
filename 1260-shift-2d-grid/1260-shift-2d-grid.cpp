class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        vector<int> v;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               v.push_back(grid[i][j]); 
            }
        }
        for(int i=0;i<k;i++){
            int x=v[v.size()-1];
            v.insert(v.begin(),x);
            v.pop_back();
        }
        
        int k1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=v[k1];
                k1++;
            }
        }
        return grid;
    }
};
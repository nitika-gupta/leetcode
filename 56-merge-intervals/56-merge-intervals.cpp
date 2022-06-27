class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& tiles) {
         vector<vector<int>> ans;
        sort(tiles.begin(),tiles.end());
        ans.push_back(tiles[0]);
        for(int i=1;i<tiles.size();i++){
            if(ans[ans.size()-1][1]>=tiles[i][0]){
                ans[ans.size()-1][1]=max(tiles[i][1],ans[ans.size()-1][1]);
                
            }
            else{
                ans.push_back(tiles[i]);
                
            }
        }
        return ans;
    }
};
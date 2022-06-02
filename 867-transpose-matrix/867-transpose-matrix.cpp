class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
       
        int n=matrix.size();
        int k=matrix[0].size();
         vector<vector<int>> m(k,vector<int>(n,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                m[i][j]=matrix[j][i];
            }
        }
        return m;
    }
};
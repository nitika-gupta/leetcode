class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int res=0;
        if(points.size()==1)
            return 0;
        for(int i=1;i<points.size();i++){
            int x= points[i][0]-points[i-1][0];
            int y=points[i][1]-points[i-1][1];
            res+= max(abs(x),abs(y));
        }
        return res;
        
    }
};
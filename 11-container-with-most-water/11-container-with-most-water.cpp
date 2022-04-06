class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j= height.size()-1;
        int res=INT_MIN;
        while(i<j){
        int m= (j-i) * min(height[i],height[j]);
         res=max(res,m);
        if( height[i]<height[j]){
            i++;
        }
        else{
            j--;
        }
        }
        return res;
        
    }
};
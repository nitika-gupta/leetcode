class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        
        while(k--){
            int x = pq.top();
            pq.pop();
            x = -1*x;
            pq.push(x);
        }
        int sum = 0;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            sum += x;
        }
        return sum;
    }
};
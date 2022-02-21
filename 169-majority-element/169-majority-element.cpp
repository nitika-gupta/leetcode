class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int element=0;
        for(int i:nums){
            if(count==0)
                element=i;
            if(element==i)
                count+=1;
            else
                count-=1;
        }
        return element;
        
        
    }
};
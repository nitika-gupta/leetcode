class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=m-1;
        int j=m;
        int x=0;
        for(int k=m;k<m+n;k++){
            
            nums1[k]=nums2[x];
            x++;
        }
      
        // while(i>=0 && j<(m +n)){
        //     cout<<"f";
        //     if(nums1[i]>nums2[j]){
        //         swap(nums1[i],nums2[j]);
        //         i--;
        //         j++;
        //     }
        //     else{
        //         break;
        //     }
        // }
        sort(nums1.begin(),nums1.end());
        //sort(nums2.begin(),nums2.end());
    }
};
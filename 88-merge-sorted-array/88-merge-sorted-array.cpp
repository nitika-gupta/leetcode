class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        vector<int> temp(nums1.begin(),nums1.end());
        int k=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                temp[k]=nums1[i];
                i++;
                k++;
            }
            else{
                temp[k]=nums2[j];
                j++;
                k++;
                
            }
        }
        
        while(j<n){
            temp[k]=nums2[j];
            j++;
            k++;
        }
        while(i<m){
            temp[k]=nums1[i];
            i++;
            k++;
        }
        
        
        for(int x=0;x<temp.size();x++){
            nums1[x]=temp[x];
        }
    }
};
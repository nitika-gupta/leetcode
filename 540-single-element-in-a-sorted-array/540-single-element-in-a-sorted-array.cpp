class Solution {
public:
//     int search(int l, int h, vector<int> & nums){
//         if(l>h)
//             return -1;
//         if(l==h){
            
//         }
        
//         int mid= l+(h-l)/2;
//         if(mid==0){
//             if(nums[mid+1]!=nums[mid])
//                 return nums[mid];
//         }
//         if(mid==nums.size()-1){
//             if(nums[mid-1]!=nums[mid])
//                 return nums[mid];
//         }
//         int flag1=0,flag2=0;
//         if(mid!=0 ){
//             if(nums[mid-1]!= nums[mid])
//                 flag1=1;
//         }
//         if(mid!=nums.size()-1)
//             if( nums[mid+1]!=nums[mid]){
//                  flag2=1;
//         }
        
        
//         if(flag1 && flag2)
//             return nums[mid];
//         else{
//             int x= search(l,mid-1,nums);
//             int y= search(mid+1,h,nums);
//             if(x!=-1)
//                 return x;
//             else
//                 return y;
//         }
//     }
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size()==1){
            return nums[0];
        }
        // return search(0,nums.size()-1,nums);
           int l=0;
	    int h=nums.size()-1;
	    
	    while(l<=h){
	        int mid= l+ (h-l)/2;
	        
	        if((mid%2==0 && nums[mid+1]!=nums[mid]) || (mid%2==1 && nums[mid-1]!=nums[mid]) ){
	           
	             h=mid-1;
	        }
	        
	        else{
	            l=mid+1;
	        }
	    }
	    return nums[l];
    }
};
class Solution {
public:
    int binarySearch(vector<int> arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
  
    // We reach here when element is not
    // present in array
    return -1;
}
  
    
    int search(vector<int>& nums, int target) {
        int n =nums.size();
	    int s=0;
	    int e=n-1;
	    while(s<e){
	        int mid =s+ (e-s)/2;
	        if(nums[mid]<nums[e])
	            e=mid;
	        else
	            s=mid+1;
	    }
      
	    int x=s;
        int a=binarySearch(nums,0,s-1,target);
        int b=binarySearch(nums,s,n-1,target);
        if(a ==-1 && b==-1)
            return -1;
        else if(a==-1)
            return b;
        return a;
    }
};
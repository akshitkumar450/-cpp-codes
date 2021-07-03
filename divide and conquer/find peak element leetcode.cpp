class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
       return find(nums,start,end);
    }
    
    int find(vector<int>& nums,int start,int end){
        // base case
        // no need to write this is question always has a peak element 
        // if we always have a peak element then base case will never be hit
        if(start>end){
            return -1;
        }
        
        int n=nums.size();
        int mid=(start+end)/2;
        // for peak element it should be greater than it left and right element
        // /nums[-1] = nums[n] = -∞
        //if we are at mid==0 then dont check for left elements
        //if we are at mid==n-1 then dont check for right elements
        if((mid==0 or nums[mid]>nums[mid-1]) and (mid==n-1 or nums[mid]>nums[mid+1])){
            return mid;
        }
        // move to the side which has greater element
        if(nums[mid]<nums[mid+1]){
            return find(nums,mid+1,end);
        } else{
            return find(nums,start,mid-1);
        }
    }
};
class Solution{
    public:
  
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        // fix i and j
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // left at j+1
                int left=j+1;
                // right at n-1
                int right=n-1;
                // find value at target-(i+j) 
                // such as we find pair in sorted array with 2 pointers
                int target2=target-(nums[i]+nums[j]);
                
                while(left<right){
                    if(nums[left]+nums[right]==target2){
                        // if we found 
                        // create a vector for storing that
                        vector<int>quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[left];
                        quad[3]=nums[right];
                        // push that in result vector
                        res.push_back(quad);
                        
                        // move left till there are duplicate elements as of which we have found quad
                        while(left <right and nums[left]==quad[2]){
                            left++;
                        }
                        // move right till there are duplicated as of which we have found quad
                        
                        while(left <right and nums[right]==quad[3]){
                            right--;
                        }
                        // if sum is less
                    } else if(nums[left]+nums[right]<target2){
                        left++;
                    } else {
                        // if sum is greater
                        right--;
                    }
                }
                // move j till there are duplcate elements
                // we are moving if there are duplicates bcz there is no point to check for that
                // as we want only unique quads
                while(j+1<n and nums[j+1]==nums[j]){
                    j++;
                }
            }
            // move i till there are duplicates
            while(i<n and nums[i+1]==nums[i]) {
                i++;
            }
        }
        return res;
        
    }
};
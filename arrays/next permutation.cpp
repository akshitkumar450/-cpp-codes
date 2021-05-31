    void nextPermutation(vector<int>& nums) {
            int i,j;
        int n=nums.size();
    for(int i=n-2;i>=0;i--) {
        if(nums[i]<nums[i+1]) {
            break;
        }
    }
    if(i<0) {
     reverse(nums.begin(),nums.end());
    } 
    else {
        for(int j=n-1;j>i;j--) {
            if(nums[j]>nums[i]) {
                break;
            }
        }
         swap(nums[i],nums[j]);
     reverse(nums.begin()+i+1,nums.end());         
    }
    }

       void nextPermutation(vector<int> &num) {
            int len = num.size();
            int i,j;
            for(i = len - 2; i >= 0 ; i--)
                if(num[i] < num[i+1])  // i is the index of the smaller value;
                break;

            // array is in decreasing order above condition will not happen then we will reverse the array

            if (i == -1) {
                reverse(num.begin(), num.end());
                return;
            }

            for(j = len - 1; j > i; j--)
                if(num[j] > num[i])  // j is the index of the value which is greater than i
                break;

            swap(num[i], num[j]);
            reverse(num.begin() + i + 1, num.end());
            return;
        }
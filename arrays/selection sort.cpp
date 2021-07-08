class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minindex=0;

        while(minindex<nums.size()-1){

            int minVal=nums[minindex];
            int replaceIndex=minindex;
            // find the minimum value  after the current value
            for(int i=minindex+1;i<nums.size();i++){
                if(nums[i]<minVal){
                    minVal=nums[i];
                    replaceIndex=i;
                }
            }
            swap(nums[minindex],nums[replaceIndex]);
            minindex++;
        }
        return nums;
    }
};
class Solution {
public:
    vector<int> sortArray(vector<int>& arr) {
        int n=arr.size();
        // divider is point from where left part is sorted and we are finding the element from right and place it in left part
        // start from index 1 
        // bcz 0 index (single element is sorted)
        int divider=1;
        while(divider<n){
            // move till i=1
            // find the element position from right part and place in left part
            // don't check for i>=0 bcz at i=0 we cant check fro i-1 index 
            for(int i=divider;i>0;i--){
                if(arr[i]<arr[i-1]){
                    swap(arr[i],arr[i-1]);
                } else {
                    break;
                }
            }
            // move to next element
            divider++;
          }
        return arr;
    }
};
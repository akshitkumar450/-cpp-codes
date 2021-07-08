// second approach
int maxSubarraySum(int arr[], int n){
    int minSum=arr[0];
    int curSum=arr[0];
    for(int i=1;i<n;i++){
        // we have two options only 
        // whether to include the new number to previous sum
        int continueWithArray=curSum+arr[i];
        // or not to include it and start it as a new 
        int newArray=arr[i];
        // cursum will max of both
        curSum=min(continueWithArray,newArray);
        // if(curSum<minSum){
        //     minSum=curSum;
        // }
        minSum=min(curSum,minSum)
    }
    return minSum;
}
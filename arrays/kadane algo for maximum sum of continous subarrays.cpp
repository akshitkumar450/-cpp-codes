#include <iostream>
using namespace std;

void maxSumSubarray(int arr[],int n) {
    int curSum=0;
    int maxSum=0;
    // kadane algo
    for(int i=0;i<n;i++) {
        curSum=curSum+arr[i];
        if(curSum<0) {
            curSum=0;
        }
        maxSum=max(curSum,maxSum);
    }

    cout<<"maximum sum "<<maxSum;
}

// second approach
int maxSubarraySum(int arr[], int n){
    int maxSum=arr[0];
    int curSum=arr[0];
    for(int i=1;i<n;i++){
        // we have two options only 
        // whether to include the new number to previous sum
        int continueWithArray=curSum+arr[i];
        // or not to include it and start it as a new 
        int newArray=arr[i];
        // cursum will max of both
        curSum=max(continueWithArray,newArray);
        if(curSum>maxSum){
            maxSum=curSum;
        }
    }
    return maxSum;
        
}

int main() {
         int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    };
    maxSumSubarray(arr,n);
}
